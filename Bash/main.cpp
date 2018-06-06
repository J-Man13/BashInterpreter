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
#include "SecondaryComands.h"
#include <chrono>
#include <thread>
#include"Comand.h"
#include"ChangeDirectory.h"
#include"ListDirectory.h"


using namespace std;



int main() {
	system("Color A");
	NetworkInterface* networkInterface = NetworkInterface::getInstance();
	SecondaryComands* comands = SecondaryComands::getInstance();

	std::cout << "Welcome to the CMD interpreter" << std::endl;
	system("pause");
	std::cout << std::endl;	
	std::cout << "List of all comands" << std::endl;
	SecondaryComands::printComands();

	std::string input = "";

	while (input.compare("exit")!=0) {
		cout << SecondaryComands::GetCurrentWorkingDir() << "$>";
		getline(cin, input);
		Comand* comand = nullptr;

		std::string order(input.substr(0,2));
		if (order.compare("cd") ==0) {
			//if (args->size() <= 1)
			//	continue;
			comand = new ChangeDirectory(input);
			comand->execute();
		}
		else if (order.compare("ls") == 0) {
		//	if (args->size() == 1){
		//		SecondaryComands::listDirectory();
		//		continue;
		//	}
			Comand* comand = new ListDirectory(input);
			comand->execute();
			
		}
		else if (order.compare("rm") == 0){
			
		}
		//else if (order.compare("df") == 0) {
		//	if (args->size() <= 1)
		//		continue;
		//	SecondaryComands::showTotal(args->at(1));
		//}
		//else if (order.compare("mv") == 0) {
		//	if (args->size() <= 2)
		//		continue;
		//	SecondaryComands::moveFile(args->at(1),args->at(2));
		//}
		//else if (order.compare("cp") == 0) {
		//	if (args->size() <= 2)
		//		continue;
		//	SecondaryComands::copyFile(args->at(1), args->at(2));
		//}

		order = input.substr(0, 3);
		//else if (args->at(0).compare("cat") == 0) {
		//	if (args->size() <= 1)
		//		continue;
		//	SecondaryComands::printFile(args->at(1));
		//}
		//else if (args->at(0).compare("touch") == 0) {
		//	if (args->size() <= 1)
		//		continue;
		//	SecondaryComands::createFile(args->at(1));
		//}
		//else if (args->at(0).compare("ipaddr") == 0) {
		//	cout << networkInterface->GetCurrentIP()<< endl;
		//}
		//else if (args->at(0).compare("mkdir") == 0) {
		//	if (args->size() <= 1)
		//		continue;
		//	SecondaryComands::createDirectory(args->at(1));
		//}
		//else if (args->at(0).compare("clear") == 0) {
		//	SecondaryComands::clear();
		//}
		//else if (args->at(0).compare("history") == 0) {
		//	SecondaryComands::printHistory();
		//}

		//else if (args->at(0).compare("comands") == 0) {
		//	SecondaryComands::printComands();
		//}
		
		if(comand)
			delete comand;
	}
	
	delete comands;
	return 0;
}