#include "ResponsesManager.h"

#include "HandshakeResponse.h"
#include "SumResponse.h"

ResponsesManager::ResponsesManager()
{
	this->Responses.emplace("Handshake", std::make_shared<HandshakeResponse>());
	this->Responses.emplace("Sum", std::make_shared<SumResponse>());
}

std::map<std::string, std::shared_ptr<Framework::Response>> ResponsesManager::getMap() const
{
	return this->Responses;
}
