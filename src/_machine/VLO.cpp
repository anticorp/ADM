#include "VLO.h"
#include "Common.h"
#include "ULO.h"
namespace adm
{
	VLO::VLO()
	{
	}
	VLO::~VLO()
	{
	}
	VLO& VLO::operator << (const char* _inChar)
	{
		if (_::pass::Vars)
		{
			_::out::Monitor->print(_inChar);
		}
		return *this;
	}
	VLO& VLO::operator << (const String& _inString)
	{
		if (_::pass::Vars)
		{
			_::out::Monitor->print(_inString);
		}
		return *this;
	}
	VLO& VLO::operator<<(const int inInt)
	{
		if (_::pass::Vars)
		{
			_::out::Monitor->print(inInt);
		}
		return *this;
	}
	VLO& VLO::operator << (const _::DblContainer dbl)
	{
		if (_::pass::Vars)
		{
			_::out::Monitor->print(dbl.number);
		}
		return *this;
	}
	namespace _
	{
		namespace varobj
		{
			VARS::VARS(bool nadda) : m_init(nadda) {}
			VARS Vars(true);
		}
	}
	


}