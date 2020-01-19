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
	printf("Статус термометра");
	return 0;
}

//void Thermometer::notify_listners()
//{
//	//Создание показателя датчика
//	Indicator *indicator = new Indicator(type, value, oldValue);
//
//	//Опповещение слушателей об изменении показателя датчика
//	for (SensorListener *sl : listeners)
//		sl->onIndicatorChange(indicator);
//}
