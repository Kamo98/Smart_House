#pragma once
#include "Sensor.h"
class Thermometer : public Sensor
{
public:
	Thermometer(int val);
	~Thermometer();

	// ������������ ����� Sensor
	virtual int get_status() override;

	// ������������ ����� Sensor
//	virtual void notify_listners() override;
};

