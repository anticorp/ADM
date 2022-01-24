#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

namespace adm
{
	namespace _
	{
		namespace pass
		{
			extern bool Active;
			extern bool Trace;
			extern bool Vars;
			extern bool Chat;
			extern bool Delay;
			extern bool Watch;
			extern bool ScopeBlock;
		}
		namespace init
		{
			extern bool Monitor;
			extern bool Serial;
		}
		namespace breathe
		{
			extern uint32_t Chat;
			extern uint32_t Vars;
			extern uint32_t Trace;
			extern uint32_t StartUp;

		}
		namespace out
		{
			extern UARTClass* Monitor;
		}
	}
	namespace TIMER
	{
		extern int TimeoutInterval;
		//extern ClockCache clock;
		extern bool Enabled;
	}
	// Resets Timeout Timer. PC side takes anything as valid input once connected, so we'll reset the clock everytime we send.
	void EnableTimeout();
	void DisableTimeout();
	void TimeoutSendLOOP();
	void TX();
}