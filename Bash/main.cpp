#define D_SCL_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <stdio.h>
#include <io.h>
#include <direct.h>
#include <conio.h>
#include <ctype.h>
#include "NetworkInterface.h"
#include "Comands.h"
//for spliting string
//#include <boost/algorithm/string.hpp>
//for pause
#include <chrono>
#include <thread>
#include"Comand.h"
#include"ChangeDirectory.h"

using namespace std;



int main() {
	system("Color A");
	NetworkInterface* networkInterface = NetworkInterface::getInstance();
	Comands* comands = Comands::getInstance();

	std::cout << "To enter the jBASH press any key to continue" << std::endl;
	std::cout << std::endl;	
	std::cout << "List of all comands" << std::endl;
	Comands::printComands();

	//std::cout << args.at(0) <<args.at(1)<< endl;
	std::string input = "";

	while (input.compare("exit")!=0) {
		cout << Comands::GetCurrentWorkingDir() << "$>";
		getline(cin, input);
		comands->addToHistory(input);
		vector<string>* args = Comands::parseConsoleString(input);

		if (args == nullptr){
			break;
		}
		if (args->at(0).compare("cd") ==0) {
			cout << args->at(1) << endl;
			if (&args->at(1) == nullptr)
				continue;
			Comand* comand = new ChangeDirectory(args->at(0),args->at(1));
			comand->execute();
			delete comand;
		}
		else if (args->at(0).compare("ls") == 0) {
			cout << "ls" << endl;
			if (args->size() == 1){
				Comands::listDirectory();
				continue;
			}
			Comands::listDirectory(args->at(1));
		}
		else if (args->at(0).compare("cat") == 0) {
			Comands::printFile(args->at(1));
		}
		else if (args->at(0).compare("touch") == 0) {
			Comands::createFile(args->at(1));
		}
		else if (args->at(0).compare("ipaddr") == 0) {
			cout << networkInterface->GetCurrentIP()<< endl;
		}
		else if (args->at(0).compare("mkdir") == 0) {
			Comands::createDirectory(args->at(1));
		}
		else if (args->at(0).compare("clear") == 0) {
			Comands::clear();
		}
		else if (args->at(0).compare("history") == 0) {
			Comands::printHistory();
		}
		else if (args->at(0).compare("rm") == 0) {
			Comands::removeInstance(args->at(1));
		}
		else if (args->at(0).compare("df") == 0) {
			Comands::showTotal(args->at(1));
		}
		else if (args->at(0).compare("mv") == 0) {
			cout << args->at(1) << endl;
			cout << args->at(2) << endl;
			Comands::moveFile(args->at(1),args->at(2));
		}
		else if (args->at(0).compare("cp") == 0) {
			Comands::copyFile(args->at(1), args->at(2));
		}
		else if (args->at(0).compare("cp") == 0) {
			Comands::copyFile(args->at(1), args->at(2));
		}
		else if (args->at(0).compare("comands") == 0) {
			Comands::printComands();
		}
	}
	
	delete comands;
	return 0;
}