#include <iostream>

#include "Listener.h"
#include "Session.h"

Listener::Listener(boost::asio::io_context& ioc, boost::asio::ip::tcp::endpoint endpoint) : _acceptor(ioc), _socket(ioc)
{
	boost::beast::error_code ec;

	_acceptor.open(endpoint.protocol(), ec);

	if (ec)
	{
		std::cerr << "open" << ": " << ec.message() << "\n";
		return;
	}

	_acceptor.set_option(boost::asio::socket_base::reuse_address(true), ec);
	if (ec)
	{
		std::cerr << "set_option" << ": " << ec.message() << "\n";
		return;
	}

	_acceptor.bind(endpoint, ec);
	if (ec)
	{
		std::cerr << "bind" << ": " << ec.message() << "\n";

		return;
	}

	_acceptor.listen(boost::asio::socket_base::max_listen_connections, ec);

	if (ec)
	{
		std::cerr << "listen" << ": " << ec.message() << "\n";

		return;
	}
}

void Listener::run()
{
	if (!_acceptor.is_open())
	{
		return;
	}

	do_accept();
}

void Listener::do_accept()
{
	_acceptor.async_accept(
		_socket,
		std::bind(
			&Listener::on_accept,
			shared_from_this(),
			std::placeholders::_1));
}

void Listener::on_accept(boost::beast::error_code ec)
{
	if (ec)
	{
		std::cerr << "accept" << ": " << ec.message() << "\n";
	}
	else
	{
		std::make_shared<Session>(std::move(_socket))->run();
	}

	do_accept();
}