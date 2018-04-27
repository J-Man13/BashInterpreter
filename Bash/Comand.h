#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<string>
#include "Comands.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <iterator>

class Comand
{
	Comands* comandsToExecute;
	std::vector<std::string>* args;
public:

	Comand(std::string order);
	~Comand();
	std::string* order;
	virtual void execute();
	virtual std::string getOrder();
	virtual void setOrder(std::string order);
	virtual void addArg(std::string arg);
	virtual std::string getArg(int index);
};

