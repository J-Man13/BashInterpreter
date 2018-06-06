#include "ListDirectory.h"



ListDirectory::ListDirectory(std::string lineInput):Comand(lineInput)
{

}


ListDirectory::~ListDirectory()
{

}

void ListDirectory::listDirectory() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::string	PATH = GetCurrentWorkingDir();
	for (auto & p : fs::directory_iterator(PATH)) {
		if (SecondaryComands::checkIfDirectory(p.path().string())) {
			SetConsoleTextAttribute(hConsole, 3);
		}
		std::cout << p.path().string() << std::endl;
		SetConsoleTextAttribute(hConsole, 10);
	}
}

void ListDirectory::execute(){
	if (argsExist()) {
		if (getArgsSize() == 1)
			ListDirectory::listDirectory();
		else
		{
			return;
		}
	}
}


std::vector<std::string>* ListDirectory::parseConsoleString(std::string str) {
	return Comand::parseConsoleString(str);
}