#pragma once

#include "Response.h"

class WordCountResponse : public Framework::Response
{
public:
	WordCountResponse();

	std::string interpretPacket(const boost::property_tree::ptree& packet);
};