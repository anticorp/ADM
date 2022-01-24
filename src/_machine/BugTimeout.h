#pragma once

//#if defined(ARDUINO) && ARDUINO >= 100
//#include "arduino.h"
//#else
//#include "WProgram.h"
//#endif

//#include <ClockCache.h>
//
//namespace adm
//{
//	namespace TIMER
//	{
//		extern int TimeoutInterval;
//		extern ClockCache clock;
//		extern bool Enabled = false;
//	}
//	// Resets Timeout Timer. PC side takes anything as valid input once connected, so we'll reset the clock everytime we send.
//	void EnableTimeout();
//	void DisableTimeout();
//	void TimeoutSendLOOP();
//	void TX();
//}