#include "Rule.h"



Rule::Rule(Sensor *sensor, Command *command, int requiredValue)
{
	this->sensor = sensor;
	this->command = command;
	this->requiredValue = requiredValue;
}


Rule::~Rule()
{
}

bool Rule::check()
{
	//Получить текущее значение показания датчика
	int curVal = sensor->get_indicator()->get_value();
	if (curVal == requiredValue) {
		//Правило сработало
		notify_listeners(sensor->get_indicator());
		return true;
	}
}

void Rule::notify_listeners(Indicator* indcator)
{
	//Пройти по всем слушателям и оповестить их о срабатывании правила
	for (IRuleListener* listener : listeners)
		listener->onRuleActive(indcator);
}

void Rule::add_listener(IRuleListener * listener)
{
	listeners.push_back(listener);
}

void Rule::rem_listener(IRuleListener * listener)
{
	auto listn = find(listeners.begin(), listeners.end(), listener);		//Найти слушателя
	listeners.erase(listn);			//Удалить слушаетеля
}
