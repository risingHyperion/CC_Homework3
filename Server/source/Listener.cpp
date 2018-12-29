#include <iostream>

#include "Listener.h"
#include "Session.h"

Listener::Listener(boost::asio::io_context& ioContext, boost::asio::ip::tcp::endpoint endpoint) : acceptor(ioContext), socket(ioContext)
{
	boost::beast::error_code errorCode;

	this->acceptor.open(endpoint.protocol(), errorCode);

	if (errorCode)
	{
		std::cerr << "open" << ": " << errorCode.message() << "\n";
		return;
	}

	this->acceptor.set_option(boost::asio::socket_base::reuse_address(true), errorCode);
	if (errorCode)
	{
		std::cerr << "set_option" << ": " << errorCode.message() << "\n";
		return;
	}

	this->acceptor.bind(endpoint, errorCode);
	if (errorCode)
	{
		std::cerr << "bind" << ": " << errorCode.message() << "\n";

		return;
	}

	this->acceptor.listen(boost::asio::socket_base::max_listen_connections, errorCode);

	if (errorCode)
	{
		std::cerr << "listen" << ": " << errorCode.message() << "\n";

		return;
	}
}

void Listener::run()
{
	if (!this->acceptor.is_open())
	{
		return;
	}

	do_accept();
}

void Listener::do_accept()
{
	this->acceptor.async_accept(
		this->socket,
		std::bind(
			&Listener::on_accept,
			shared_from_this(),
			std::placeholders::_1));
}

void Listener::on_accept(boost::beast::error_code errorCode)
{
	if (errorCode)
	{
		std::cerr << "accept" << ": " << errorCode.message() << "\n";
	}
	else
	{
		std::make_shared<Session>(std::move(this->socket))->run();
	}

	do_accept();
}