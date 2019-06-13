#pragma once

#include "Response.h"

class DateResponse : public Framework::Response
{
public:
	DateResponse();

	std::string interpretPacket(const boost::property_tree::ptree& packet);
};