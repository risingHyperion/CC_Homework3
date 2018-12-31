#pragma once

namespace Framework
{
	class IDataPacket
	{
	public:
		virtual void interpretPacket() = 0;

		virtual ~IDataPacket() = default;
	};
}