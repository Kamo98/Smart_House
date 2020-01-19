#include "Command.h"



Command::Command(IDevice *device, string function)
{
	this->device = device;
	this->function = function;
}


Command::~Command()
{
}

void Command::execute()
{
	device->execute_command(this);
}

string Command::get_function()
{
	return function;
}
