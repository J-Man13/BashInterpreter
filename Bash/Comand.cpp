#include "Comand.h"

Comand::Comand(std::string lineInput){
	args = parseConsoleString(lineInput);
}


Comand::~Comand()
{
	if (args)
		delete args;
}




void Comand::execute() {
}

int	Comand::getArgsSize() {
	return args->size();
}

bool Comand::argsExist(){
	return ((args != nullptr) ? true : false);
}

std::string Comand::getArg(int index) {
	int size = args->size();
	if((index <= 0) || (index >= size))
		return std::string("");
	else
		return std::string(args->at(index));
}


std::vector<std::string>* Comand::parseConsoleString(std::string str) {
	std::vector<std::string>* vec = new std::vector<std::string>;
	std::vector<int>* spacesPos = new std::vector<int>;

	for (int i = 0 ; i < str.length() ; i++) {
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
