#include "SLO.h"
#include "Common.h"

namespace adm
{
	SLO::SLO()
	{
		//Serial.print("[ SLO() ]=");
		mSettingLoaded = false;
		CurrentSetting = nullptr;
	}
	SLO::SLO(UARTClass& _inSerial, _::setobj::SETTINGOBJECT* _inSetting)
	{
		//Serial.print("[ SLO( UART ) ]=");
		//Serial.print("{ ?NotAlreadyLoaded? }=");
		//delay(600);
		if (!mSettingLoaded)
		{
			//Serial.print("{ YES }");
			delay(1200);
			CurrentSetting = _inSetting;
			//Serial.print("{ SETTING OBJECT ASSIGNED }={ CALL: SettingParameter( UART ) }=");
			//delay(600);
			CurrentSetting->SettingParameter(_inSerial);
			mSettingLoaded = true;
		} //else Serial.print("{ NO }");
	}
	SLO& SLO::operator<<(const int& _inInt)
	{
		if (mSettingLoaded)
		{
			CurrentSetting->SettingParameter(_inInt);
		}
		return *this;
	}
	SLO::~SLO()
	{
		if (mSettingLoaded)
		{
			CurrentSetting->WrapUpSettings();
		}
	}

	namespace _
	{

		namespace setobj
		{
			VARS::VARS(bool VarsState)
				: mVarsState(VarsState)
			{
			}
			bool VARS::FirstOrderSettings()
			{	
				Serial.print("\n[ VARS]=[ FirstOrderSettings() ]={ ?init Monitor? }");
				if (_::init::Monitor)
				{
					Serial.print("{ YES }");
					_::pass::Vars = mVarsState;
					Serial.print("( pass::Vars )=( ");
					Serial.print((_::pass::Vars ? "TRUE" : "FALSE"));
				} else Serial.print("{ NO }");
				return false;	/* False if no further ordered settings */
			}
		
			TRACE::TRACE(bool TraceState)
				:	mTraceState(TraceState)
			{
			}
			bool TRACE::FirstOrderSettings()
			{
				if (_::init::Monitor)
				{
					_::pass::Trace = mTraceState;
				}
				return false;
			}
		
			bool SETTINGOBJECT::FirstOrderSettings()
			{
				Serial.print("[  virutal FirstOrderSettings( ) ]=");
				return false;
			}

			bool SETTINGOBJECT::SecondOrderSettings()
			{
				Serial.print("[  virutal SecondOrderSettings( ) ]=");
				return false;
			}
			bool SETTINGOBJECT::ThirdOrderSettings()
			{
				return false;
			}
			bool SETTINGOBJECT::SettingParameter(UARTClass& _inSerial)
			{
				//Serial.print("[  virutal SettingParameter( UART ) ]=");
				return false;
			}
			bool SETTINGOBJECT::SettingParameter(const int& _inInt)
			{
				//Serial.print("[  virutal SettingParameter( int ) ]=");

				return false;
			}
			bool SETTINGOBJECT::WrapUpSettings()
			{
				return false;
			}
		
			MONITOR::MONITOR(bool thing)
			{
				mInit = false;
				mSerial = nullptr;
				mBaudRate = 9600;
			}
			bool MONITOR::SettingParameter(UARTClass& _inSerial)
			{
				//Serial.print("\n\n[ MONITOR ]=[ SettingParameter( UART ) ]=");
				//Serial.print("{ ?NOT ALREADY mInitialized? }=");
				if (!mInit)
				{
					//Serial.print("{ YES }");
					mSerial = &_inSerial;
					return true;
				} //else  Serial.print("{ NO }");

			}
			bool MONITOR::SettingParameter(const int& _inInt)
			{
				//Serial.print("\n\n[ MONITOR ]=[ SettingParameter( int ) ]=");
				//Serial.print("{ ?NOT ALREADY mInitialized? }=");
				if (!mInit)
				{
					//Serial.print("{ YES }={ ?mSerial !=nullptr? }");
					if (mSerial != nullptr)
					{
						//Serial.print("{ YES }=( IN BAUD )=( ");
						//Serial.print(_inInt);
						//Serial.print(" )=");
						mBaudRate = _inInt;
						return false;
					}
					//Serial.print("{ No }");
				}
			}
			bool MONITOR::WrapUpSettings()
			{
				//Serial.print("[ MONITOR ]=[ WrapUpSettings() ]=");
				//Serial.print("{ ?!mInitialized? }=");
				if (!mInit)
				{
					//Serial.print("{ YES }=");
					//Serial.print("{ ?!init::Monitor? }=");
					if (!_::init::Monitor) {
						//Serial.print("{ YES }=");
						//Serial.print("{ ?init::Serial? }=");
						if (!_::init::Serial) {
							//Serial.print("{ YES }=");
							//Serial.print("{ BEGIN SERIAL }=");
							//Serial.print("{ DO TEST ON POINTER: }\n\n");
							//mSerial->print("POINTER WORKS AS SET!\n\n");
							mSerial->begin(mBaudRate);
							//delay(200);
							_::init::Serial = true;
							_::out::Monitor = mSerial;
							//Serial.print("( init::Serial )=( ");
							//Serial.print((init::Serial ? "TRUE" : "FALSE"));
							//Serial.print(" )=");
							_::out::Monitor->print("\n\n\n\nSerial Initialised By Arduino Debug Machine.\n\n");
							delay(_::breathe::StartUp);
						} 
						else
						{
							//Serial.print("{ NO }=");
							_::init::Serial = false;
						}
						_::init::Monitor = _::init::Serial;
					}
					mInit = true;
				}
				return false;	/* If ever needed. */
			}
			CHAT::CHAT(bool ChatState)
				: mChatState(ChatState)
			{
			}
			bool CHAT::FirstOrderSettings()
			{
				if (_::init::Monitor)
				{
					_::pass::Chat = mChatState;
					return false;
				}
				_::pass::Chat = false;
				return false;
			}
			VARS VarsOFF(false);
			VARS VarsON(true);
			TRACE TraceOFF(false);
			TRACE TraceON(true);
			CHAT ChatOFF(false);
			CHAT ChatON(true);
			MONITOR Monitor(true);
		}
		setobj::SETTINGOBJECT* Monitor = &setobj::Monitor;
	}
}

