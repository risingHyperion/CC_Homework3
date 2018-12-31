#pragma once

#include "IDataPacket.h"

#include <boost/property_tree/ptree.hpp>

namespace Framework
{
	class IResponse : public IDataPacket
	{
	public:
		virtual boost::property_tree::ptree getResponse() = 0;
	};
}