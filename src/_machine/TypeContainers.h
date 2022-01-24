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
		struct DblContainer
		{
			DblContainer(const double _inDouble);
			operator double();
			const double number;
		};

	}
}

