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
	static size_t idOrder;
	Address startAddress;
	Address destAddress;
	size_t passengersNum;
	size_t minutesTillArrival;
	int idOrderPerson; //tova nz dali mi trqq
public:
	Order();
	int getOrderId() const;
	bool isAccepted() const;
	bool isFinished() const;
	//const std::string& getDriverName() const;
	//const std::string& getCarNum() const;
	//const std::string& getDriverPhoneNum() const;
	double getDriverRating() const;
	const Address& getStartAddress() const;
	const Address& getDestAddress() const;
	size_t getPassengersNum() const;
	int getIdOrderPerson() const; //nz dali mi trqq vuobshte
	size_t getMinutesTillArrival() const;
	const Driver* getDriver() const;

	void setAccepted(bool isAccepted);
	void setDriverName(const std::string& driverName);
	void setCarNum(const std::string& carNum);
	void setDriverPhoneNum(const std::string& driverPhoneNum);
	void setIdOrder(int idOrder) const;
	void setStartAddress(const Address& startAddress);
	void setDestAddress(const Address& destAddress);
	void setPassengersNum(size_t passNum);
};