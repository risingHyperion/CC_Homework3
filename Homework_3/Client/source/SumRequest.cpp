#include "SumRequest.h"

SumRequest::SumRequest() : Request("Sum")
{
	this->content.push_back(boost::property_tree::ptree::value_type("First_Number", "2"));
	this->content.push_back(boost::property_tree::ptree::value_type("Second_Number", "4"));
}
