#include "HumidityMeter.h"



HumidityMeter::HumidityMeter(int val) : Sensor(val)
{
	type = TypeOfSensor::HUMIDITY_METER;
}


HumidityMeter::~HumidityMeter()
{
}

int HumidityMeter::get_status()
{
	printf("������ ���������� ���������");
	return 0;
}

//void HumidityMeter::notify_listners()
//{
//	Indicator *indicator = new Indicator(type, value, oldValue);
//
//	//����������� ���������� �� ��������� ���������� �������
//	for (SensorListener *sl : listeners)
//		sl->onIndicatorChange(indicator);
//}
