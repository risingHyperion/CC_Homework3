#pragma once

#include <vector>

template <typename T>
class Utils
{
public:
	struct Comparator
	{
		bool operator()(const Utils& left, const Utils& right) const
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

	auto addElementsToVector(T element)
	{
		myVector.push_back(element);
	}

	auto printElementsFromVector() 
	{
		std::cout << "Elements in vector: ";
		for (auto i : myVector) {
			std::cout << i << ' ';
		}
	}

	auto getMeanOfVector() {
		int meanOfVector = myVector.size() / 2;
		return myVector.at(meanOfVector);
	}

private:
	T mv_Value;
	std::vector<T> myVector;
};
