// Student: Draghici Andrei Cosmin, Anul II ID
// Homework 2 - Cloud Computing part 2

#pragma once
#include<iostream>
#include<vector>
#include<mutex>

class Wallet
{
	int myMoney;
	std::mutex mutex;
public:
	Wallet(int myMoney = 0);
	int getMoney() const;
	void addMoney(const int & money);
};