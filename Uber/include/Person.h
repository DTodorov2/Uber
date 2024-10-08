#pragma once
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>
#include "Helper.h"

class Person {
	size_t id;
	std::string username;
	std::string password;
	std::string first_name;
	std::string last_name;
	std::queue<std::string> messages;
	size_t balance;

public:
	Person();
	Person(size_t id, const std::string& username, const std::string& password, const std::string& first_name, const std::string& last_name);

	void setUsername(const std::string& newUsername);
	void setPassword(const std::string& newPass);
	void setFirstName(const std::string& newFirst);
	void setLastName(const std::string& newLast);
	void setBalance(double amount);
	void setMessages(const std::queue<std::string>& mess);
	void setId(size_t id);
	
	const std::string& getUsername() const;
	const std::string& getPassword() const;
	const std::string& getFirstName() const;
	const std::string& getSecondName() const;
	const std::queue<std::string>& getMessages() const;
	size_t getBalance() const;
	size_t getId() const;
	void addMessage(const std::string& str);
	virtual void showProfile() const;
	virtual void writePersonIntoFile(std::ofstream& ofs) const;
	virtual void readPersonFromFile(std::stringstream& ss);
	
	virtual ~Person() = 0;
};