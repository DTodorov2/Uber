#include "../include/Order.h"

size_t Order::idOrder = 0;

Order::Order()
{
	accepted = false;
	idOrder++;
	passengersNum = 0;
	minutesTillArrival = 0;
	finished = false;
}

//pri destruktora da namalqm idOrder s 1