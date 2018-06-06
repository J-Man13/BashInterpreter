#include "SecondaryComands.h"

SecondaryComands* SecondaryComands::comand;
std::vector<std::string>* SecondaryComands::comands;
std::vector<std::string>* SecondaryComands::history;

SecondaryComands::SecondaryComands() {
	comands = new std::vector<std::string>;
	history = new std::vector<std::string>;
	comands->push_back("cd");//+
	comands->push_back("ls");//+
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
	comands->push_back("comands");//+
}


SecondaryComands::~SecondaryComands() {
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


SecondaryComands* SecondaryComands::getInstance() {
	if (comand == nullptr) {
		comand = new SecondaryComands;
		return comand;
	}
	else {
		return nullptr;
	}
}


void SecondaryComands::printComands() {
	for (std::vector<std::string>::iterator it = comands->begin(); it != comands->end(); ++it)
		std::cout << *it << std::endl;
}

std::string* SecondaryComands::comandExists(std::string* comandToCheck) {
	for (std::vector<std::string>::iterator it = comands->begin(); it != comands->end(); ++it) {
		std::string temp(*it);
		if (strcmp(temp.c_str(), comandToCheck->c_str()) == 0)
			return comandToCheck;
	}
	return nullptr;
}

std::string SecondaryComands::GetCurrentWorkingDir(void) {
	char buff[FILENAME_MAX];
	_getcwd(buff, FILENAME_MAX);
	std::string current_working_dir(buff);
	return current_working_dir;
}

void SecondaryComands::addToHistory(std::string comand) {
	history->push_back(std::string(comand));
}

void SecondaryComands::printHistory() {
	for (std::vector<std::string>::iterator it = history->begin(); it != history->end(); ++it)
		std::cout << *it << std::endl;
}

void SecondaryComands::clear() {
	std::cout << std::string(100, '\n');
}

void SecondaryComands::printFile(std::string fileName) {
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

std::vector<string>* SecondaryComands::parseConsoleString(std::string str){
	std::vector<string>* vec = new std::vector<std::string>;
	vector<int>* spacesPos = new vector<int>;

	for (int i = 0, j = 1; i < str.length(); i++, j++) {
		if (str[i] == ' ') {
			spacesPos->push_back(i);
		}
	}
	if (spacesPos->size() == 0) {
		vec->push_back(str);
		return vec;
	}
	if (spacesPos->at(0) == 0) {
		delete vec;
		vec = nullptr;
		return vec;
	}
	if (spacesPos->at(spacesPos->size() - 1) == str.size() - 1) {
		delete vec;
		vec = nullptr;
		return vec;
	}
	else {
		//cd C:/
		for (int k = 0; k < spacesPos->size(); k++) {
			std::string temp = "";
			if (k == 0) {
				for (int j = 0; j < spacesPos->at(k); j++) {
					std::string superTemp(1, str[j]);
					temp.append(superTemp);
				}
				vec->push_back(temp);
			}
			else {
				for (int j = spacesPos->at(k - 1) + 1; j < spacesPos->at(k); j++) {
					std::string superTemp(1, str[j]);
					temp.append(superTemp);
				}
				vec->push_back(temp);
			}
			if (k == spacesPos->size() - 1) {
				temp = "";
				for (int j = spacesPos->at(k) + 1; j < str.length(); j++) {
					std::string superTemp(1, str[j]);
					temp.append(superTemp);
				}
				vec->push_back(temp);
			}
		}
		return vec;
	}
}


void SecondaryComands::listDirectory(std::string PATH ){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (&PATH == nullptr)
		PATH = GetCurrentWorkingDir();
	for (auto & p : fs::directory_iterator(PATH)) {
		if (checkIfDirectory(p.path().string())){
			SetConsoleTextAttribute(hConsole, 3);
		}
		std::cout << p.path().string()<<" "<<instanceSize(p.path().string()) << " bytes" << std::endl;
		SetConsoleTextAttribute(hConsole, 10);
	}
}



void SecondaryComands::listDirectory(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::string	PATH = GetCurrentWorkingDir();
	for (auto & p : fs::directory_iterator(PATH)) {
		if (checkIfDirectory(p.path().string())) {
			SetConsoleTextAttribute(hConsole, 3);
		}
		std::cout << p.path().string()<< std::endl;
		SetConsoleTextAttribute(hConsole, 10);
	}
}

bool SecondaryComands::checkIfDirectory(std::string filePath)
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

void SecondaryComands::createFile(std::string PATH) {
	std::ofstream myFile(PATH);
	myFile.close();
}


void SecondaryComands::createDirectory(std::string PATH) {
	_mkdir(PATH.c_str());
}



void SecondaryComands::moveFile(std::string target, std::string destination){
	if (MoveFile(target.c_str(), destination.c_str())) { 
		cout << "Moved" << endl;
	}
}



void SecondaryComands::copyFile(std::string target, std::string destination) {
	if (CopyFile(target.c_str(), destination.c_str(),0)) {
		cout << "Copied" << endl;
	}
}

void SecondaryComands::removeInstance(std::string PATH) {
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


unsigned long long SecondaryComands::instanceSize(std::string PATH) {
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

void SecondaryComands::showTotal(std::string PATH) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (auto & p : fs::directory_iterator(PATH)) {
		if (checkIfDirectory(p.path().string())) {
			listDirectory(p.path().string());
			showTotal(p.path().string());
		}
	}
}