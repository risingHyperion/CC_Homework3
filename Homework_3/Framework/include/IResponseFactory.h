#pragma once

#include <string>

#include "Response.h"

namespace Framework
{
	class IResponseFactory
	{
	public:
		IResponseFactory() = default;

		virtual std::string generateResponse(const std::string& request) const = 0;
	};
}