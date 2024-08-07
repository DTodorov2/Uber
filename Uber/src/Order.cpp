#include "../include/Order.h"

size_t Order::idOrder = 0;

Order::Order()
{
	accepted = false;
	//idOrder++; da vidq dali trqq go praq tuka ili ne
	passengersNum = 0;
	minutesTillArrival = 0;
	finished = false;
}

Order::Order(const Address& startAdd, const Address& finalAdd, size_t numPass, const std::string& nameOrderPerson) : Order()
{
	idOrder++;
	setDriverName(nameOrderPerson);
	setAddress(startAdd, this->startAddress);
	setAddress(finalAdd, this->destAddress);
	setPassengersNum(numPass);
}

//pri destruktora da namalqm idOrder s 1