#pragma once
#include "RealDevice.h"
#include "SmartLamp.h"

//Адаптер для для умной лампы
class SmartLampAdapter : public RealDevice
{
private:
	SmartLamp *adaptable;
public:
	SmartLampAdapter(string _deviceId, SmartLamp *_smartLamp);
	~SmartLampAdapter();

	// Унаследовано через RealAppliance
//	virtual void execute_command(string nameOfFunction, map<string, int>& params) override;
	
private:
	void turn_on(map<string, int> & params);
	void turn_off(map<string, int>& params);
	void set_intensity(map<string, int>& params);
	void set_color(map<string, int>& params);
};

