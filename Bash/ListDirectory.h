#pragma once
#include "Comand.h"
#include <windows.h> 
#include <stdio.h>
//#include"SecondaryComands.h"
//for directory list
#include<experimental/filesystem>
namespace fs = std::experimental::filesystem;

class ListDirectory : public Comand
{
public:
	ListDirectory(std::string lineInput);
	~ListDirectory();
	static void listDirectory();
	void execute();
	std::vector<std::string>* parseConsoleString(std::string str);
};
