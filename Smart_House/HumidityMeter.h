#pragma once
#include "Sensor.h"
class HumidityMeter : public Sensor
{
public:
	HumidityMeter(int val);
	~HumidityMeter();

	// ������������ ����� Sensor
	virtual int get_status() override;

	// ������������ ����� Sensor
//	virtual void notify_listners() override;
};

