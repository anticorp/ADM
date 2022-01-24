#pragma once
#if !defined(__ADM__TLO__h__)
#define __ADM__TLO__h__

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif


namespace adm
{
	class TLO
	{
	public:
		TLO() {}
		~TLO() {}
		TLO& operator << (const char*);
		TLO& operator << (const String&);
		TLO& operator << (const int&);

	private:

	};

	namespace _
	{
		namespace traceobj
		{
			class TRACE
			{
			public:
				TRACE(bool in);
				~TRACE() {}

			private:
				bool Init;

			};
			extern TRACE Trace;
		}
	}
}

#endif
