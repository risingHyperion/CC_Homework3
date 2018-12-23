#include <iostream>
#include <memory>

#include "Session.h"

int main(int argc, char** argv)
{
	auto const host = "192.168.0.101";
	auto const port = "2751";
	auto const text = "handshake";

	// The io_context is required for all I/O
	boost::asio::io_context ioc;

	// Launch the asynchronous operation
	std::make_shared<Session>(ioc)->run(host, port, text);

	// Run the I/O service. The call will return when
	// the socket is closed.
	ioc.run();

	return EXIT_SUCCESS;
}