#include "RealDevice.h"
#include "Command.h"


RealDevice::RealDevice(string deviceId)
{
	this->deviceId = deviceId;
	state = StateDevice::SWITCHED_OFF;
}


RealDevice::~RealDevice()
{
}

int RealDevice::get_status()
{
	printf("Статус реального прибора\n");
	return 0;
}

void RealDevice::execute_command(Command *command)
{
	printf("Выполнение команды %d реальным прибором\n", command->get_function());
}


StateDevice RealDevice::get_state()
{
	return state;
}


void RealDevice::turn_on()
{
	state = StateDevice::SWITCHED_ON;
}


void RealDevice::turn_off()
{
	state = StateDevice::SWITCHED_OFF;
}


void RealDevice::block()
{
	state = StateDevice::LOCKED;
}


void RealDevice::unlock()
{
	state = StateDevice::SWITCHED_ON;
}
