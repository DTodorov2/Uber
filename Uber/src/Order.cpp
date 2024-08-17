#include "../include/Order.h"

Order::Order()
{
	accepted = false;
	passengersNum = 0;
	minutesTillArrival = 0;
	finished = false;
	driver = nullptr;
}

Order::Order(size_t idOwner, size_t id, const Address& startAdd, const Address& finalAdd, size_t numPass, const std::string& nameOrderPerson) : Order()
{
	this->idOwner = idOwner;
	this->idOrder = id;
	this->nameOwner = nameOrderPerson;
	setAddress(startAdd, this->startAddress);
	setAddress(finalAdd, this->destAddress);
	setPassengersNum(numPass);
}

void Order::setFinished(bool isFinished)
{
	finished = isFinished;
}

void Order::setPassengersNum(size_t passNum)
{
	passengersNum = passNum;
}

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

size_t Order::getIdOrder() const
{
	return idOrder;
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

size_t Order::getIdOwner() const
{
	return idOwner;
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

void Order::setIdOrder(int idOrder)
{
	this->idOrder = idOrder;
}

void Order::setAddress(const Address& newAddress, Address& AddressToChange)
{
	AddressToChange = newAddress;
}

void Order::addNumberToSet(int num)
{
	driversPassed.insert(num);
}

const std::unordered_set<int>& Order::getDriversPassed() const
{
	return driversPassed;
}