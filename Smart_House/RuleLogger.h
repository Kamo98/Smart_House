#pragma once
#include "IRuleListener.h"
#include <string>
#include <fstream>
using namespace std;

class RuleLogger :
	public IRuleListener
{
private:
	string path;		//���� � ����� ������
	ofstream stream;	//����� ��� ������ �����
public:
	RuleLogger(string path);
	~RuleLogger();

	// ������������ ����� IRuleListener
	virtual void onRuleActive(Indicator * indicator) override;
};

