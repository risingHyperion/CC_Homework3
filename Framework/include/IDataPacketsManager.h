#pragma once

#include <map>

#include "Request.h"

namespace Framework
{
	template <class T>
	class IDataPacketsManager
	{
	public:
		virtual std::map<std::string, std::shared_ptr<T>> getMap() const = 0;
	};
}