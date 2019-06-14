#pragma once
#include <iostream>


class Vechile 
{
private:
	std::string brand;
	int year;

public:
	Vechile();
	Vechile(std::string brand, int year);
	std::string getBrand();
	int getYear();

	struct Comparator
	{
		bool operator()(const Vechile& left, const Vechile& right) const
		{
			return left.year < right.year;
		}
	};

	friend std::ostream& operator<<(std::ostream& output, const Vechile vechile) {
		output << vechile.year;
		return output;
	}

};
