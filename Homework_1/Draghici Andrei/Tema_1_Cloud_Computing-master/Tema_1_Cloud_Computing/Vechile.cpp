#include "Vechile.h"

Vechile::Vechile() {
	this->brand = "Undefined car";
	this->year = 1900;
}

Vechile::Vechile(std::string brand, int year) {
	this->brand = brand;
	this->year = year;
}

std::string Vechile::getBrand() {
	return this->brand;
}

int Vechile::getYear() {
	return this->year;
}