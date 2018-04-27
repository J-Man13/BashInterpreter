#include "ChangeDirectory.h"




ChangeDirectory::~ChangeDirectory(){

}

void Comand::execute() {
	Comands::changeDirectory(getArg(0).c_str());
}