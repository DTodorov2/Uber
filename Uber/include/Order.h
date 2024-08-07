#pragma once
#include <string>
#include "Address.h"
#include "Driver.h"

class Order
{
	bool accepted, finished;
	//std::string driverName;
	//std::string carNum;
	//std::string driverPhoneNum;
	Driver* driver; // shte sochi kum driver-a, koito e priel poruchkata, ne iskam da kopiram neshtata postoqnno
	size_t idOrder;
	Address startAddress;
	Address destAddress;
	size_t passengersNum;
	size_t minutesTillArrival;
	std::string nameOrderPerson;
	//int idOrderPerson; //tova nz dali mi trqq
	//BIG 6?
public:
	Order();
	Order(const Address& startAdd, const Address& finalAdd, size_t numPass, const std::string& nameOrderPerson);
	Order(const Order& other);
	int getOrderId() const;
	bool isAccepted() const;
	bool isFinished() const;
	double getDriverRating() const;
	const Address& getStartAddress() const;
	const Address& getDestAddress() const;
	size_t getPassengersNum() const;
	const std::string& getNameOrderPerson() const;
	//int getIdOrderPerson() const; //nz dali mi trqq vuobshte
	size_t getMinutesTillArrival() const;
	Driver* getDriver() const;

	void setAccepted(bool isAccepted);
	//void setDriverName(const std::string& driverName);
	//void setCarNum(const std::string& carNum);
	//void setDriverPhoneNum(const std::string& driverPhoneNum);
	void setMinutes(int minutes);
	void setDriver(const Driver* driver);
	void setIdOrder(int idOrder) const;
	void setAddress(const Address& newAddress, Address& AddressToChange);
	//void setDestAddress(const Address& destAddress);
	void setPassengersNum(size_t passNum);
};