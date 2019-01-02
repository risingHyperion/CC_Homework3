#pragma once

#include "Response.h"

class SumResponse : public Framework::Response
{
public:
	SumResponse();

	std::string interpretPacket(const boost::property_tree::ptree& packet);
};