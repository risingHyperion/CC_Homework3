#pragma once

#include "Response.h"
#include "IDataPacketsManager.h"

class ResponsesManager : public Framework::IDataPacketsManager<Framework::Response>
{
public:
	ResponsesManager();

	virtual std::map<std::string, std::shared_ptr<Framework::Response>> getMap() const override;

private:
	std::map<std::string, std::shared_ptr<Framework::Response>> Responses;
};