#pragma once
#include "Sensor.h"
#include "Command.h"
#include "IRuleListener.h"

class Rule
{
private:
	Sensor *sensor;
	Command *command;
	int requiredValue;
		//������ ����������, ������� ����� ������������ ������� �� ������������ ������� 
	vector<IRuleListener*> listeners;		

public:
	Rule(Sensor *sensor, Command *command, int requiredValue);
	~Rule();

	bool check();		//��������, ��������� �� ��������?
	void notify_listeners(Indicator* indicator);		//���������� ���������� � ������������ �������
	void add_listener(IRuleListener* listener);			//�������� ���������
	void rem_listener(IRuleListener* listener);			//������� ���������
};

