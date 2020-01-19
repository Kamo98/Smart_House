#pragma once
#include "Device.h"
#include "StateDevice.h"
#include <map>
#include <string>

using namespace std;


/*
* Абстрактный класс прибор (имеет прокси ProxyAppliance)
*/
class RealDevice : public IDevice
{
protected:
	string deviceId;
	StateDevice state;						//Состояние прибора
	map<string, int> permissibleComands;	//Список допустимых функций прибора <имя ф-ии, делегат>

public:
	RealDevice(string deviceId);
	~RealDevice();

	// Унаследовано через Appliance
	//В дальнейшем эти методы станут виртуальными
	virtual int get_status() override;
	virtual void execute_command(Command *command) override;

	//Геттеры
	StateDevice get_state();

	//Сеттеры для состояния устройства
	void turn_on();
	void turn_off();
	void block();
	void unlock();
};
