#include <stdlib.h>

#include "SumResponse.h"

SumResponse::SumResponse() : Response("Sum")
{

}

std::string SumResponse::interpretPacket(const boost::property_tree::ptree& packet)
{
	auto firstNumber = atoi(packet.get<std::string>("First_Number").c_str());
	auto secondNumber = atoi(packet.get<std::string>("Second_Number").c_str());

	this->content.push_back(boost::property_tree::ptree::value_type("File", "sum.txt"));
	this->content.push_back(boost::property_tree::ptree::value_type("Result", std::to_string(firstNumber + secondNumber)));

	return this->getContentAsString();
}
