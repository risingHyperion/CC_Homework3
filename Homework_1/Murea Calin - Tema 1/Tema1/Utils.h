#pragma once

#include <vector>

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

	auto insertElements(T element) {
		MyVector.push_back(element);
	}

	auto printVector() {
		std::cout << "Elementele vectorului: " << "\n";
		for (auto i : MyVector) {
			std::cout << i << " ";
		}
		std::cout << "\n";
	}

	auto meanOfVector() {
		int mean = MyVector.size() / 2;
		return MyVector.at(mean);
	}

private:
	T mv_Value;
	std::vector<T>MyVector;
};
