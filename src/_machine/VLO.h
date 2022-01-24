#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#include "TypeContainers.h"

namespace adm
{
	class ULO;
	class DOUBLEVAR
	{
	public:
		DOUBLEVAR() {}
		~DOUBLEVAR() {}
	};
	class BOOLVAR
	{
	public:
		BOOLVAR() {}
		~BOOLVAR() {}
	};
	class CHARVAR
	{
	public:
		CHARVAR() {}
		~CHARVAR() {}
	};
	class VLO
	{
	public:
		VLO();
		~VLO();
		VLO& operator << (const char*);
		VLO& operator << (const String&);
		VLO& operator << (const int);
		VLO& operator << (const _::DblContainer);
		//VLO& operator << (const float&);
		//VLO& operator << (const double&);


	private:

	};

	namespace _
	{
		namespace varobj
		{
			class VARS
			{
			public:
				VARS(bool);
				~VARS() {}

			private:
				bool m_init;
				int y;

			};
			extern VARS Vars;

		}
	}
}