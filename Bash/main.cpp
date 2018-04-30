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


std::vector<string> dump(std::string str) {
	std::vector<string>* vec = new std::vector<std::string>;
	vector<int>* spacesPos = new vector<int>;

	for (int i = 0, j = 1; i < str.length(); i++, j++) {
		if (str[i] == ' ') {
			spacesPos->push_back(i);
		}
		if (i != str.length() - 1) {
			if (str[i] == ' ' && str[i + 1] == ' ') {
				delete vec;
				cout << "Insuficient input" << endl;
				return *vec;
			}
		}
	}
	if (spacesPos->size() == 0) {
		vec->push_back(str);
		return *vec;
	}
	if (spacesPos->at(0) == 0) {
		delete vec;
		cout << "Insuficient input" << endl;
		return *vec;
	}
	if (spacesPos->at(spacesPos->size() - 1) == str.size() - 1) {
		delete vec;
		cout << "Insuficient input" << endl;
		return *vec;
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
		return *vec;
	}
}


int main() {
	system("Color A");
	NetworkInterface* networkInterface = NetworkInterface::getInstance();
	Comands* comands = Comands::getInstance();

	std::cout << "To enter the jBASH press any key to continue" << std::endl;
	std::cout << std::endl;
	std::cout << "List of all comands" << std::endl;
	Comands::printComands();

	cout << Comands::GetCurrentWorkingDir()<<"$";
	std::string input;
	getline(cin,input);
	comands->addToHistory(input);
	vector<string> args = dump(input);
	//std::cout << args.at(0) <<args.at(1)<< endl;

	while (input.compare("exit")!=0) {
	
		if (args.at(0).compare("cd") ==0) {
			Comand* comand = new ChangeDirectory(args.at(0),args.at(1));
			comand->execute();
			delete comand;
		}
		else if (args.at(0).compare("ls") == 0) {
			cout << "ls" << endl;
			Comands::listDirectory(args.at(1));
		}
		else if (args.at(0).compare("cat") == 0) {
			Comands::printFile(args.at(1));
		}
		else if (args.at(0).compare("touch") == 0) {
			Comands::createFile(args.at(1));
		}
		else if (args.at(0).compare("ipaddr") == 0) {
			cout << networkInterface->GetCurrentIP()<< endl;
		}
		else if (args.at(0).compare("mkdir") == 0) {
			Comands::createDirectory(args.at(1));
		}
		else if (args.at(0).compare("clear") == 0) {
			Comands::clear();
		}
		else if (args.at(0).compare("history") == 0) {
			Comands::printHistory();
		}
		else if (args.at(0).compare("rm") == 0) {
			Comands::removeInstance(args.at(1));
		}
		else if (args.at(0).compare("df") == 0) {
			Comands::showTotal(args.at(1));
		}
		else if (args.at(0).compare("mv") == 0) {
			cout << args.at(1) << endl;
			cout << args.at(2) << endl;
			Comands::moveFile(args.at(1),args.at(2));
		}
		else if (args.at(0).compare("cp") == 0) {
			Comands::copyFile(args.at(1), args.at(2));
		}
		cout << Comands::GetCurrentWorkingDir() << "$";
		getline(cin, input);
		comands->addToHistory(input);
		args = dump(input);
	}
	
	delete comands;
	//system("pause");
	return 0;
}




