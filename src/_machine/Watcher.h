#pragma once

#if !defined(__ADM__WATCHER__h__)
#define __ADM__WATCHER__h__

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#include "TLO.h"
namespace adm
{
	class WATCHER
	{
	public:
		WATCHER();
		WATCHER& operator << (_::traceobj::TRACE* _trace);
		WATCHER& operator << (const char*);

	private:


	};
	namespace _
	{
		namespace objs
		{
			class SCOPEWATCH
			{
			public:
				SCOPEWATCH();
				SCOPEWATCH(const String&);
				SCOPEWATCH(const String&, const String&);

				~SCOPEWATCH();
				SCOPEWATCH& operator << (const String& _FuncSignature);

			private:
				bool Active;
				bool mPrevTrace;
				bool mPrevVars;
				bool mPrevChat;
				bool mPrevDelay;
				bool mFuncSigLoaded;
				String mFunctionSignature;

			};
			class SCOPEBLOCK
			{
			public:
				SCOPEBLOCK();
				~SCOPEBLOCK();
			private:
				bool Active;
				bool mPrevTrace;
				bool mPrevVars;
				bool mPrevChat;
				bool mPrevDelay;
				bool mFuncSigLoaded;
			};
		}
	}
}

#endif