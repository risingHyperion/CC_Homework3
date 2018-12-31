#pragma once

#include "IDataPacket.h"

#include <boost/property_tree/ptree.hpp>

namespace Framework
{
	class IRequest : public IDataPacket
	{
	public:
		virtual boost::property_tree::ptree generateResponse() = 0;
	};
}