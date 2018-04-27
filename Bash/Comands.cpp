#include "Comands.h"

Comands* Comands::comand;
std::vector<std::string>* Comands::comands;
std::vector<std::string>* Comands::history;

Comands::Comands() {
	comands = new std::vector<std::string>;
	history = new std::vector<std::string>;
	comands->push_back("cd");//+
	comands->push_back("ls");//+
	comands->push_back("pwd");//+
	comands->push_back("cat");//+
	comands->push_back("touch");//+
	comands->push_back("ipaddr");//+
	comands->push_back("mkdir");//+
	comands->push_back("clear");//+
	comands->push_back("history");//+
	comands->push_back("rm");//+
	comands->push_back("mv");//+
	comands->push_back("cp");//+
	comands->push_back("df");//+
	comands->push_back("exit");//+
	//comands->push_back("grep");//
}

Comands::~Comands() {
	if (comands) {
		delete comands;
		comands = NULL;
	}
	if (history) {
		delete history;
		comands = NULL;
	}
	if (comand) {
		delete comand;
		comand = NULL;
	}
}


Comands* Comands::getInstance() {
	if (comand == nullptr) {
		comand = new Comands;
		return comand;
	}
	else {
		return nullptr;
	}
}


void Comands::printComands() {
	for (std::vector<std::string>::iterator it = comands->begin(); it != comands->end(); ++it)
		std::cout << *it << std::endl;
}

std::string* Comands::comandExists(std::string* comandToCheck) {
	for (std::vector<std::string>::iterator it = comands->begin(); it != comands->end(); ++it) {
		std::string temp(*it);
		if (strcmp(temp.c_str(), comandToCheck->c_str()) == 0)
			return comandToCheck;
	}
	cout << "Invalid commands" << endl;
	return nullptr;
}

std::string Comands::GetCurrentWorkingDir(void) {
	char buff[FILENAME_MAX];
	GetCurrentDir(buff, FILENAME_MAX);
	std::string current_working_dir(buff);
	return current_working_dir;
}

void Comands::changeDirectory(std::string PATH) {
	
	//std::wstring wtemp(temp.begin(), temp.end());
	//LPCWSTR path = wtemp.c_str();
	LPCSTR lpc = PATH.c_str();
	SetCurrentDirectory(lpc);

}

void Comands::addToHistory(std::string comand) {
	history->push_back(std::string(comand));
}

void Comands::printHistory() {
	for (std::vector<std::string>::iterator it = history->begin(); it != history->end(); ++it)
		std::cout << *it << std::endl;
}

void Comands::clear() {
	std::cout << std::string(50, '\n');
}

void Comands::printFile(std::string fileName) {
	std::fstream f;
	f.open(fileName.c_str(), std::ios_base::in);
	if (f.good()){
		std::string tmp;
		while (!f.eof()) {
			f >> tmp;
			std::cout << tmp << "\t";
			f >> tmp;
			std::cout << tmp << std::endl;
		}
	}
	else {	
		std::cout << "Error occured or file does not exist" << std::endl;
	}
}

void Comands::listDirectory(std::string PATH ) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (auto & p : fs::directory_iterator(PATH)) {
		if (checkIfDirectory(p.path().string())){
			SetConsoleTextAttribute(hConsole, 3);
		}
		std::cout << p.path().string()<<" "<<instanceSize(p.path().string()) << " bytes" << std::endl;
		SetConsoleTextAttribute(hConsole, 10);
	}

}



bool Comands::checkIfDirectory(std::string filePath)
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

void Comands::createFile(std::string PATH) {
	std::ofstream myFile(PATH);
	myFile.close();
}


void Comands::createDirectory(std::string PATH) {
	_mkdir(PATH.c_str());
}



void Comands::moveFile(std::string target, std::string destination){
	if (MoveFile(target.c_str(), destination.c_str())) { 
		cout << "Moved" << endl;
	}
}



void Comands::copyFile(std::string target, std::string destination) {
	if (CopyFile(target.c_str(), destination.c_str(),0)) {
		cout << "Copied" << endl;
	}
}

void Comands::removeInstance(std::string PATH) {
	if (checkIfDirectory(PATH)) {
		for (auto & p : fs::directory_iterator(PATH)) {
			removeInstance(p.path().string());
		}
		RemoveDirectory(PATH.c_str());
	}
	else {
		DeleteFile(PATH.c_str());
	}
}


unsigned long long Comands::instanceSize(std::string PATH) {
	if (checkIfDirectory(PATH)){
		//cout << PATH << endl;
		unsigned long long totalSize = 0;
		std::vector<std::string>* listPath = new std::vector<std::string>;

		for (auto & p : fs::directory_iterator(PATH)) {
			listPath->push_back(p.path().string());
		}
	
		for (std::vector<std::string>::iterator it = listPath->begin(); it != listPath->end(); ++it){
			unsigned long long res = instanceSize(*it);
			
			totalSize += res;
		}
		delete listPath;
		return totalSize;
	}
	else {
		struct stat stat_buf;
		unsigned long long rc = stat(PATH.c_str(), &stat_buf);
		return rc == 0 ? stat_buf.st_size : -1;
	}

}

void Comands::showTotal(std::string PATH) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (auto & p : fs::directory_iterator(PATH)) {
		if (checkIfDirectory(p.path().string())) {
			listDirectory(p.path().string());
			showTotal(p.path().string());
		}
	}
}