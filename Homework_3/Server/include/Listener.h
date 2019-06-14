#pragma once

#include <memory>

#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/core.hpp>

class Listener : public std::enable_shared_from_this<Listener>
{
private:
	boost::asio::ip::tcp::acceptor acceptor;
	boost::asio::ip::tcp::socket socket;

public:
	Listener(boost::asio::io_context& ioContext, boost::asio::ip::tcp::endpoint endpoint);

	void run();
	void do_accept();
	void on_accept(boost::beast::error_code errorCode);
};