#include <memory>

#include <boost/beast/core.hpp>
#include <boost/beast/websocket/stream.hpp>
#include <boost/asio/strand.hpp>
#include <boost/asio/bind_executor.hpp>

#include "Session.h"

Session::Session(boost::asio::ip::tcp::socket socket) : _ws(std::move(socket)), _strand(_ws.get_executor())
{ 

}

void Session::run()
{
	_ws.async_accept(
		boost::asio::bind_executor(
			_strand,
			std::bind(
				&Session::on_accept,
				shared_from_this(),
				std::placeholders::_1)));
}

void Session::on_accept(boost::beast::error_code ec)
{
	if (ec)
	{
		std::cerr << "accept" << ": " << ec.message() << "\n";
	}

	do_read();
}

void Session::do_read()
{
	_ws.async_read(
		_buffer,
		boost::asio::bind_executor(
			_strand,
			std::bind(
				&Session::on_read,
				shared_from_this(),
				std::placeholders::_1,
				std::placeholders::_2)));
}

void Session::on_read(boost::beast::error_code ec, std::size_t bytes_transferred)
{
	boost::ignore_unused(bytes_transferred);

	if (ec == boost::beast::websocket::error::closed)
	{
		return;
	}

	if (ec)
	{
		std::cerr << "read" << ": " << ec.message() << "\n";
	}

	_ws.text(_ws.got_text());
	_ws.async_write(
		_buffer.data(),
		boost::asio::bind_executor(
			_strand,
			std::bind(
				&Session::on_write,
				shared_from_this(),
				std::placeholders::_1,
				std::placeholders::_2)));
}

void Session::on_write(boost::beast::error_code ec, std::size_t bytes_transferred)
{
	boost::ignore_unused(bytes_transferred);

	if (ec)
	{
		std::cerr << "write" << ": " << ec.message() << "\n";
	}

	std::cout << boost::beast::buffers(_buffer.data());

	_buffer.consume(_buffer.size());

	do_read();
}

