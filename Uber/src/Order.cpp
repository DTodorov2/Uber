#include "../include/Order.h"

//size_t Order::idOrder = 0;

Order::Order()
{
	accepted = false;
	passengersNum = 0;
	minutesTillArrival = 0;
	finished = false;
}

Order::Order(size_t idOwner, size_t id, const Address& startAdd, const Address& finalAdd, size_t numPass, const std::string& nameOrderPerson) : Order()
{
	this->idOwner = idOwner;
	this->idOrder = id;
	setAddress(startAdd, this->startAddress);
	setAddress(finalAdd, this->destAddress);
	setPassengersNum(numPass);
}

//int Order::getOrderId() const
//{
//	return idOrder;
//}

bool Order::isAccepted() const
{
	return accepted;
}

bool Order::isFinished() const
{
	return finished;
}

double Order::getDriverRating() const
{
	return driver->getRating();
}

const Address& Order::getStartAddress() const
{
	return startAddress;
}

const Address& Order::getDestAddress() const
{
	return destAddress;
}

size_t Order::getPassengersNum() const
{
	return passengersNum;
}

const std::string& Order::getNameOwner() const
{
	return nameOwner;
}

size_t Order::getMinutesTillArrival() const
{
	return minutesTillArrival;
}

Driver* Order::getDriver() const
{
	return driver;
}

void Order::setAccepted(bool isAccepted)
{
	accepted = isAccepted;
}

void Order::setMinutes(int minutes)
{
	minutesTillArrival = minutes;
}

void Order::setDriver(Driver* driver)
{
	this->driver = driver;
}

//void Order::setIdOrder(int idOrder)
//{
//	this->idOrder = idOrder;
//}
void Order::setAddress(const Address& newAddress, Address& AddressToChange)
{
	AddressToChange = newAddress;
}

void Order::setPassengersNum(size_t passNum)
{
	this->passengersNum = passNum;
}

//pri destruktora da namalqm idOrder s 1, ako go polzvam vuobshte