#pragma once

#include <boost/property_tree/ptree.hpp>

#include "IDataPacket.h"

namespace Framework
{
	class Request : public std::enable_shared_from_this<Request>, public IDataPacket
	{
	public:
		Request() = default;
		Request(const std::string& actionName);

		std::string getContentAsString() const;
	protected:
		boost::property_tree::ptree content;
	};
}