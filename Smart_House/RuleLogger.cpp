#include "RuleLogger.h"



RuleLogger::RuleLogger(string path)
{
	this->path = path;
	stream = ofstream(path);
}


RuleLogger::~RuleLogger()
{
}

void RuleLogger::onRuleActive(Indicator * indicator)
{
	stream << indicator->get_value() << endl;;
}
