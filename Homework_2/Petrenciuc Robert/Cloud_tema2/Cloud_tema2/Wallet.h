#pragma once
#include<mutex>

class Wallet
{
	int money;
	std::mutex mutex;
public:
	Wallet()
	{
		money = 0;
	}
	int getMoney() 
	{ 
		return money; 
	}
	void addMoney(int m)
	{
		std::lock_guard<std::mutex> lockGuard(mutex);
		//mutex.lock();
		std::cout << "Thread id: " << std::this_thread::get_id() <<" is adding money..."<< std::endl;
		for (int i = 0; i < m; i++)
		{
			money++;
		}
		//mutex.unlock();
	}
};