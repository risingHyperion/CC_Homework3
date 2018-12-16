#include <memory>

#include <boost/beast/websocket.hpp>
#include <boost/asio/strand.hpp>

class Session : public std::enable_shared_from_this<Session>
{
private:
	boost::beast::websocket::stream<boost::asio::ip::tcp::socket> _ws;
	boost::asio::strand<boost::asio::io_context::executor_type> _strand;
	boost::beast::multi_buffer _buffer;

public:
	explicit Session(boost::asio::ip::tcp::socket socket);

	void run();

	void on_accept(boost::beast::error_code ec);
	void on_read(boost::beast::error_code ec, std::size_t bytes_transferred);
	void on_write(boost::beast::error_code ec, std::size_t bytes_transferred);

	void do_read();
};
