#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include <iterator>
#include <string>

class Comand
{
	std::vector<std::string>* args;
public:
	Comand(std::string lineInput);
	Comand();
	~Comand();
	virtual bool argsExist();
	virtual void execute();
	virtual int getArgsSize();
	virtual std::string getArg(int index);
	virtual std::vector<std::string>* parseConsoleString(std::string str);
	
};
