#pragma once
#include "Device.h"
#include "RealDevice.h"

/*
* Прокси для контроля доступа к конкретному прибору
* Прибор может быть выключенным, заблокированным, перегруженным
* либо же вообще неопределённым
*/
class ProxyDevice : public IDevice
{
private:
	RealDevice *subject;
	
public:
	ProxyDevice();
	~ProxyDevice();

	// Унаследовано через Appliance
	virtual int get_status() override;
	virtual void execute_command(Command *command) override;
	int init_device(RealDevice* realDevice);			//Инициализация проксируемого объекта
};

