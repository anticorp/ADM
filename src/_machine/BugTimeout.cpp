#include "BugTimeout.h"
//#include "Common.h"
//
//namespace adm
//{
//	namespace TIMER
//	{
//		ClockCache clock = ClockCache();
//		int TimeoutInterval = 8000;
//	}
//	void EnableTimeout()
//	{
//		TIMER::Enabled = true;
//		TX();
//	}
//	void DisableTimeout()
//	{
//		TIMER::Enabled = false;
//	}
//	void TimeoutSendLOOP()
//	{
//		if (TIMER::Enabled)
//		{
//			if (TIMER::clock.Delta() >= TIMER::TimeoutInterval)
//			{
//				TIMER::clock.Mark();
//				if (_::init::Monitor)
//				{
//					_::out::Monitor->print(".");
//				}
//			}
//		}
//	}
//	void TX()
//	{
//		TIMER::clock.Mark();
//	}
//}