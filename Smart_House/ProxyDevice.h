#pragma once
#include "Device.h"
#include "RealDevice.h"

/*
* ������ ��� �������� ������� � ����������� �������
* ������ ����� ���� �����������, ���������������, �������������
* ���� �� ������ �������������
*/
class ProxyDevice : public IDevice
{
private:
	RealDevice *subject;
	
public:
	ProxyDevice();
	~ProxyDevice();

	// ������������ ����� Appliance
	virtual int get_status() override;
	virtual void execute_command(Command *command) override;
	int init_device(RealDevice* realDevice);			//������������� ������������� �������
};

