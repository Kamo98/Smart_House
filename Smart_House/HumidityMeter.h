#pragma once
#include "Sensor.h"
class HumidityMeter : public Sensor
{
public:
	HumidityMeter(int val);
	~HumidityMeter();

	// Унаследовано через Sensor
	virtual int get_status() override;

	// Унаследовано через Sensor
//	virtual void notify_listners() override;
};

