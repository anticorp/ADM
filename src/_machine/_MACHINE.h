#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Common.h"

namespace adm
{
	void ADMdelay(uint32_t delayInMilli);


	namespace _
	{

	}
}
