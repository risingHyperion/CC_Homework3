#include <memory>

#include <boost/beast/core.hpp>
#include <boost/beast/websocket/stream.hpp>
#include <boost/asio/strand.hpp>
#include <boost/asio/bind_executor.hpp>

#include "Session.h"

Session::Session(boost::asio::ip::tcp::socket socket) : webSocket(std::move(socket)), strand(webSocket.get_executor())
{ 

}

void Session::run()
{
	this->webSocket.async_accept(
		boost::asio::bind_executor(
			this->strand,
			std::bind(
				&Session::on_accept,
				shared_from_this(),
				std::placeholders::_1)));
}

void Session::on_accept(boost::beast::error_code errorCode)
{
	if (errorCode)
	{
		std::cerr << "accept" << ": " << errorCode.message() << "\n";
	}

	do_read();
}

void Session::do_read()
{
	this->webSocket.async_read(
		this->buffer,
		boost::asio::bind_executor(
			this->strand,
			std::bind(
				&Session::on_read,
				shared_from_this(),
				std::placeholders::_1,
				std::placeholders::_2)));
}

void Session::on_read(boost::beast::error_code errorCode, std::size_t bytes_transferred)
{
	boost::ignore_unused(bytes_transferred);

	if (errorCode == boost::beast::websocket::error::closed)
	{
		return;
	}

	if (errorCode)
	{
		std::cerr << "read" << ": " << errorCode.message() << "\n";
	}

	this->response = this->responseFactory.generateResponse(
		boost::beast::buffers_to_string(
			this->buffer.data()));
	auto responseAsBuffer = boost::asio::buffer(response);

	this->webSocket.text(this->webSocket.got_text());
	this->webSocket.async_write(
		responseAsBuffer,
		boost::asio::bind_executor(
			this->strand,
			std::bind(
				&Session::on_write,
				shared_from_this(),
				std::placeholders::_1,
				std::placeholders::_2)));
}

void Session::on_write(boost::beast::error_code errorCode, std::size_t bytes_transferred)
{
	boost::ignore_unused(bytes_transferred);

	if (errorCode)
	{
		std::cerr << "write" << ": " << errorCode.message() << "\n";
	}

	std::cout << boost::beast::buffers(this->buffer.data());

	this->buffer.consume(this->buffer.size());

	do_read();
}

