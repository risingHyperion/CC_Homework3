#pragma once
#include <string.h>
#include <vector>

class Vehicle
{
public:
	struct Comparator
	{
		bool operator()(const Vehicle & left, const Vehicle & right) const
		{
			return left.Year < right.Year;
		}
	};
	friend std::ostream& operator<< (std::ostream& os, const Vehicle& dt)
	{
		os << dt.Brand << " " << dt.Year;
		return os;
	}

	Vehicle(std::string brand, int year)
	{
		Brand = brand;
		Year = year;

	}
	~Vehicle() = default;
	
	void displayVehicles()
	{
		std::cout << Brand << " " << Year << std::endl;
	}

private:
	std::string Brand;
	int Year;
};
