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
	printf("Статус измерителя влажности");
	return 0;
}

//void HumidityMeter::notify_listners()
//{
//	Indicator *indicator = new Indicator(type, value, oldValue);
//
//	//Опповещение слушателей об изменении показателя датчика
//	for (SensorListener *sl : listeners)
//		sl->onIndicatorChange(indicator);
//}
