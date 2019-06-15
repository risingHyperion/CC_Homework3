#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <future>
#include "Wallet.h"


int testMultithreadedWallet()
{
	Wallet walletObject;
	std::vector<std::thread> threads;
	for (int i = 0; i < 100; i++) 
	{
		threads.push_back(std::thread(&Wallet::addMoney, &walletObject, 10));
		
	}

	for (int i = 0; i < threads.size(); i++)
	{
		threads.at(i).join();
	}

	return walletObject.getMoney();
}


int main()
{
	int total = 0;
	total = testMultithreadedWallet();
	std::cout<<"Suma totala in wallet: "<< total;

	return 0;
}
