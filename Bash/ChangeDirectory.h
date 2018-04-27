#pragma once
#include "Comand.h"
class ChangeDirectory:public Comand
{
public:
	ChangeDirectory(std::string order, std::string arg) :Comand(order){
		addArg(arg);
	};
	~ChangeDirectory();
};

