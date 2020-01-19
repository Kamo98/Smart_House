#pragma once
#include "Device.h"
#include "StateDevice.h"
#include <map>
#include <string>

using namespace std;


/*
* ����������� ����� ������ (����� ������ ProxyAppliance)
*/
class RealDevice : public IDevice
{
protected:
	string deviceId;
	StateDevice state;						//��������� �������
	map<string, int> permissibleComands;	//������ ���������� ������� ������� <��� �-��, �������>

public:
	RealDevice(string deviceId);
	~RealDevice();

	// ������������ ����� Appliance
	//� ���������� ��� ������ ������ ������������
	virtual int get_status() override;
	virtual void execute_command(Command *command) override;

	//�������
	StateDevice get_state();

	//������� ��� ��������� ����������
	void turn_on();
	void turn_off();
	void block();
	void unlock();
};
