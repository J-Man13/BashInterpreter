#include "ListDirectory.h"



ListDirectory::ListDirectory()
{
}


ListDirectory::~ListDirectory()
{
}

void ListDirectory::listDirectory() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::string	PATH = GetCurrentWorkingDir();
	for (auto & p : fs::directory_iterator(PATH)) {
		if (checkIfDirectory(p.path().string())) {
			SetConsoleTextAttribute(hConsole, 3);
		}
		std::cout << p.path().string() << std::endl;
		SetConsoleTextAttribute(hConsole, 10);
	}
}

void ListDirectory::listDirectory(std::string PATH) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (&PATH == nullptr)
		PATH = GetCurrentWorkingDir();
	for (auto & p : fs::directory_iterator(PATH)) {
		if (checkIfDirectory(p.path().string())) {
			SetConsoleTextAttribute(hConsole, 3);
		}
		std::cout << p.path().string() << " " << instanceSize(p.path().string()) << " bytes" << std::endl;
		SetConsoleTextAttribute(hConsole, 10);
	  }
}
