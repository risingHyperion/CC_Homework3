#pragma once

#include <memory>

#include <boost/beast/websocket.hpp>
#include <boost/asio/strand.hpp>
#include "RequestsManager.h"

class Session : public std::enable_shared_from_this<Session>
{
private:
	boost::asio::ip::tcp::resolver resolver;
	boost::beast::websocket::stream<boost::asio::ip::tcp::socket> webSocket;
	boost::beast::multi_buffer buffer;
	std::string host;
	std::string message;

public:
	explicit Session(boost::asio::io_context& ioc);

	void run(char const* host, char const* port, const std::string& message);

	void on_resolve(boost::beast::error_code errorCode, boost::asio::ip::tcp::resolver::results_type results);
	void on_connect(boost::beast::error_code errorCode);
	void on_handshake(boost::beast::error_code errorCode);
	void on_write(boost::beast::error_code errorCode, std::size_t bytes_transferred);
	void on_read(boost::beast::error_code errorCode, std::size_t bytes_transferred);
	void write_response_to_file();

	void on_close(boost::beast::error_code errorCode);
};
