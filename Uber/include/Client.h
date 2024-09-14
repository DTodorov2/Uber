#pragma once

#include "Person.h"
#include "Order.h"

class Client : public Person
{
	Order order;

	double validateAmount() const;
public:
	Client() = default;
	Client(size_t id, const std::string& username, const std::string& pass, const std::string& firstName, const std::string& secondName);
	Order makeOrder(size_t idOwner, size_t id, Address& CurrAddress, Address& finalDest, int& numPassengers); 
	void checkOrder() const;
	void cancelOrder();
	bool pay(double& doubleAmount);
	int rate() const; 
	void addMoney();

	void setOrder(const Order& order);

	const Order& getOrder() const;
	~Client() = default;
};