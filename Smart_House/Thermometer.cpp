#include "Thermometer.h"



Thermometer::Thermometer(int val) : Sensor(val)
{
	type = TypeOfSensor::THERMOMETER;
}


Thermometer::~Thermometer()
{
}

int Thermometer::get_status()
{
	printf("������ ����������");
	return 0;
}

//void Thermometer::notify_listners()
//{
//	//�������� ���������� �������
//	Indicator *indicator = new Indicator(type, value, oldValue);
//
//	//����������� ���������� �� ��������� ���������� �������
//	for (SensorListener *sl : listeners)
//		sl->onIndicatorChange(indicator);
//}
