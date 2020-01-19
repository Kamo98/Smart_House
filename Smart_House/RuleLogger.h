#pragma once
#include "IRuleListener.h"
#include <string>
#include <fstream>
using namespace std;

class RuleLogger :
	public IRuleListener
{
private:
	string path;		//Путь к файлу логера
	ofstream stream;	//Поток для вывода логов
public:
	RuleLogger(string path);
	~RuleLogger();

	// Унаследовано через IRuleListener
	virtual void onRuleActive(Indicator * indicator) override;
};

