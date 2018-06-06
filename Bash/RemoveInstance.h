#pragma once
#include "Comand.h"
class RemoveInstance :public Comand{

public:
	RemoveInstance(std::string LineInput);
	~RemoveInstance();
	
	void execute();
	std::vector<std::string>* parseConsoleString(std::string str);
};


