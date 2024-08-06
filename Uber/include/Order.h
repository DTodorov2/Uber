#pragma once
#include <string>
#include "Address.h"

class Order
{
	bool accepted;
	std::string driverName;
	std::string carNum;
	std::string driverPhoneNum;
	static size_t idOrder;
	Address startAddress;
	Address destAddress;
	size_t passengersNum;
	int idOrderPerson; //tova nz dali mi trqq
public:
	Order();
	int getOrderId() const;
	bool isAccepted() const;
	const std::string& getDriverName() const;
	const std::string& getCarNum() const;
	const std::string& getDriverPhoneNum() const;
	const Address& getStartAddress() const;
	const Address& getDestAddress() const;
	size_t getPassengersNum() const;
	int getIdOrderPerson() const; //nz dali mi trqq vuobshte

	void setAccepted(bool isAccepted);
	void setDriverName(const std::string& driverName);
	void setCarNum(const std::string& carNum);
	void setDriverPhoneNum(const std::string& driverPhoneNum);
	void setIdOrder(int idOrder) const;
	void setStartAddress(const Address& startAddress);
	void setDestAddress(const Address& destAddress);
	void setPassengersNum(size_t passNum);
};