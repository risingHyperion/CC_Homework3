#pragma once
#include <string>
class Vehicle
{
private:
	std::string Brand;
	int Year;
public:
	Vehicle();
	Vehicle(std::string Brand, int Year);
	std::string getBrand();
	~Vehicle();

	struct Comparator
	{
		bool operator()(const Vehicle & left, const Vehicle & right) const
		{
			return left.Year < right.Year;
		}
	};

	friend std::ostream& operator<< (std::ostream& os, const Vehicle& data)
	{
		os << data.Year;
		return os;
	}
};

