#pragma once
#include <string>
#include "Address.h"
#include "Driver.h"

class Order
{
	bool accepted, finished;
	Driver* driver; // shte sochi kum driver-a, koito e priel poruchkata, ne iskam da kopiram neshtata postoqnno
	//size_t idOrder;
	Address startAddress;
	Address destAddress;
	size_t passengersNum;
	size_t minutesTillArrival;
	std::string nameOwner;
	int idOwner = -1; //trqq da e -1, shtoto taka proverqvam v klienta dali imam napravena poruchka
	int idOrder = -1;
	//BIG 6?
public:
	Order();
	Order(size_t idOwner, size_t id, const Address& startAdd, const Address& finalAdd, size_t numPass, const std::string& nameOrderPerson);
	Order(const Order& other);

	size_t getIdOrder() const;
	bool isAccepted() const;
	bool isFinished() const;
	double getDriverRating() const;
	const Address& getStartAddress() const;
	const Address& getDestAddress() const;
	size_t getPassengersNum() const;
	const std::string& getNameOwner() const;
	size_t getMinutesTillArrival() const;
	Driver* getDriver() const;
	size_t getIdOwner() const;

	void setAccepted(bool isAccepted);
	void setFinished(bool isFinished);
	void setMinutes(int minutes);
	void setDriver(Driver* driver);
	//void setIdOrder(int idOrder);
	void setAddress(const Address& newAddress, Address& AddressToChange);
	void setPassengersNum(size_t passNum);
	void setIdOrder(int id);
};