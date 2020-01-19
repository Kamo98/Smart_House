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
		//Список слушателей, которым будем делегировать реакцию на срабатывание правила 
	vector<IRuleListener*> listeners;		

public:
	Rule(Sensor *sensor, Command *command, int requiredValue);
	~Rule();

	bool check();		//Проверка, сработало ли прависло?
	void notify_listeners(Indicator* indicator);		//Оповестить слушателей о срабатывании правила
	void add_listener(IRuleListener* listener);			//Добавить слушаетля
	void rem_listener(IRuleListener* listener);			//Удалить слушателя
};

