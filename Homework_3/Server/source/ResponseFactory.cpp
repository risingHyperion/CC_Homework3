#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/beast/core.hpp>

#include "ResponseFactory.h"

std::string ResponseFactory::generateResponse(const std::string & request) const
{
	auto requestPropertyTree = this->stringToPropertyTree(request);

	return this->responsesManager.getMap().at(requestPropertyTree.get<std::string>("Action"))->interpretPacket(requestPropertyTree);
}

boost::property_tree::ptree ResponseFactory::stringToPropertyTree(const std::string & request) const
{
	boost::property_tree::ptree result;	

	std::stringstream ss;
	ss << request;

	boost::property_tree::read_json(ss, result);

	return result;
}
