#pragma once

#include <boost/property_tree/ptree.hpp>

#include "IDataPacket.h"

namespace Framework
{
	class Response : public std::enable_shared_from_this<Response>, public IDataPacket
	{
	public:
		Response() = default;
		Response(const std::string& actionName);

		std::string getContentAsString() const;
		virtual std::string interpretPacket(const boost::property_tree::ptree & packet);
	protected:
		boost::property_tree::ptree content;
	};
}