#include<iostream>
#include<thread>
#include<vector>
#include<mutex>

class Wallet
{
	int mMoney;
public:
	Wallet() :mMoney(0) {}
	int getMoney() { return mMoney; }
	void addMoney(int money)
	{
		for (int i = 0; i < money; ++i)
		{
			mMoney++;
		}
	}
};