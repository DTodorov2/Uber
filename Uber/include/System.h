#pragma once
#include "Person.h"
#include "Driver.h"
#include "Client.h"

class System
{
	std::vector<Driver> drivers; //tuka moje i da trqbva da e Driver bez *, shtoto dostupa taka e po-lesen, a az dostup shte opravqm
	std::vector<Client> clients; // tuka sushto kato gornoto
	std::vector<Order> orders;
	int currentUserIndex = -1;

	void validateType(std::string& type) const;
	void validateString(const std::string& desc, std::string& str) const;
	void validatePhoneOrCarNum(const std::string& regex, const std::string& str, const std::string& which, std::string& phoneNum) const;
	double validateAmount() const;
	int validateMinutesTillArrival() const;
	size_t findFirstEmptyIndex() const;
	void sendOrderToClosestDriver(const Order& order);
	void showUserMessages(const std::string& type) const;

public:
	void registårUser();
	void login(std::string& type); //vrushta int, za da moga da vzema id-to na suotevtniq potrebitel i v type zapisvam kakuv e potrebitelq\
	ako vurne -1, to nqma takuv potrebitel
	void logout() const; //tova nz oshte kvo da go praq
	void initiatePayment();
	void initiateCheckingMessages() const;
	void initiateMakingOrder();
	void initiateCheckingOrder() const;
	void initiateCancelingOrder();
	void initiateRate();
	void initateAddingMoney();
	void initiateChangingAddress();
	void initiateAcceptingOrder();
	void initiateDecliningOrder();
	void initiateFinishingOrder();
};