#pragma once

namespace Framework
{
	class IDataPacket
	{
	public:
		IDataPacket() = default;

		virtual std::string getContentAsString() const = 0;
	};
}