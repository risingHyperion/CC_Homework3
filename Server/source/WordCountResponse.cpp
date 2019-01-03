#include <stdlib.h>

#include "WordCountResponse.h"

WordCountResponse::WordCountResponse() : Response("WordCounter")
{

}

std::string WordCountResponse::interpretPacket(const boost::property_tree::ptree& packet)
{
	auto sentence = packet.get<std::string>("Sentence");

	std::stringstream wordsStream(sentence);
	auto wordCount = std::distance(std::istream_iterator<std::string>(wordsStream), std::istream_iterator<std::string>());

	this->content.push_back(boost::property_tree::ptree::value_type("File", "count.txt"));	
	this->content.push_back(boost::property_tree::ptree::value_type("Result", std::to_string(wordCount)));

	return this->getContentAsString();
}
