#pragma once

#include <memory>

#include <boost/beast/websocket.hpp>
#include <boost/asio/strand.hpp>

#include "ResponseFactory.h"

class Session : public std::enable_shared_from_this<Session>
{
private:
	boost::beast::websocket::stream<boost::asio::ip::tcp::socket> webSocket;
	boost::asio::strand<boost::asio::io_context::executor_type> strand;
	boost::beast::multi_buffer buffer;
	std::string response;
	ResponseFactory responseFactory;

public:
	explicit Session(boost::asio::ip::tcp::socket socket);

	void run();

	void on_accept(boost::beast::error_code errorCode);
	void on_read(boost::beast::error_code errorCode, std::size_t bytesTransferred);
	void on_write(boost::beast::error_code errorCode, std::size_t bytesTransferred);

	void do_read();
};
