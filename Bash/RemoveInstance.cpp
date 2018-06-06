#include "RemoveInstance.h"


RemoveInstance::RemoveInstance(std::string lineInput):Comand(lineInput)
{


}


RemoveInstance::~RemoveInstance()
{
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


void RemoveInstance::execute() {
	Comand::execute();
}

std::vector<std::string>* RemoveInstance :: parseConsoleString(std::string str) {
	return Comand::parseConsoleString(str);
}