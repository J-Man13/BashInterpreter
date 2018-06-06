#pragma once
#include "Comand.h"
#include <Windows.h>
#include <stdio.h>
//#include <tchar.h>
#define BUFSIZE MAX_PATH

class ChangeDirectory:public Comand
{
public:
	ChangeDirectory(std::string lineInput);
	~ChangeDirectory();
	 static void changeDirectory(std::string PATH);
	 void execute();
	 std::vector<std::string>* parseConsoleString(std::string str);
};

