#include "../include/Person.h"

Person::Person(size_t id, const std::string& username, const std::string& password, const std::string& first_name, const std::string& last_name)
{
	setFirstName(first_name);
	setLastName(last_name);
	setPassword(password);
	setUsername(username);
	this->id = id;
	balance = 0;
}

Person::Person() : Person(0, "", "", "", "") {};

void Person::setFirstName(const std::string& firstName)
{
	first_name = firstName;
}

void Person::setLastName(const std::string& lastName)
{
	last_name = lastName;
}

void Person::setPassword(const std::string& newPass)
{
	password = newPass;
}

void Person::setUsername(const std::string& username)
{
	this->username = username;
}

void Person::setBalance(double amount)
{
	this->balance = amount;
}

void Person::setMessages(const std::queue<std::string>& mess)
{
	messages = mess;
}

void Person::addMessage(const std::string& str)
{
	messages.push(str);
}

const std::string& Person::getFirstName() const
{
	return first_name;
}

const std::string& Person::getSecondName() const
{
	return last_name;
}

const std::string& Person::getPassword() const
{
	return password;
}

const std::string& Person::getUsername() const
{
	return username;
}

size_t Person::getId() const
{
	return id;
}

size_t Person::getBalance() const
{
	return balance;
}

const std::queue<std::string>& Person::getMessages() const
{
	return messages;
}

void Person::writePersonIntoFile(std::ofstream& ofs) const
{
	ofs << getUsername() << "," << getFirstName() << "," << getSecondName() << "," << getBalance();
}

void Person::showProfile() const
{
	std::cout << "\nUsername: " << getUsername() << std::endl;
	std::cout << "First name: " << getFirstName() << std::endl;
	std::cout << "Last name: " << getSecondName() << std::endl;
	std::cout << "Balance: " << getBalance() << std::endl;
}