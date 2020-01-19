#pragma once
#include "StateDevice.h"
#include "TypeOfSensor.h"
#include "Indicator.h"
#include <vector>

using namespace std;


class Sensor
{
protected:
	StateDevice state;
	TypeOfSensor type;
	int oldValue;
	int value;
public:
	Sensor(int val);
	~Sensor();
	virtual int get_status() = 0;


	void set_value(int newVal);						//��������� ������ �������� ���������� �������
	int get_value();
	TypeOfSensor get_type();
	Indicator* get_indicator();			//������ ���������� �������
};

