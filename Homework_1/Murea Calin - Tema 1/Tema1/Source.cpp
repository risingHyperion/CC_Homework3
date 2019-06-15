#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <memory>
#include "Utils.h"
#include "Vehicle.h"

auto main() -> int
{
	{
		Utils<int> lv_nUtils;
		Utils<double> lv_dfUtils;
		Utils<int> vect;

		auto const lv_nMaxElement = lv_dfUtils.mf_MaxElement(7, 10);
		auto const lv_dfMaxElement = lv_dfUtils.mf_MaxElement(2.3, 4.5);

		std::cout << lv_nMaxElement << std::endl;
		std::cout << lv_dfMaxElement << std::endl << std::endl;

		// Rezolvare punctul 1
		vect.insertElements(7);
		vect.insertElements(3);
		vect.insertElements(17);
		vect.insertElements(23);
		vect.insertElements(4);
		vect.insertElements(5);
		vect.insertElements(33);
		vect.insertElements(18);
		vect.insertElements(2);
		vect.insertElements(9);
		vect.insertElements(4);
		vect.insertElements(6);

		vect.printVector();

		std::cout << "Elementul din mijlocul vectorului este: " << vect.meanOfVector() << std::endl;

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
		//std::cout << std::endl << "Refference count: " << lv_sharedPtr1.use_count() << std::endl;
	}
	//std::cout << "Refference count: " << lv_sharedPtr1.use_count() << std::endl << std::endl;
	
	{
		// Rezolvare punctul 2

		Vehicle car1("Toyota", 2019);
		Vehicle car2("Mazda", 2018);
		Vehicle car3("Audi", 2017);
		Vehicle car4("BMW", 2015);
		Vehicle car5("Volkswagen", 2016);

		//std::cout << "Prima marca: " << car1.getBrand() << std::endl;

		std::map<Vehicle, std::string, Vehicle::Comparator> vehiclesMap;
		vehiclesMap.insert(std::make_pair(car1, std::string("Toyota")));
		vehiclesMap.insert(std::make_pair(car2, std::string("Mazda")));
		vehiclesMap.insert(std::make_pair(car3, std::string("Audi")));
		vehiclesMap.insert(std::make_pair(car4, std::string("BMW")));
		vehiclesMap.insert(std::make_pair(car5, std::string("Volkswagen")));


		for (auto const mapIterator : vehiclesMap)
		{
			std::cout << mapIterator.first << " " << mapIterator.second << std::endl;
		}

		/*for (auto it = vehiclesMap.begin(); it != vehiclesMap.end(); it++) {
			std::cout << it->first << " - " << it->second << "\n";
		}*/
	}
	 

	system("pause");
	return EXIT_SUCCESS;
	
}