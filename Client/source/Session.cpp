#pragma once

#include <memory>

#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>

#include "Session.h"


Session::Session(boost::asio::io_context& ioc) : resolver_(ioc), ws_(ioc)
{

}

// Start the asynchronous operation
void Session::Session::run(char const* host, char const* port, char const* text)
{
	// Save these for later
	host_ = host;
	text_ = text;

	// Look up the domain name
	resolver_.async_resolve(
		host,
		port,
		std::bind(
			&Session::on_resolve,
			shared_from_this(),
			std::placeholders::_1,
			std::placeholders::_2));
}

void Session::on_resolve(boost::beast::error_code ec, boost::asio::ip::tcp::resolver::results_type results)
{
	if (ec)
	{
		std::cerr << "resolve" << ": " << ec.message() << "\n";
	}

	// Make the connection on the IP address we get from a lookup
	boost::asio::async_connect(
		ws_.next_layer(),
		results.begin(),
		results.end(),
		std::bind(
			&Session::on_connect,
			shared_from_this(),
			std::placeholders::_1));
}

void Session::on_connect(boost::beast::error_code ec)
{
	if (ec)
	{
		std::cerr << "connect" << ": " << ec.message() << "\n";
	}

	// Perform the boost::boost::beast::websocket handshake
	ws_.async_handshake(host_, "/",
		std::bind(
			&Session::on_handshake,
			shared_from_this(),
			std::placeholders::_1));
}

void Session::on_handshake(boost::beast::error_code ec)
{
	if (ec)
	{
		std::cerr << "handshake" << ": " << ec.message() << "\n";
	}

	// Send the message
	ws_.async_write(
		boost::asio::buffer(text_),
		std::bind(
			&Session::on_write,
			shared_from_this(),
			std::placeholders::_1,
			std::placeholders::_2));
}

void Session::on_write(boost::beast::error_code ec, std::size_t bytes_transferred)
{
	boost::ignore_unused(bytes_transferred);

	if (ec)
	{
		std::cerr << "write" << ": " << ec.message() << "\n";
	}

	// Read a message into our buffer
	ws_.async_read(
		buffer_,
		std::bind(
			&Session::on_read,
			shared_from_this(),
			std::placeholders::_1,
			std::placeholders::_2));
}

void Session::on_read(boost::beast::error_code ec, std::size_t bytes_transferred)
{
	boost::ignore_unused(bytes_transferred);

	if (ec)
	{
		std::cerr << "read" << ": " << ec.message() << "\n";
	}

	// Close the boost::boost::beast::websocket connection
	ws_.async_close(boost::beast::websocket::close_code::normal,
		std::bind(
			&Session::on_close,
			shared_from_this(),
			std::placeholders::_1));
}

void Session::on_close(boost::beast::error_code ec)
{
	if (ec)
	{
		std::cerr << "close" << ": " << ec.message() << "\n";
	}

	// If we get here then the connection is closed gracefully

	// The make_printable() function helps print a ConstBufferSequence
	std::cout << boost::beast::buffers(buffer_.data()) << std::endl;
}
