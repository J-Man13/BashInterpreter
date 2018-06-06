#include "ChangeDirectory.h"


ChangeDirectory::ChangeDirectory(std::string lineInput):Comand(lineInput){

}

ChangeDirectory::~ChangeDirectory(){

}

void ChangeDirectory::changeDirectory(std::string PATH) {
	//std::wstring wtemp(temp.begin(), temp.end());
	//LPCWSTR path = wtemp.c_str();
	LPCSTR lpc = PATH.c_str();
	SetCurrentDirectory(lpc);
}

void ChangeDirectory::execute() {
	if(argsExist())
		if(Comand::getArgsSize() == 2) 
			ChangeDirectory::changeDirectory(Comand::getArg(1));
}


std::vector<std::string>* ChangeDirectory::parseConsoleString(std::string str){
	return Comand::parseConsoleString(str);
}