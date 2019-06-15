#include <iostream>
#include <thread>
#include <mutex>
#include <stdexcept>  
#include <vector>
#include "Wallet.cpp"

int testMultithreadedWallet()
{
	Wallet walletObject;
	std::vector<std::thread> threads;
	for (int i = 0; i < 5; ++i) {
		threads.push_back(std::thread(&Wallet::addMoney, &walletObject, 1000));
	}
	for (int i = 0; i < threads.size(); i++)
	{
		threads.at(i).join();
	}
	return walletObject.getMoney();
}
int main()
{
	int val = 0;
	for (int k = 0; k < 1000; k++)
	{
		if ((val = testMultithreadedWallet()) != 5000)
		{
			std::cout << "Error at count = " << k << " Money in Wallet = " << val << std::endl;
		}
	}

	system("pause");
	return 0;
}