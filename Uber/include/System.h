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
	void validateString(const std::string& desc, std::string& str, char ch) const;
	void validatePhoneOrCarNum(const std::string& regex, const std::string& str, const std::string& which, std::string& phoneNum) const;
	size_t validateMinutesTillArrival() const;
	size_t findFirstEmptyIndex() const;
	void sendOrderToClosestDriver(Order& order);
	int validateOrderId() const;
	void removeOrderFromDrivers(size_t idOrder);

	template <typename T>
	bool isTheUsernameUniqueInCollection(const std::string& username, const std::vector<T>& collection) const;
	bool doesUsernameExist(const std::string& username) const;

	template <typename T>
	bool doesUserExist(const std::vector<T>& collection, const std::string& username, const std::string& pass);

	template <typename T>
	void readInfoFromCurrentCollectionFile(const std::string& file, std::vector<T>& collection);

	template <typename T>
	void writeUsersFromCurrentCollectionIntoFile(const std::string& fileName, const std::vector<T>& collection) const;

	void deleteUserMessages(const std::string& type);


public:
	void registårUser();
	void login(std::string& type);
	void logout(const std::string& type);
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
	void initiateShowingProfile(char ch = 'c') const;
	void showUserMessages(const std::string& type) const;
	void writeInfoIntoFile() const;
	void readInfoFromFile();
};