#pragma once
#include "Comand.h"
#include <Windows.h>
#include <stdio.h>
//#include <tchar.h>
#define BUFSIZE MAX_PATH

class ChangeDirectory:public Comand
{
public:
	ChangeDirectory(std::string order, std::string arg) :Comand(order){
		addArg(arg);
	};
	~ChangeDirectory();
	static void changeDirectory(std::string PATH);
};

