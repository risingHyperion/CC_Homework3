#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <memory>
#include "Utils.h"
#include "Vechile.h"

auto main() -> int
{
	{
		Utils<int> lv_nUtils;
		Utils<double> lv_dfUtils;

		auto const lv_nMaxElement = lv_dfUtils.mf_MaxElement(7, 10);
		auto const lv_dfMaxElement = lv_dfUtils.mf_MaxElement(2.3, 4.5);

		std::cout << lv_nMaxElement << std::endl;
		std::cout << lv_dfMaxElement << std::endl << std::endl;
	}

	{
		std::map<int, std::string> lv_Map;
		lv_Map.insert(std::make_pair(5, std::string("FirstInesrtion")));
		lv_Map.insert(std::make_pair(3, std::string("SecondInsertion")));

		for (auto const mapIterator : lv_Map)
		{
			std::cout << mapIterator.first << " " << mapIterator.second << std::endl;
		}

	}

	{
		std::map<Utils<int>, int, Utils<int>::Comparator> lv_UtilsMaps;
		Utils<int> lv_nUtils1;
		Utils<int> lv_nUtils2;
		lv_UtilsMaps.insert(std::make_pair(lv_nUtils1, 0));
		lv_UtilsMaps.insert(std::make_pair(lv_nUtils2, 1));

	}

	std::shared_ptr<Utils<int>> lv_sharedPtr1 = std::make_shared<Utils<int>>();
	{
		std::shared_ptr<Utils<int>> lv_sharedPtr2 = lv_sharedPtr1;
		std::cout << std::endl << "Refference count: " << lv_sharedPtr1.use_count() << std::endl;
	}
	std::cout << "Refference count: " << lv_sharedPtr1.use_count() << std::endl << std::endl;

	// LEVEL 1
	{
		Utils<int> myVector;

		myVector.addElementsToVector(3);
		myVector.addElementsToVector(10);
		myVector.addElementsToVector(2);
		myVector.addElementsToVector(5);
		myVector.addElementsToVector(7);
		myVector.addElementsToVector(1);
		myVector.addElementsToVector(11);

		myVector.printElementsFromVector();
		std::cout << "\nMean of myVector: " << myVector.getMeanOfVector() << "\n";

	}

	// LEVEL 2
	{
		Vechile car1 = Vechile("Toyota", 2007);
		Vechile car2 = Vechile("Audi", 2010);
		Vechile car3 = Vechile("Mercedes-Benz", 2018);
		Vechile car4 = Vechile("Chrysler", 2019);
		Vechile car5 = Vechile("Mustang", 2000);

		std::map<Vechile, std::string, Vechile::Comparator> myVechileMap;
		myVechileMap.insert(std::pair<Vechile, std::string>(car1, car1.getBrand()));
		myVechileMap.insert(std::pair<Vechile, std::string>(car2, car2.getBrand()));
		myVechileMap.insert(std::pair<Vechile, std::string>(car3, car3.getBrand()));
		myVechileMap.insert(std::pair<Vechile, std::string>(car4, car4.getBrand()));
		myVechileMap.insert(std::pair<Vechile, std::string>(car5, car5.getBrand()));

		for (auto const mapIterator : myVechileMap)
		{
			std::cout << mapIterator.first << " " << mapIterator.second << std::endl;
		}

	}
	
	return EXIT_SUCCESS;
}