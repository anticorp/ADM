#include "_MACHINE.h"

namespace adm
{
	namespace _
	{
	}
	void ADMdelay(uint32_t delayInMilli)
	{
		if (_::pass::Delay)
		{
			_::out::Monitor->print("\nxBUG BLOCKING DELAY = ");
			_::out::Monitor->print(delayInMilli);
			_::out::Monitor->print(" ms\n");
			delay(delayInMilli);
		}
	}
}