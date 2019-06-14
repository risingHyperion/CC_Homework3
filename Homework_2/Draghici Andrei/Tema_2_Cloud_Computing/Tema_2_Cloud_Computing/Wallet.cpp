// Student: Draghici Andrei Cosmin, Anul II ID
// Homework 2 - Cloud Computing part 2

#include "Wallet.h"

Wallet::Wallet(int myMoney)
{
	this->myMoney = myMoney;
}
int Wallet::getMoney() const
{
	return this->myMoney;
}

void Wallet::addMoney(const int &money) 
{
	//std::lock_guard<std::mutex> lockGuard(mutex);

	std::cout << "Thread is writing" << std::endl;
	for (int i = 0; i < money; ++i)
	{
		myMoney++;
	}
}
