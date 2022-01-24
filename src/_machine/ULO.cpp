#include "ULO.h"
#include "Common.h"

namespace helper
{
	namespace ULOHELPER
	{
		PARA _xpara = PARA();
		INDENTx1 _xnt = INDENTx1();
		INDENTx2 _xntt = INDENTx2();
		INDENTx3 _xnttt = INDENTx3();
		INDENTx4 _xntttt = INDENTx4();
		NNT _xnnt = NNT();
		NNTT _xnntt = NNTT();
		NLx1 _xn = NLx1();
		NLx2 _xnn = NLx2();
		NLx3 _xnnn = NLx3();
		NLx4 _xnnnn = NLx4();
		NTx1 _xt = NTx1();
		NTx2 _xtt = NTx2();
		NTx3 _xttt = NTx3();
		NTx4 _xtttt = NTx4();
		WIDEEQUALLINEx60 _xEqual60 = WIDEEQUALLINEx60();
		WIDESTARLINEx60 _xStar60 = WIDESTARLINEx60();
		WIDESINGLELINEx60 _xSingle60 = WIDESINGLELINEx60();
		adm::DOUBLEVAR XDBL = adm::DOUBLEVAR();
		adm::BOOLVAR XBOOL = adm::BOOLVAR();
		adm::CHARVAR XCHAR = adm::CHARVAR();
	}
	adm::DOUBLEVAR* xBugDoubleHelper = &ULOHELPER::XDBL;
	adm::BOOLVAR* xBugBoolHelper = &ULOHELPER::XBOOL;
	adm::CHARVAR* xBugCharHelper = &ULOHELPER::XCHAR;
	ULOHELPER::ULOHelper* _xpara = &ULOHELPER::_xpara;
	ULOHELPER::ULOHelper* _xnt = &ULOHELPER::_xnt;
	ULOHELPER::ULOHelper* _xntt = &ULOHELPER::_xntt;
	ULOHELPER::ULOHelper* _xnttt = &ULOHELPER::_xnttt;
	ULOHELPER::ULOHelper* _xntttt = &ULOHELPER::_xntttt;
	ULOHELPER::ULOHelper* _xnnt = &ULOHELPER::_xnnt;
	ULOHELPER::ULOHelper* _xnntt = &ULOHELPER::_xnntt;
	ULOHELPER::ULOHelper* _xn = &ULOHELPER::_xn;
	ULOHELPER::ULOHelper* _xnn = &ULOHELPER::_xnn;
	ULOHELPER::ULOHelper* _xnnn = &ULOHELPER::_xnnn;
	ULOHELPER::ULOHelper* _xnnnn = &ULOHELPER::_xnnnn;
	ULOHELPER::ULOHelper* _xt = &ULOHELPER::_xt;
	ULOHELPER::ULOHelper* _xtt = &ULOHELPER::_xtt;
	ULOHELPER::ULOHelper* _xttt = &ULOHELPER::_xttt;
	ULOHELPER::ULOHelper* _xtttt = &ULOHELPER::_xtttt;
	ULOHELPER::ULOHelper* _xEqual60 = &ULOHELPER::_xEqual60;
	ULOHELPER::ULOHelper* _xStar60 = &ULOHELPER::_xStar60;
	ULOHELPER::ULOHelper* _xSingle60 = &ULOHELPER::_xSingle60;
}
namespace adm
{
	bool SerialInit = false;
	void InitializeSerial(uint32_t baud)
	{
		Serial.begin(baud);
		SerialInit = true;
	}
	
	ULO::ULO()
	{
	}

	ULO& ULO::operator<<(const BOOLVAR* bv)
	{
		mAOA = 1;
	}
	ULO& ULO::operator<<(const DOUBLEVAR* dv)
	{
		mAOA = 2;
	}

	ULO& ULO::operator<<(const CHARVAR* dv)
	{
		mAOA = 3;
	}


	ULO& ULO::operator << (const helper::ULOHELPER::ULOHelper* hp)
	{
		if (_::pass::Chat)
		{
			_::out::Monitor->print(hp->MyThing());
			TX();
		}
		return *this;
	}
	ULO& ULO::operator << (const char* _inChar)
	{
		if (_::pass::Chat)
		{
			_::out::Monitor->print(_inChar);
			TX();
			//delay(_::breathe::Chat);
		}
		return *this;
	}
	ULO& ULO::operator << (const String& _inString)
	{
		if (_::pass::Chat)
		{
			_::out::Monitor->print(_inString);
			TX();
		}
		return *this;
	}
	ULO& ULO::operator<<(const __FlashStringHelper* fsh)
	{
		if (_::pass::Chat)
		{
			_::out::Monitor->print(fsh);
			TX();
		}
		return *this;
	}
	ULO& ULO::operator << (const double& i)
	{
		if (_::pass::Chat) 
		{
			return (this->*OutAsFNC[mAOA])(i);
		}
		return *this;
	}
	SLO ULO::operator << (_::setobj::SETTINGOBJECT* _inSetting)
	{
			Serial.print("\n[ ULO ]={ ?FIRST ORDER? }=");
		if (_inSetting->FirstOrderSettings())
		{
				Serial.print("\n[ ULO ]={ ?SECOND ORDER? }=");
			if (_inSetting->SecondOrderSettings())
			{
				Serial.print("\n[ ULO ]={ THIRD ORDER? }=");
				_inSetting->ThirdOrderSettings();
			} else Serial.print("{ NO }=");
		} else Serial.print("{ NO }=");

		return SLO();
	}
	SLO ULO::operator << (UARTClass& _inSerial)
	{
		return SLO(_inSerial, _::Monitor);
	}
	TLO ULO::operator << (_::traceobj::TRACE* _trace)
	{
		return TLO();
	}
	VLO ULO::operator << (_::varobj::VARS* _vars)
	{
		return VLO();
	}
	ULO& ULO::OutAsInt(const double& i)
	{
		_::out::Monitor->print((int)i);
		TX();
		return *this;
	}
	ULO& ULO::OutAsBool(const double& i)
	{
		_::out::Monitor->print(i ? "TRUE" : "FALSE");
		mAOA = 0;
		TX();
		return *this;
	}
	ULO& ULO::OutAsDouble(const double& i)
	{
		_::out::Monitor->print(i);
		mAOA = 0;
		TX();
		return *this;
	}
	ULO& ULO::OutAsChar(const double& i)
	{
		_::out::Monitor->print((char)i);
		mAOA = 0;
		TX();
		return *this;
	}
}
