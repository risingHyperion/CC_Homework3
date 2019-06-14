#include <iostream>

#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "Request.h"

namespace Framework
{
	Request::Request(const std::string& actionName)
	{
		this->content.push_front(boost::property_tree::ptree::value_type("Action", actionName));
	}

	std::string Request::getContentAsString() const
	{
		std::ostringstream buffer;

		boost::property_tree::write_json(buffer, this->content, false);

		return buffer.str();
	}
}