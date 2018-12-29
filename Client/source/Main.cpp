#include <iostream>
#include <memory>

#include "Session.h"

int main(int argc, char** argv)
{
	const auto host = "192.168.0.101";
	const auto port = "2751";
	const auto text = "handshake";

	// The io_context is required for all I/O
	boost::asio::io_context ioContext;

	// Launch the asynchronous operation
	std::make_shared<Session>(ioContext)->run(host, port, text);

	// Run the I/O service. The call will return when
	// the socket is closed.
	ioContext.run();

	return EXIT_SUCCESS;
}