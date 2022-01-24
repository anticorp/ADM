#include "TLO.h"
#include "Common.h"

namespace adm
{
	namespace _
	{
		namespace traceobj
		{
			TRACE::TRACE(bool in)
			{
				Init = in;
			}
			TRACE Trace(true);
		}
	}
	TLO& TLO::operator<<(const char* _inChar)
	{
		if (_::pass::Trace)
		{
			delay(_::breathe::Trace);
			_::out::Monitor->print(_inChar);
		}
		return *this;
	}
	TLO& TLO::operator<<(const String& _inString)
	{
		if (_::pass::Trace)
		{
			delay(_::breathe::Trace);
			_::out::Monitor->print(_inString);
		}
		return *this;
	}
	TLO& TLO::operator<<(const int& _inInt)
	{
		if (_::pass::Trace)
		{
			delay(_::breathe::Trace);
			_::out::Monitor->print(_inInt);
		}
		return *this;
	}
}