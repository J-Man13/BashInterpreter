#include "Comand.h"


Comand::Comand(std::string order){
	comandsToExecute = Comands::getInstance();
	args = new std::vector<std::string>;
	setOrder(order);
}


Comand::~Comand()
{
	if (comandsToExecute)
		delete comandsToExecute;
	if (args)
		delete args;
	if (order)
		delete order;
}


std::string Comand::getOrder(){
	return std::string(*this->order);
}

void Comand::setOrder(std::string order) {
	this->order = new std::string(order);
}

void Comand::addArg(std::string arg) {
	args->push_back(arg);
}

std::string Comand::getArg(int index) {
	return args->at(index);
}
