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

	{
		std::cout << "Tema 1 -> Level 1 " << std::endl<< std::endl;

		Utils <int> v;
		v.addNumber(32);
		v.addNumber(56);
		v.addNumber(21);
		v.addNumber(13);
		v.addNumber(26);
		//v.addNumber(29);

		v.displayVectorContents();
		v.meanOfElements();
		std::cout << std::endl;

	}
	{
		std::cout << "Tema 1 -> Level 2 " << std::endl<<std::endl;

		Vehicle v1 = Vehicle("Ford",2019);
		Vehicle v2 = Vehicle("BMW", 2002);
		Vehicle v3 = Vehicle("Skoda", 2004);
		Vehicle v4 = Vehicle("Audi", 1998);
		Vehicle v5 = Vehicle("Mazda", 2008);
	
		std::map<Vehicle, std::string, Vehicle::Comparator> vehiclesMap;
		vehiclesMap.insert(std::make_pair(v1, std::string("Ford")));
		vehiclesMap.insert(std::make_pair(v2, std::string("BMW")));
		vehiclesMap.insert(std::make_pair(v3, std::string("Skoda")));
		vehiclesMap.insert(std::make_pair(v4, std::string("Audi")));
		vehiclesMap.insert(std::make_pair(v5, std::string("Mazda")));
		
		
		for (std::map<Vehicle, std::string, Vehicle::Comparator>::iterator it = vehiclesMap.begin(); it != vehiclesMap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}

	return EXIT_SUCCESS;
}