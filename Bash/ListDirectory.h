#pragma once
#include "Comand.h"
#include <windows.h> 



class ListDirectory : public Comand
{
public:
	ListDirectory();
	~ListDirectory();
	static void listDirectory(std::string PATH);
	static void listDirectory();

};

