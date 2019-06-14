#pragma once

#include <memory>

#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/asio/buffer.hpp>

#include "Session.h"


Session::Session(boost::asio::io_context& ioContext) : resolver(ioContext), webSocket(ioContext)
{

}

// Start the asynchronous operation
void Session::Session::run(char const* host, char const* port, const std::string& message)
{
	// Save these for later
	this->host = host;
	this->message = message;

	// Look up the domain name
	this->resolver.async_resolve(
		this->host,
		port,
		std::bind(
			&Session::on_resolve,
			shared_from_this(),
			std::placeholders::_1,
			std::placeholders::_2));
}

void Session::on_resolve(boost::beast::error_code errorCode, boost::asio::ip::tcp::resolver::results_type results)
{
	if (errorCode)
	{
		std::cerr << "resolve" << ": " << errorCode.message() << "\n";
	}

	// Make the connection on the IP address we get from a lookup
	boost::asio::async_connect(
		this->webSocket.next_layer(),
		results.begin(),
		results.end(),
		std::bind(
			&Session::on_connect,
			shared_from_this(),
			std::placeholders::_1));
}

void Session::on_connect(boost::beast::error_code errorCode)
{
	if (errorCode)
	{
		std::cerr << "connect" << ": " << errorCode.message() << "\n";
	}

	// Perform the boost::boost::beast::websocket handshake
	this->webSocket.async_handshake(this->host, "/",
		std::bind(
			&Session::on_handshake,
			shared_from_this(),
			std::placeholders::_1));
}

void Session::on_handshake(boost::beast::error_code errorCode)
{
	if (errorCode)
	{
		std::cerr << "handshake" << ": " << errorCode.message() << "\n";
	}

	auto requestAsBuffer = boost::asio::buffer(this->message);

	// Send the message
	this->webSocket.async_write(
		requestAsBuffer,
		std::bind(
			&Session::on_write,
			shared_from_this(),
			std::placeholders::_1,
			std::placeholders::_2));
}

void Session::on_write(boost::beast::error_code errorCode, std::size_t bytes_transferred)
{
	boost::ignore_unused(bytes_transferred);

	if (errorCode)
	{
		std::cerr << "write" << ": " << errorCode.message() << "\n";
	}

	// Read a message into our buffer
	this->webSocket.async_read(
		this->buffer,
		std::bind(
			&Session::on_read,
			shared_from_this(),
			std::placeholders::_1,
			std::placeholders::_2));
}

void Session::on_read(boost::beast::error_code errorCode, std::size_t bytes_transferred)
{
	boost::ignore_unused(bytes_transferred);

	if (errorCode)
	{
		std::cerr << "read" << ": " << errorCode.message() << "\n";
	}

	write_response_to_file();

	// Close the boost::boost::beast::websocket connection
	this->webSocket.async_close(boost::beast::websocket::close_code::normal,
		std::bind(
			&Session::on_close,
			shared_from_this(),
			std::placeholders::_1));
}

void Session::write_response_to_file()
{
	boost::property_tree::ptree result;
	std::stringstream ss;

	ss << boost::beast::buffers(this->buffer.data());

	boost::property_tree::read_json(ss, result);

	boost::filesystem::path path(result.get<std::string>("File"));
	boost::filesystem::ofstream ofs(path);
	ofs << boost::beast::buffers(this->buffer.data());
}

void Session::on_close(boost::beast::error_code errorCode)
{
	if (errorCode)
	{
		std::cerr << "close" << ": " << errorCode.message() << "\n";
	}

	// If we get here then the connection is closed gracefully

	// The make_printable() function helps print a ConstBufferSequence
	std::cout << boost::beast::buffers(this->buffer.data()) << std::endl;
}
