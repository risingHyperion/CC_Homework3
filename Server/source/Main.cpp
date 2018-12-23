#include <iostream>
#include <thread>

#include "Listener.h"

int main()
{
	const auto address = boost::asio::ip::make_address("192.168.0.101");
	const unsigned short port = 2751;
	const auto threads = std::max<int>(1, 10);

	// The io_context is required for all I/O
	boost::asio::io_context ioc{ threads };

	// Create and launch a listening port
	std::make_shared<Listener>(ioc, boost::asio::ip::tcp::endpoint{ address, port })->run();

	// Run the I/O service on the requested number of threads
	std::vector<std::thread> v;
	v.reserve(threads - 1);
	for (auto i = threads - 1; i > 0; --i)
		v.emplace_back(
			[&ioc]
	{
		ioc.run();
	});
	ioc.run();

	return EXIT_SUCCESS;
}