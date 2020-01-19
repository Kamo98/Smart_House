#pragma once
#include "Indicator.h"

//Интерфейс слушателей правил
class IRuleListener {
public:
	 virtual void onRuleActive(Indicator* indicator) = 0;
};