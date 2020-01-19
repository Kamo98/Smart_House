#pragma once
#include "Device.h"
#include <string>
using namespace std;

class Command
{
private:
	IDevice *device;
	string function;
public:
	Command(IDevice *device, string function);
	~Command();

	void execute();
	string get_function();
};

