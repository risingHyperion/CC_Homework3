#include <memory>

#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/core.hpp>

class Listener : public std::enable_shared_from_this<Listener>
{
private:
	boost::asio::ip::tcp::acceptor _acceptor;
	boost::asio::ip::tcp::socket _socket;

public:
	Listener(boost::asio::io_context& ioc, boost::asio::ip::tcp::endpoint endpoint);

	void run();
	void do_accept();
	void on_accept(boost::beast::error_code ec);
};