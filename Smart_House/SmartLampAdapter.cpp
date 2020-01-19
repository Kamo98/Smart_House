#include "SmartLampAdapter.h"
#include <functional>
using namespace std;



SmartLampAdapter::SmartLampAdapter(string _deviceId, SmartLamp *_smartLamp) : RealDevice(_deviceId)
{
	adaptable = _smartLamp;
	/*permissibleComands["�������� �����"] = bind(&SmartLampAdapter::turn_on, this, placeholders::_1);
	permissibleComands["��������� �����"] = bind(&SmartLampAdapter::turn_off, this, placeholders::_1);
	permissibleComands["���������� ������������� ���������"] = bind(&SmartLampAdapter::set_intensity, this, placeholders::_1);
	permissibleComands["���������� ���� ���������"] = bind(&SmartLampAdapter::set_color, this, placeholders::_1);*/
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
		printf("������ \"%s\": ��������� ����� ����� ������ �������\n", deviceId.c_str());
	else
		printf("������ \"%s\": ����� ����� ��� ��������\n", deviceId.c_str());
}


void SmartLampAdapter::turn_off(map<string, int>& params)
{
	if (adaptable->turnOff())
		printf("������ \"%s\": ���������� ����� ����� ������ �������\n", deviceId.c_str());
	else
		printf("������ \"%s\": ����� ����� �٨ �� ��������\n", deviceId.c_str());
}


void SmartLampAdapter::set_intensity(map<string, int>& params)
{
	if (params.count("intensity") == 0) {
		printf("������ \"%s\": � ������� ����������� �������� \"intensivity\" ", deviceId.c_str());
		return;
	}

	adaptable->change_intensity(params["intensity"]);
	printf("������ \"%s\": ����� ������������� ����� ����� = %d\n", deviceId.c_str(), params["intensity"]);
}


void SmartLampAdapter::set_color(map<string, int>& params)
{
	if (params.count("colorR") == 0) {
		printf("������ \"%s\": � ������� ����������� �������� \"colorR\" ", deviceId.c_str());
		return;
	}
	if (params.count("colorG") == 0) {
		printf("������ \"%s\": � ������� ����������� �������� \"colorG\" ", deviceId.c_str());
		return;
	}
	if (params.count("colorB") == 0) {
		printf("������ \"%s\": � ������� ����������� �������� \"colorB\" ", deviceId.c_str());
		return;
	}

	adaptable->change_color(params["colorR"], params["colorG"], params["colorB"]);
	printf("������ \"%s\": ����� ���� ����� ����� = (%d, %d, %d)\n", deviceId.c_str(), params["colorR"], params["colorG"], params["colorB"]);
}
