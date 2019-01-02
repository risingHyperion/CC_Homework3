#pragma once

#include "IResponseFactory.h"
#include "Response.h"
#include "ResponsesManager.h"

class ResponseFactory : Framework::IResponseFactory
{
public:
	ResponseFactory() = default;

	virtual std::string generateResponse(const std::string& request) const override;

private:
	ResponsesManager responsesManager;

	boost::property_tree::ptree stringToPropertyTree(const std::string& request) const;
};