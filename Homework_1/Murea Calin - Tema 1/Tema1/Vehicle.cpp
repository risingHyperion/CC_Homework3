#include "Vehicle.h"



Vehicle::Vehicle()
{
}

Vehicle::Vehicle(std::string Brand, int Year) {
	this->Brand = Brand;
	this->Year = Year;
}

std::string Vehicle::getBrand() {
	return Brand;
}

Vehicle::~Vehicle()
{
}
