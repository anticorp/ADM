#include "Common.h"
#include "ClockCache.h"

namespace adm
{
	namespace _
	{
		namespace pass
		{
			bool Active = false;
			bool Trace = false;
			bool Vars = false;
			bool Chat = false;
			bool Delay = false;
			bool Watch = false;
			bool ScopeBlock = false;
		}
		namespace init
		{
			bool Monitor = false;
			bool Serial = false;
		}
		namespace breathe
		{
			uint32_t Chat = 0;
			uint32_t Vars = 0;
			uint32_t Trace = 0;
			uint32_t StartUp = 300;

		}
		namespace out
		{
			UARTClass* Monitor = nullptr;
		}
		
	}
	namespace TIMER
	{
		ClockCache clock = ClockCache();
		int TimeoutInterval = 5000;
		bool Enabled = false;
	}
	void EnableTimeout()
	{
		TIMER::Enabled = true;
		TX();
	}
	void DisableTimeout()
	{
		TIMER::Enabled = false;
	}
	void TimeoutSendLOOP()
	{
		if (TIMER::Enabled)
		{
			if (TIMER::clock.Delta() >= TIMER::TimeoutInterval)
			{
				TIMER::clock.Mark();
				if (_::init::Monitor)
				{
					_::out::Monitor->print(".");
				}
			}
		}
	}
	void TX()
	{
		TIMER::clock.Mark();
	}
}