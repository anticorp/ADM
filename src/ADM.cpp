/*
 Name:		ADM.cpp
 Created:	5/29/2021 4:36:37 PM
 Author:	Robert
 Editor:	http://www.visualmicro.com
*/

#include "ADM.h"

namespace adm
{
	namespace KEYWORDS
	{
		namespace set
		{
			_::setobj::SETTINGOBJECT* VarsOFF = &_::setobj::VarsOFF;
			_::setobj::SETTINGOBJECT* VarsON = &_::setobj::VarsON;
			_::setobj::SETTINGOBJECT* TraceOFF = &_::setobj::TraceOFF;
			_::setobj::SETTINGOBJECT* TraceON = &_::setobj::TraceON;
			_::setobj::SETTINGOBJECT* ChatON = &_::setobj::ChatON;
			_::setobj::SETTINGOBJECT* ChatOFF = &_::setobj::ChatOFF;
		}
	}
	namespace STREAMKEYWORDS
	{
		_::traceobj::TRACE* trace_ = &_::traceobj::Trace;
		_::varobj::VARS* vars_ = &_::varobj::Vars;
	}
	namespace SHORTSTREAMKEYWORDS
	{
		_::traceobj::TRACE* trace = &_::traceobj::Trace;
		_::varobj::VARS* vars = &_::varobj::Vars;
	}
		
	void TurnBugChatOn()
	{
		_::pass::Chat = true && _::init::Monitor;
	}
	void TurnBugChatOff()
	{
		_::pass::Chat = false;

	}
	void TurnBugOn()
	{
		_::pass::Active = true && _::init::Monitor;
		_::pass::Chat = true && _::init::Monitor;
		_::pass::Trace = true && _::init::Monitor;
		_::pass::Vars = true && _::init::Monitor;
		_::pass::Delay = true && _::init::Monitor;
		_::pass::ScopeBlock = true && _::init::Monitor;
	}
	void TurnBugOff()
	{
		_::pass::Active = false;
		_::pass::Chat = false;
		_::pass::Trace = false;
		_::pass::Vars = false;
		_::pass::Delay = false;
		_::pass::ScopeBlock = false;
	}
	
}
