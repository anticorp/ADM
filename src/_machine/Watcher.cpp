#include "Watcher.h"
#include "Common.h"


namespace adm
{
	WATCHER::WATCHER()
	{
	}
	WATCHER& WATCHER::operator<<(_::traceobj::TRACE* _trace)
	{
		// TODO: insert return statement here
	}
	WATCHER& WATCHER::operator<<(const char*)
	{
		// TODO: insert return statement here
	}
	namespace _
	{
		namespace objs
		{
			SCOPEWATCH::SCOPEWATCH()
			{
				if (_::pass::Watch)
				{
					Active = true;
					mPrevChat = _::pass::Chat;
					mPrevTrace = _::pass::Trace;
					mPrevVars = _::pass::Vars;
					_::pass::Chat = true && _::init::Monitor;
					_::pass::Trace = true && _::init::Monitor;
					_::pass::Vars = true && _::init::Monitor;
					if (_::init::Monitor)
					{
						_::out::Monitor->print("\n\n WATCH: ");
						_::out::Monitor->print("\n {\n");
					}
				}
			}
			SCOPEWATCH::SCOPEWATCH(const String& _functionSignature)
			{
				if (_::pass::Watch)
				{
					Active = true;
					mPrevChat = _::pass::Chat;
					mPrevTrace = _::pass::Trace;
					mPrevVars = _::pass::Vars;
					mPrevDelay = _::pass::Delay;
					_::pass::Chat = true && _::init::Monitor;
					_::pass::Trace = true && _::init::Monitor;
					_::pass::Vars = true && _::init::Monitor;
					_::pass::Delay = true && _::init::Monitor;
					if (_::init::Monitor)
					{
						_::out::Monitor->print("\n\n WATCH --> \t");
						_::out::Monitor->print(_functionSignature + "( )");
						_::out::Monitor->print("\n {\n");
					}
				}
			}
			SCOPEWATCH::SCOPEWATCH(const String& _classID, const String& _functionSignature)
			{
				if (_::pass::Watch)
				{
					Active = true;
					mPrevChat = _::pass::Chat;
					mPrevTrace = _::pass::Trace;
					mPrevVars = _::pass::Vars;
					_::pass::Chat = true && _::init::Monitor;
					_::pass::Trace = true && _::init::Monitor;
					_::pass::Vars = true && _::init::Monitor;
					if (_::init::Monitor)
					{
						_::out::Monitor->print("\n\n\t WATCH --> \t" + _classID + "::" + _functionSignature + "( )" + "\t\t{\n");
					}
				}
			}
			SCOPEWATCH::~SCOPEWATCH()
			{
				if (Active)
				{
					if (_::init::Monitor) _::out::Monitor->print("\t\t };\n\n");
					_::pass::Chat = mPrevChat && _::init::Monitor;
					_::pass::Trace = mPrevTrace && _::init::Monitor;
					_::pass::Vars = mPrevVars && _::init::Monitor;
				}
			}
			SCOPEWATCH& SCOPEWATCH::operator << (const String& _FuncSignature)
			{
				mFunctionSignature = _FuncSignature;
				mFuncSigLoaded = true;
			}
			SCOPEBLOCK::SCOPEBLOCK()
			{
				if (!_::pass::ScopeBlock) return;
				mPrevChat = _::pass::Chat;
				mPrevTrace = _::pass::Trace;
				mPrevVars = _::pass::Vars;
				mPrevDelay = _::pass::Delay;
				_::pass::Chat = false;
				_::pass::Trace = false;
				_::pass::Vars = false;
				_::pass::Delay = false;
			}
			SCOPEBLOCK::~SCOPEBLOCK()
			{
				if (!_::pass::ScopeBlock) return;
				_::pass::Chat = mPrevChat && _::init::Monitor;
				_::pass::Trace = mPrevTrace && _::init::Monitor;
				_::pass::Vars = mPrevVars && _::init::Monitor;
				_::pass::Delay = mPrevDelay && _::init::Monitor;
			}
		}
	}

}
