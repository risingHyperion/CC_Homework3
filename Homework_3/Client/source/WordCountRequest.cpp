#include "WordCountRequest.h"

WordCountRequest::WordCountRequest() : Request("WordCounter")
{
	this->content.push_back(boost::property_tree::ptree::value_type("Sentence", "The quick brown fox jumps over the lazy dog!"));
}