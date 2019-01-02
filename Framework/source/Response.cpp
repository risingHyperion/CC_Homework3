#include <iostream>

#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "Response.h"

namespace Framework
{
	Response::Response(const std::string& actionName)
	{
		this->content.push_front(boost::property_tree::ptree::value_type("Action", actionName));
	}

	std::string Response::getContentAsString() const
	{
		std::ostringstream buffer;

		boost::property_tree::write_json(buffer, this->content, false);

		return buffer.str();
	}

	std::string Response::interpretPacket(const boost::property_tree::ptree & packet)
	{
		throw "Your derived class has to implement this method";
	}
}