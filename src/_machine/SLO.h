#pragma once

#if !defined(__ADM__SLO__h__)
	#define __ADM__SLO__h__

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

namespace adm
{
	namespace _ { namespace setobj { class SETTINGOBJECT; } }
	class SLO
	{
	public:
		SLO();
		SLO(UARTClass& _inSerial, _::setobj::SETTINGOBJECT* _inSetting);
		SLO& operator << (const int&);
		~SLO();
	private:
		_::setobj::SETTINGOBJECT* CurrentSetting = nullptr;
		bool mSettingLoaded = false;

	};

	namespace _
	{

		namespace setobj
		{
			class SETTINGOBJECT
			{
			public:
				SETTINGOBJECT() {}
				~SETTINGOBJECT() {}
				virtual bool FirstOrderSettings();
				virtual bool SecondOrderSettings();
				virtual bool ThirdOrderSettings();
				virtual bool SettingParameter(UARTClass& _inSerial);
				virtual bool SettingParameter(const int& _inInt);
				virtual bool WrapUpSettings();
			};

			class VARS : public SETTINGOBJECT
			{
			public:
				VARS(bool VarsState);
				~VARS() {}
				bool FirstOrderSettings() override;
			private:
				const bool mVarsState;
			};
			class TRACE : public SETTINGOBJECT
			{
			public:
				TRACE(bool TraceState);
				~TRACE() {}
				bool FirstOrderSettings() override;

			private:
				const bool mTraceState;
			};
			class MONITOR : public SETTINGOBJECT
			{
			public:
				MONITOR(bool);
				bool SettingParameter(UARTClass& _inSerial) override;
				bool SettingParameter(const int& _inInt) override;
				bool WrapUpSettings() override;

			private:
				bool mInit;
				UARTClass* mSerial;
				uint32_t mBaudRate;

			};
			class CHAT : public SETTINGOBJECT
			{
			public:
				CHAT(bool ChatState);
				~CHAT() {}
				bool FirstOrderSettings() override;
			private:
				const bool mChatState;
			};
			extern VARS VarsOFF;
			extern VARS VarsON;
			extern TRACE TraceOFF;
			extern TRACE TraceON;
			extern CHAT ChatOFF;
			extern CHAT ChatON;
			extern MONITOR Monitor;
		}
		extern setobj::SETTINGOBJECT* Monitor;
	}
}

#endif
