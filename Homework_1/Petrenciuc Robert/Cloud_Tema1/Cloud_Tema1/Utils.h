#pragma once

#include <vector>
#include <string.h>

template <typename T>
class Utils
{
public:

	struct Comparator
	{
		bool operator()(const Utils & left, const Utils & right) const
		{
			return left.mv_Value < right.mv_Value;
		}
	};

	Utils() = default;

	auto mf_MaxElement(T lv_FirstElement, T lv_SecondElement) const -> T
	{
		return lv_FirstElement > lv_SecondElement ? lv_FirstElement : lv_SecondElement;
	}

	~Utils() = default;

	void addNumber(int num)
	{
		myVector.push_back(num);
	}
	void displayVectorContents()
	{
		for (size_t i = 0; i < myVector.size(); i++)
		{
			std::cout << "Element[" << i << "] = " << myVector[i] << std::endl;
		}
		std::cout << std::endl;
	}
	void meanOfElements()
	{
		int mean = myVector.size() / 2;
		if(myVector.size()%2==0)
			std::cout << "The mean of the elements is at position: " << mean-1 << " and the element is: " << myVector[mean-1] << std::endl;
		else
		std::cout << "The mean of the elements is at position: " << mean << " and the element is: " << myVector[mean] << std::endl;
	}
private:
	T mv_Value;
	std::vector<T> myVector;

};