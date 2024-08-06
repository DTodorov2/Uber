#pragma once
#include "Driver.h"

class Order
{
	bool accepted = false;
	Driver* driver = nullptr;
	int idOrder = -1;
	Address startAddress;
	Address destAddress;
	size_t passengersNum = 0;
	int idOrderPerson = -1; //tova nz dali mi trqq
public:
	Order() = default;
	int getOrderId() const;
};