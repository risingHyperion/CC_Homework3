#include <iostream>
#include <thread>

#include "Listener.h"

int main()
{
	const auto address = boost::asio::ip::make_address("127.0.0.1");
	const unsigned short port = 8888;
	const auto threadsCount = 10;

	// The io_context is required for all I/O
	boost::asio::io_context ioContext{ threadsCount };

	// Create and launch a listening port
	std::make_shared<Listener>(ioContext, boost::asio::ip::tcp::endpoint{ address, port })->run();

	// Run the I/O service on the requested number of threads
	std::vector<std::thread> threads;

	threads.reserve(threadsCount - 1);
	for (auto index = 0; index < threadsCount - 1; ++index)
	{
		threads.emplace_back([&ioContext] { ioContext.run(); });
	}

	ioContext.run();

	return EXIT_SUCCESS;
}