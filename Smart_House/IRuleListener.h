#pragma once
#include "Indicator.h"

//��������� ���������� ������
class IRuleListener {
public:
	 virtual void onRuleActive(Indicator* indicator) = 0;
};