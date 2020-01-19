#include "SmartLampAdapter.h"
#include <functional>
using namespace std;



SmartLampAdapter::SmartLampAdapter(string _deviceId, SmartLamp *_smartLamp) : RealDevice(_deviceId)
{
	adaptable = _smartLamp;
	/*permissibleComands["Включить лампу"] = bind(&SmartLampAdapter::turn_on, this, placeholders::_1);
	permissibleComands["Выключить лампу"] = bind(&SmartLampAdapter::turn_off, this, placeholders::_1);
	permissibleComands["Установить интенсивность освещения"] = bind(&SmartLampAdapter::set_intensity, this, placeholders::_1);
	permissibleComands["Установить цвет освещения"] = bind(&SmartLampAdapter::set_color, this, placeholders::_1);*/
}


SmartLampAdapter::~SmartLampAdapter()
{
}

//void SmartLampAdapter::execute_command(string nameOfFunction, map<string, int>& params)
//{
//}


void SmartLampAdapter::turn_on(map<string, int> & params)
{
	if (adaptable->turnOn())
		printf("Прибор \"%s\": Включение умной лампы прошло успешно\n", deviceId.c_str());
	else
		printf("Прибор \"%s\": Умная лампа УЖЕ ВКЛЮЧЕНА\n", deviceId.c_str());
}


void SmartLampAdapter::turn_off(map<string, int>& params)
{
	if (adaptable->turnOff())
		printf("Прибор \"%s\": Выключение умной лампы прошло успешно\n", deviceId.c_str());
	else
		printf("Прибор \"%s\": Умная лампа ЕЩЁ НЕ ВКЛЮЧЕНА\n", deviceId.c_str());
}


void SmartLampAdapter::set_intensity(map<string, int>& params)
{
	if (params.count("intensity") == 0) {
		printf("Прибор \"%s\": в команде ОТСУТСТВУЕТ ПАРАМЕТР \"intensivity\" ", deviceId.c_str());
		return;
	}

	adaptable->change_intensity(params["intensity"]);
	printf("Прибор \"%s\": новая интенсивность умной ламны = %d\n", deviceId.c_str(), params["intensity"]);
}


void SmartLampAdapter::set_color(map<string, int>& params)
{
	if (params.count("colorR") == 0) {
		printf("Прибор \"%s\": в команде ОТСУТСТВУЕТ ПАРАМЕТР \"colorR\" ", deviceId.c_str());
		return;
	}
	if (params.count("colorG") == 0) {
		printf("Прибор \"%s\": в команде ОТСУТСТВУЕТ ПАРАМЕТР \"colorG\" ", deviceId.c_str());
		return;
	}
	if (params.count("colorB") == 0) {
		printf("Прибор \"%s\": в команде ОТСУТСТВУЕТ ПАРАМЕТР \"colorB\" ", deviceId.c_str());
		return;
	}

	adaptable->change_color(params["colorR"], params["colorG"], params["colorB"]);
	printf("Прибор \"%s\": новый цвет умной ламны = (%d, %d, %d)\n", deviceId.c_str(), params["colorR"], params["colorG"], params["colorB"]);
}
