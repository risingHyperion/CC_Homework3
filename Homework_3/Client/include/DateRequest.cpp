#include "DateRequest.h"

DateRequest::DateRequest() : Request("Date")
{
	this->content.push_back(boost::property_tree::ptree::value_type("Year", "1909"));
	this->content.push_back(boost::property_tree::ptree::value_type("Month", "43"));
	this->content.push_back(boost::property_tree::ptree::value_type("Day", "2"));
}
