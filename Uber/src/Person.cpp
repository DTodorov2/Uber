#include "../include/Person.h"

Person::Person(size_t id, Types type, const std::string& username, const std::string& password, const std::string& first_name, const std::string& last_name)
{
	setFirstName(first_name);
	setLastName(last_name);
	setPassword(password);
	setUsername(username);
	this->id = id;
	this->type = type;
	balance = 0;
}

Person::Person() : Person(0, Types::person, "", "", "", "") {};

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

//Types Person::getType() const
//{
//	return type;
//}

size_t Person::getBalance() const
{
	return balance;
}

const std::vector<std::string>& Person::getMessages() const
{
	return messages;
}