#pragma once

#if !defined(__ADM__ULO__h__)
	#define __ADM__ULO__h__

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "SLO.h"
#include "TLO.h"
#include "VLO.h"
#include "BugTimeout.h"

#define _BUG_USE_MACRO_HELPERS_
#if defined(_BUG_USE_MACRO_HELPERS_)
#define xpara helper::_xpara
#define xnt helper::_xnt
#define xntt helper::_xntt
#define xnttt helper::_xnttt
#define xntttt helper::_xntttt
#define xnnt helper::_xnnt
#define xnntt helper::_xnntt
#define xn helper::_xn
#define xnn helper::_xnn
#define xnnn helper::_xnnn
#define xnnnn helper::_xnnnn
#define xt helper::_xt
#define xtt helper::_xtt
#define xttt helper::_xttt
#define xtttt helper::_xtttt
#define xEqLine60 helper::_xEqual60
#define xStarLine60 helper::_xStar60
#define xSinLine60 helper::_xSingle60

#endif

namespace helper
{
	namespace ULOHELPER
	{
		class ULOHelper {
		public:
			ULOHelper() {}
			//virtual const char* MyThing() const {}
			virtual const __FlashStringHelper* MyThing() const {}
		};
		class PARA : public ULOHelper
		{
		public:
			const __FlashStringHelper* MyThing() const override { return F("\n\n\t"); }
		};
		class INDENTx1 : public ULOHelper
		{
		public:
			const __FlashStringHelper* MyThing() const override { return F("\n\t"); }
		};
		class INDENTx2 : public ULOHelper
		{
		public:
			const __FlashStringHelper* MyThing() const override { return F("\n\t\t"); }
		};
		class INDENTx3 : public ULOHelper
		{
		public:
			const __FlashStringHelper* MyThing() const override { return F("\n\t\t\t"); }
		};
		class INDENTx4 : public ULOHelper
		{
		public:
			const __FlashStringHelper* MyThing() const override { return F("\n\t\t\t\t"); }
		};
		class NLx1 : public ULOHelper
		{
		public:
			const __FlashStringHelper* MyThing() const override { return F("\n"); }
		};
		class NLx2 : public ULOHelper
		{
		public:
			const __FlashStringHelper* MyThing() const override { return F("\n\n"); }
		};
		class NLx3 : public ULOHelper
		{
		public:
			const __FlashStringHelper* MyThing() const override { return F("\n\n\n"); }
		};
		class NLx4 : public ULOHelper
		{
		public:
			const __FlashStringHelper* MyThing() const override { return F("\n\n\n\n"); }
		};
		class NTx1 : public ULOHelper
		{
		public:
			const __FlashStringHelper* MyThing() const override { return F("\t"); }
		};
		class NTx2 : public ULOHelper
		{
		public:
			const __FlashStringHelper* MyThing() const override { return F("\t\t"); }
		};
		class NTx3 : public ULOHelper
		{
		public:
			const __FlashStringHelper* MyThing() const override { return F("\t\t\t"); }
		};
		class NTx4 : public ULOHelper
		{
		public:
			const __FlashStringHelper* MyThing() const override { return F("\t\t\t\t"); }
		};
		class NNT : public ULOHelper
		{
		public:
			const __FlashStringHelper* MyThing() const override { return F("\n\n\t"); }
		};
		class NNTT : public ULOHelper
		{
		public:
			const __FlashStringHelper* MyThing() const override { return F("\n\n\t\t"); }
		};
		class WIDEEQUALLINEx60 : public ULOHelper
		{
		public:
			const __FlashStringHelper* MyThing() const override { return F("\n============================================================\n"); }
		};
		class WIDESTARLINEx60 : public ULOHelper
		{
		public:
			const __FlashStringHelper* MyThing() const override { return F("\n************************************************************\n"); }
		};
		class WIDESINGLELINEx60 : public ULOHelper
		{
		public:
			const __FlashStringHelper* MyThing() const override { return F("\n------------------------------------------------------------\n"); }
		};
		extern PARA _xpara;
		extern INDENTx1 _xnt;
		extern INDENTx2 _xntt;
		extern INDENTx3 _xnttt;
		extern INDENTx4 _xntttt;
		extern NLx1 _xn;
		extern NLx2 _xnn;
		extern NLx3 _xnnn;
		extern NLx4 _xnnnn;
		extern NTx1 _xt;
		extern NTx2 _xtt;
		extern NTx3 _xttt;
		extern NTx4 _xtttt;
		extern NNT _xnnt;
		extern NNTT _xnntt;
		extern WIDEEQUALLINEx60 _xEqual60;
		extern WIDESTARLINEx60 _xStar60;
		extern WIDESINGLELINEx60 _xSingle60;
		extern adm::DOUBLEVAR _XDBL;
		extern adm::BOOLVAR _XBOOL;
		extern adm::CHARVAR _XCHAR;
	}
	extern adm::DOUBLEVAR* xBugDoubleHelper;
	extern adm::BOOLVAR* xBugBoolHelper;
	extern adm::CHARVAR* xBugCharHelper;
	extern ULOHELPER::ULOHelper* _xpara;
	extern ULOHELPER::ULOHelper* _xnt;
	extern ULOHELPER::ULOHelper* _xntt;
	extern ULOHELPER::ULOHelper* _xnttt;
	extern ULOHELPER::ULOHelper* _xntttt;
	extern ULOHELPER::ULOHelper* _xn;
	extern ULOHELPER::ULOHelper* _xnn;
	extern ULOHELPER::ULOHelper* _xnnn;
	extern ULOHELPER::ULOHelper* _xnnnn;
	extern ULOHELPER::ULOHelper* _xt;
	extern ULOHELPER::ULOHelper* _xtt;
	extern ULOHELPER::ULOHelper* _xttt; 
	extern ULOHELPER::ULOHelper* _xtttt;
	extern ULOHELPER::ULOHelper* _xnnt;
	extern ULOHELPER::ULOHelper* _xnntt;
	extern ULOHELPER::ULOHelper* _xEqual60;
	extern ULOHELPER::ULOHelper* _xStar60;
	extern ULOHELPER::ULOHelper* _xSingle60;
}

namespace adm
{

	extern bool SerialInit;
	void InitializeSerial(uint32_t baud);
	class ULO
	{
	public:
		ULO();
		ULO(const char*);
		ULO(const double& dbl);
		typedef ULO& (ULO::* typeFCN)(const double&);
		SLO operator << (_::setobj::SETTINGOBJECT* _inSet);

		ULO& operator << (const helper::ULOHELPER::ULOHelper* helperPtr);
		ULO& operator << (const char*);

		ULO& operator << (const String&);
		ULO& operator << (const __FlashStringHelper*);

		ULO& operator << (const double& i);

		ULO& operator << (const BOOLVAR* bv);
		ULO& operator << (const DOUBLEVAR* dv);
		ULO& operator << (const CHARVAR* dv);

		SLO operator << (UARTClass& _inSerial);
		TLO operator << (_::traceobj::TRACE* _trace);
		VLO operator << (_::varobj::VARS* _vars);
	private:
		ULO& OutAsInt(const double& i);
		ULO& OutAsBool(const double& i);
		ULO& OutAsDouble(const double& i);
		ULO& OutAsChar(const double& i);
		typeFCN OutAsFNC[4] = { &ULO::OutAsInt,&ULO::OutAsBool,&ULO::OutAsDouble,&ULO::OutAsChar };
		int mAOA = 0;
		int shifter = 0;
		bool customOut = false;
		bool nextIsDbl = false;
		bool nextIsBool = false;
		bool nextIsChar = false;
	};

}
#endif