#include "ChangeDirectory.h"




ChangeDirectory::~ChangeDirectory(){

}

void ChangeDirectory::changeDirectory(std::string PATH) {
	//std::wstring wtemp(temp.begin(), temp.end());
	//LPCWSTR path = wtemp.c_str();
	LPCSTR lpc = PATH.c_str();
	SetCurrentDirectory(lpc);
}

void Comand::execute() {
	ChangeDirectory::changeDirectory(getArg(0).c_str());
}