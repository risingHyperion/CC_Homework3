#include "RequestsManager.h"

#include "HandshakeRequest.h"
#include "SumRequest.h"

RequestsManager::RequestsManager()
{
	this->requests.emplace("Handshake", std::make_shared<HandshakeRequest>());
	this->requests.emplace("Sum", std::make_shared<SumRequest>());
}

std::map<std::string, std::shared_ptr<Framework::Request>> RequestsManager::getMap() const
{
	return this->requests;
}
