#if !defined(__ADM__nLO__h__)
#define __ADM__nLO__h__

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#include "VLO.h"
#include "TLO.h"
#include "SLO.h"

namespace adm
{
	class nLO
	{
	public:
		nLO();
		//template<class T>
		//nLO& operator << (T&) { return *this; }
		nLO& operator << (const char* _in) { return *this; }
		nLO& operator << (const String&) { return *this; }
		nLO& operator << (const int&) { return *this; }
		nLO& operator << (const _::varobj::VARS*) { return *this; }
		nLO& operator << (const _::traceobj::TRACE*) { return *this; }


	};
}

#endif
