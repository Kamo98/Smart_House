#pragma once
#include "RealDevice.h"
class AirŅonditioning :
	public RealDevice
{
private:
	int intensity;
public:
	AirŅonditioning(string deviceId, int intensity);
	~AirŅonditioning();
};

