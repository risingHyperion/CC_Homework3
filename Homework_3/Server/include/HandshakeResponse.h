#pragma once

#include "Response.h"

class HandshakeResponse : public Framework::Response
{
public:
	HandshakeResponse();

	std::string interpretPacket(const boost::property_tree::ptree& packet);
};