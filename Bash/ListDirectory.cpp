#include "ListDirectory.h"



ListDirectory::ListDirectory(std::string lineInput):Comand(lineInput)
{

}


ListDirectory::~ListDirectory()
{

}

std::string ListDirectory::getCurrentWorkingDir() {
	char buff[FILENAME_MAX];
	_getcwd(buff,FILENAME_MAX);
	std::string current_working_dir(buff);
	return current_working_dir;
}

bool ListDirectory::checkIfDirectory(std::string filePath)
{
	try {
		// Create a Path object from given path string
		fs::path pathObj(filePath);
		// Check if path exists and is of a directory file
		if (fs::exists(pathObj) && fs::is_directory(pathObj))
			return true;
	}
	catch (fs::filesystem_error & e)
	{
		std::cout << e.what() << std::endl;
	}
	return false;
}

void ListDirectory::listDirectory() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::string	PATH = ListDirectory::getCurrentWorkingDir();
	for (auto & p : fs::directory_iterator(PATH)) {
		if (ListDirectory::checkIfDirectory(p.path().string())) {
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