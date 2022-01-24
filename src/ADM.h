/*
 Name:		ADM.h
 Created:	5/29/2021 4:36:37 PM
 Author:	Robert
 Editor:	http://www.visualmicro.com
*/

#ifndef _ADM_h
#define _ADM_h

#define BUG_STATE true

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#include "_machine\ULO.h"
#include "_machine\nLO.h"
#include "_machine/VLO.h"
#include "_machine/SLO.h"
#include "_machine/TLO.h"
#include "_machine/SetState.h"
#include "_machine/Watcher.h"
#include "_machine/TypeContainers.h"
#include "_machine/_MACHINE.h"
#include "_machine/BugTimeout.h"


namespace adm
{
	namespace KEYWORDS
	{
		namespace set
		{
			extern _::setobj::SETTINGOBJECT* VarsOFF;
			extern _::setobj::SETTINGOBJECT* VarsON;
			extern _::setobj::SETTINGOBJECT* TraceOFF;
			extern _::setobj::SETTINGOBJECT* TraceON;
			extern _::setobj::SETTINGOBJECT* ChatON;
			extern _::setobj::SETTINGOBJECT* ChatOFF;
		}
	}
	namespace STREAMKEYWORDS
	{
		extern _::traceobj::TRACE* trace_;
		extern _::varobj::VARS* vars_;
	}
	namespace SHORTSTREAMKEYWORDS
	{
		extern _::traceobj::TRACE* trace;
		extern _::varobj::VARS* vars;
	}
	
	void TurnBugChatOn();
	void TurnBugChatOff();
	void TurnBugOn();
	void TurnBugOff();
}

#if (BUG_STATE)

#define bug adm::ULO()
#define bugElse else adm::ULO()
#define xbugElse else adm::ULO() << "FALSE"
#define bugBool(x) #x << " = " << (x ? "TRUE" : "FALSE")
#define xbool helper::xBugBoolHelper
#define xdouble helper::xBugDoubleHelper
#define xchar helper::xBugCharHelper
#define xbugBool(x) adm::ULO() << #x << " = " << (x ? "TRUE" : "FALSE")
#define bugVar(x) #x <<" = " << x
#define xbugVar(x) adm::ULO() << #x << " = " << x
#define xbugDbl(x) adm::ULO() << #x << " = " << helper::xBugDoubleHelper << x

#define xbugBlock adm::_::objs::SCOPEBLOCK thisIsOneOfThoseReallyLongVariableNamesThatWillBeHiddenBehindAMacro = adm::_::objs::SCOPEBLOCK();
#define bugWatch adm::_::objs::SCOPEWATCH reallyLongVariableNameThatWillNeverConflictWithAnything = adm::_::objs::SCOPEWATCH()
#define xbugWatch(x) adm::_::objs::SCOPEWATCH reallyLongVariableNameThatWillNeverConflictWithAnything = adm::_::objs::SCOPEWATCH(x)
#define xbugEnd adm::ULO() << adm::STREAMKEYWORDS::trace_ << "[_END_]\n"
#define zbugWatch(x,y) adm::_::objs::SCOPEWATCH theOtherReallyLongVariableNameThatWillNeverConflictWithAnything = adm::_::objs::SCOPEWATCH(x, y)
#define xbugYesCall(x) { adm::ULO() << adm::STREAMKEYWORDS::trace_ << "{_YES_} "; x ;}
#define xbugif(x) adm::ULO() << " ?( " << #x << " )? = "; if (x)
/*	zbugif() is used where where an xbugwatch() is triggered inside the if statement. The IF signature can then be output using tbugAboveif; inside the IF body, after watch is started. */
#define zbugif(x) String hereIsAnotherOneOfThoseReallyLongVariableNames = #x; if (x)
/*	tbugAboveIf; is used with zbugif() to output the IF signature inside the IF body. */
#define tbugAboveIf adm::ULO() << adm::STREAMKEYWORDS::trace_ << "{." << hereIsAnotherOneOfThoseReallyLongVariableNames << ".}={.TRUE.} "
#define xbugdelay(x) adm::ADMdelay(x)
#define xSnoop(x) adm::ULO() << adm::STREAMKEYWORDS::vars_ << " {_" << #x "_}={_" << x << "_}="; x
#define xSnoopBool(x) adm::ULO() << adm::STREAMKEYWORDS::vars_ << " {_" << #x "_}={_" << ( x ? "TRUE" : "FALSE") << "_}="; x
#define xbugYes adm::ULO() << "YES"
#define xbugNo adm::ULO() << "NO"
#define xbugTrue adm::ULO() << "TRUE"
#define xbugFalse adm::ULO() << "FALSE"
#define xbugfor(x) adm::ULO() << adm::STREAMKEYWORDS::trace_ << " FOR(_" << #x << "_)="; for (x)

#else
#define bug adm::nLO()
#define bugElse adm::nLO()
#define bugbool(x) " "
#define xbugElse adm::nLO()
#define xbugBool(x) " "
#define xbugIf(x) if (x)

#define bugElse else adm::nLO()
#define xbugElse adm::nLO()
#define bugBool(x) " "
#define xbugBool(x) adm::nLO()
#define bugVar(x) " "
#define xbugVar(x) adm::nLO()
#define xbugDbl(x) adm::nLO()
#define bugWatch adm::nLO()
#define xbugWatch(x) adm::nLO()
#define xbugYesCall(x) x
#define xbugif(x) if (x)

#define xSnoop(x) x
#define xSnoopBool(x) x

#define xbugYes adm::nLO()
#define xbugNo adm::nLO()
#define xbugTrue adm::nLO()
#define xbugFalse adm::nLO()

#endif

#endif
