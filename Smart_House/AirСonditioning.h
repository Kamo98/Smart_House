#pragma once
#include "RealDevice.h"
class Air—onditioning :
	public RealDevice
{
private:
	int intensity;
public:
	Air—onditioning(string deviceId, int intensity);
	~Air—onditioning();
};

