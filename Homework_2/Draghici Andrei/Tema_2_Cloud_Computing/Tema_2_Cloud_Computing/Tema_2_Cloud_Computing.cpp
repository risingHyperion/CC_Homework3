// Student: Draghici Andrei Cosmin, Anul II ID
// Homework 2 - Cloud Computing part 2
// The code shows the 'Race condition' problem when using mutex and lock guard.

#include <iostream>
#include <thread>
#include <vector>
#include <stdexcept>  
#include "Wallet.h"

int runWalletThreading()
{
	Wallet walletObject;
	std::vector<std::thread> threads;

	// This variable indicates the sum of money that is going to be added by each thread.
	// For example: if the variable is set to '100' and we create 5 threads, the total amount of money
	// at the end should be 500.

	int amountToBeAdded = 100;
	int numberOfThreads = 5;

	for (int i = 0; i < numberOfThreads; ++i) {
		threads.push_back(std::thread(&Wallet::addMoney, &walletObject, amountToBeAdded));
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
	int countOfExecutions = 100;
	int totalSumOfMoneyExpected = 500;
	int issuesCounter = 0;
	std::vector<int> errorLocation;

	for (int i = 0; i < countOfExecutions; i++)
	{
		if ((val = runWalletThreading()) != totalSumOfMoneyExpected)
		{
			std::cout << "Error at count = " << i + 1 << std::endl << "Total sum of money = " << val << std::endl << std::endl;
			errorLocation.push_back(i + 1);
		}

		else 
		{
			std::cout << "All good on count = " << i + 1 << std::endl << "Total sum of money = " << val << std::endl << std::endl;
			issuesCounter++;
		}
	}

	if (issuesCounter == countOfExecutions)
	{
		std::cout << "No sum calculation errors found!" << std::endl;
	}
	else
	{
		std::cout << "Erros have been encountered in sum calculation. Total no. of errors: " << errorLocation.size() << "\nErrors encountered at location(s): ";
		for (int i = 0; i < errorLocation.size(); i++)
			std::cout << errorLocation.at(i) << " ";
		std::cout << std::endl;
	}

	return 0;
}