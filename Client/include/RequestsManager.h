#pragma once

#include "IDataPacketsManager.h"

class RequestsManager : public Framework::IDataPacketsManager<Framework::Request>
{
public:
	RequestsManager();

	virtual std::map<std::string, std::shared_ptr<Framework::Request>> getMap() const override;

private:
	std::map<std::string, std::shared_ptr<Framework::Request>> requests;
};