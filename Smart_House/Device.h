#pragma once

class Command;

class IDevice
{
public:
	virtual int get_status() = 0;
	virtual void execute_command (Command *command) = 0;
};



