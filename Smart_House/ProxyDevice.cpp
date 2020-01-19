#include "ProxyDevice.h"



ProxyDevice::ProxyDevice()
{
	subject = nullptr;
}


ProxyDevice::~ProxyDevice()
{
	delete subject;
	subject = nullptr;
}

int ProxyDevice::get_status()
{
	if (subject == nullptr)
		printf("Статус не может быть получен. Запрашиваемое устройство не создано\n");
	else if (subject->get_state() == StateDevice::LOCKED)
		printf("Статус не может быть получен. Устройство временно заблокировано");
	else if (subject->get_state() == StateDevice::OVERLOAD)
		printf("Статус не может быть получен. Устройство в данный момент перегружено");
	else if (subject->get_state() == StateDevice::SWITCHED_OFF)
		printf("Статус не может быть получен. Устройство в данный момент выключено");
	else
		return subject->get_status();
}

void ProxyDevice::execute_command(Command *command)
{
	if (subject == nullptr)
		printf("Команда не может быть выполнена. Запрашиваемое устройство не создано\n");
	else if (subject->get_state() == StateDevice::LOCKED)
		printf("Команда не может быть выполнена. Устройство временно заблокировано");
	else if (subject->get_state() == StateDevice::OVERLOAD)
		printf("Команда не может быть выполнена. Устройство в данный момент перегружено");
	else if (subject->get_state() == StateDevice::SWITCHED_OFF)
		printf("Команда не может быть выполнена. Устройство в данный момент выключено");
	else
		subject->execute_command(command);
}


int ProxyDevice::init_device(RealDevice* realAppliance)
{
	subject = realAppliance;
	return 0;
}
