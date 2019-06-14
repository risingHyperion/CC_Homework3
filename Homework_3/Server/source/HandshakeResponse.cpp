#include "HandshakeResponse.h"

HandshakeResponse::HandshakeResponse() : Response("Handshake")
{

}

std::string HandshakeResponse::interpretPacket(const boost::property_tree::ptree& packet)
{
	this->content.push_back(boost::property_tree::ptree::value_type("File", "misc.txt"));

	return this->getContentAsString();
}
