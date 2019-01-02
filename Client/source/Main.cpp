#include <iostream>
#include <memory>

#include "Session.h"

int main(int argc, char** argv)
{
	const auto host = "192.168.0.101";
	const auto port = "2751";

	// The io_context is required for all I/O
	boost::asio::io_context ioContext;

	RequestsManager requestsManager;

	auto handshake = requestsManager.getMap().at("Handshake")->getContentAsString();
	auto sum = requestsManager.getMap().at("Sum")->getContentAsString();

	// Launch the asynchronous operation
	std::make_shared<Session>(ioContext)->run(host, port, handshake);
	std::make_shared<Session>(ioContext)->run(host, port, sum);

	// Run the I/O service. The call will return when
	// the socket is closed.
	ioContext.run();

	return EXIT_SUCCESS;
}