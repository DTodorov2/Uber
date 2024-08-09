#include "../include/System.h"
#include <regex>

void System::validateType(std::string& type) const
{
	while (strcmp(type.c_str(), "client") != 0 && strcmp(type.c_str(), "driver") != 0)
	{
		std::cout << "Enter type (driver or client): ";
		std::getline(std::cin, type);
	}
}

void System::validateString(const std::string& desc, std::string& str) const
{
	do {
		std::cout << "The " << desc << " must be at least 1 character!" << std::endl;
		std::cout << "Enter " << desc << ": ";
		std::getline(std::cin, str); // da proverq dali e po-dulgo ot 0 simvola
	} while (str.length() == 0);
}

void System::validatePhoneOrCarNum(const std::string& regex, const std::string& str, const std::string& which, std::string& phoneNum) const
{
	std::regex reg_exp(regex);
	do
	{
		std::cout << str << std::endl;
		std::cout << "Enter " << which << " number: ";
		std::getline(std::cin, phoneNum);
	} while (!std::regex_match(phoneNum, reg_exp));
}

void System::registårUser()
{
	std::string type;
	validateType(type);

	std::string username, pass, firstName, secondName;
	
	validateString("username", username);
	validateString("password", pass);
	validateString("first name", firstName);
	validateString("second name", secondName);

	if (strcmp(type.c_str(), "client") == 0)
	{
		Client* newClient = new Client(clients.size(), username, pass, firstName, secondName);
		clients.push_back(newClient);
	}
	else if (strcmp(type.c_str(), "driver") == 0)
	{
		std::string phoneNum, carNum;

		validatePhoneOrCarNum("^(087|088|089)[0-9]{7}$", "The phone number must be 10 digits and must start with 089/088/087!", "phone", phoneNum);
		validatePhoneOrCarNum("^[A-Z] [0-9]{4} [A-Z]{2}$", "The car number must follow the given pattern: A 0000 AA!", "car", carNum);

		Driver* driver = new Driver(drivers.size(), username, pass, firstName, secondName, carNum, phoneNum);
		drivers.push_back(driver);
	}
}

int System::login(std::string& type) const
{
	std::string username, pass;

	validateString("username", username);
	validateString("password", pass);

	size_t clientsCount = clients.size();
	for (size_t i = 0; i < clientsCount; i++)
	{
		if (strcmp(clients[i]->getUsername().c_str(), username.c_str()) == 0 && strcmp(clients[i]->getPassword().c_str(), pass.c_str()) == 0)
		{
			type = "client";
			return i;
		}
	}

	size_t driverCount = drivers.size();
	for (size_t i = 0; i < driverCount; i++)
	{
		if (strcmp(drivers[i]->getUsername().c_str(), username.c_str()) == 0 && strcmp(drivers[i]->getPassword().c_str(), pass.c_str()) == 0)
		{
			type = "driver";
			return i;
		}
	}
	return -1;
}