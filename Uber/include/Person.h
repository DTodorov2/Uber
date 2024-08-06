#pragma once
#include <string>
#include <vector>
#include "Order.h"
#include "GlobalConstants.h"

class Person {
	size_t id;
	std::string username;
	std::string password;
	std::string first_name;
	std::string last_name;
	std::vector<std::string> messages;
	size_t balance;
	Types type;

	//bool validateName(const std::string& str) const;

public:

	Person();
	Person(size_t id, Types type, const std::string& username, const std::string& password, const std::string& first_name, const std::string& last_name);

	void setUsername(const std::string& newUsername);
	void setPassword(const std::string& newPass);
	void setFirstName(const std::string& newFirst);
	void setLastName(const std::string& newLast);
	
	const std::string& getUsername() const;
	const std::string& getPassword() const;
	const std::string& getFirstName() const;
	const std::string& getSecondName() const;
	const std::vector<std::string>& getMessages() const; //tuka moje da trqbva i std::string da e const
	size_t getBalance() const;
	Types getType() const;
	size_t getId() const;
	void addMessage(const std::string& str);
	
	//virtual Person* clone() const = 0;
	virtual ~Person() = default;
};