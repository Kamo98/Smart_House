#pragma once
#include "Sensor.h"
class Thermometer : public Sensor
{
public:
	Thermometer(int val);
	~Thermometer();

	// Унаследовано через Sensor
	virtual int get_status() override;

	// Унаследовано через Sensor
//	virtual void notify_listners() override;
};

