#include "Sensor.h"



Sensor::Sensor(int val)
{
	type = TypeOfSensor::UNDEFINED;		//Сенсор неопредленного типа
	value = val;
}


Sensor::~Sensor()
{
}


void Sensor::set_value(int newVal)
{
	oldValue = value;
	value = newVal;
}


int Sensor::get_value()
{
	return value;
}


TypeOfSensor Sensor::get_type()
{
	return type;
}

Indicator* Sensor::get_indicator()
{
	return new Indicator(type, value, oldValue);
}
