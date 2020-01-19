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
		printf("������ �� ����� ���� �������. ������������� ���������� �� �������\n");
	else if (subject->get_state() == StateDevice::LOCKED)
		printf("������ �� ����� ���� �������. ���������� �������� �������������");
	else if (subject->get_state() == StateDevice::OVERLOAD)
		printf("������ �� ����� ���� �������. ���������� � ������ ������ �����������");
	else if (subject->get_state() == StateDevice::SWITCHED_OFF)
		printf("������ �� ����� ���� �������. ���������� � ������ ������ ���������");
	else
		return subject->get_status();
}

void ProxyDevice::execute_command(Command *command)
{
	if (subject == nullptr)
		printf("������� �� ����� ���� ���������. ������������� ���������� �� �������\n");
	else if (subject->get_state() == StateDevice::LOCKED)
		printf("������� �� ����� ���� ���������. ���������� �������� �������������");
	else if (subject->get_state() == StateDevice::OVERLOAD)
		printf("������� �� ����� ���� ���������. ���������� � ������ ������ �����������");
	else if (subject->get_state() == StateDevice::SWITCHED_OFF)
		printf("������� �� ����� ���� ���������. ���������� � ������ ������ ���������");
	else
		subject->execute_command(command);
}


int ProxyDevice::init_device(RealDevice* realAppliance)
{
	subject = realAppliance;
	return 0;
}
