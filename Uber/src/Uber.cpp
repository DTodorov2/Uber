#include <iostream>
#include "../include/System.h"

void validateOption(std::string& option, int downLimit, int upLimit)
{
	std::getline(std::cin, option);

	while ((option.length() != 1) || (option[0] - '0' <= downLimit || option[0] - '0' >= upLimit))
	{
		std::cout << "The number must be between " << downLimit + 1 << " and " << upLimit - 1 << ": ";
		std::getline(std::cin, option);

	}
}

int chooseKey(const std::string& str, int downLimit, int upLimit)
{
	std::cout << str << std::endl;

	std::cout << "Choose an option: ";
	std::string optionStr;
	validateOption(optionStr, downLimit, upLimit);
	int optionInt = optionStr[0] - '0';
	return optionInt;
}

void executeOption(System& sys, int key, std::string& type)
{
	if (strcmp(type.c_str(), "client") == 0)
	{
		switch (key)
		{
		case 1: 
			sys.initiateMakingOrder();
			break;
		case 2:
			sys.initiateCheckingOrder();
			break;
		case 3:
			sys.initiateCancelingOrder();
			break;
		case 4:
			sys.initiatePayment();
			break;
		case 5:
			sys.initateAddingMoney();
			break;
		case 6:
			sys.initiateShowingProfile();
			break;
		case 7:
			sys.showUserMessages(type);
			break;
		default:
			break;
		}
	}
	else if (strcmp(type.c_str(), "driver") == 0)
	{
		switch (key)
		{
		case 1:
			sys.initiateChangingAddress();
			break;
		case 2:
			sys.initiateCheckingMessages();
			break;
		case 3:
			sys.initiateAcceptingOrder();
			break;
		case 4:
			sys.initiateDecliningOrder();
			break;
		case 5:
			sys.initiateFinishingOrder();
			break;
		case 6:
			sys.initiateShowingProfile('d');
			break;
		case 7:
			sys.showUserMessages(type);
			break;
		default:
			break;
		}
	}
	else
	{
		switch (key)
		{
		case 1:
			sys.registerUser();
			break;
		case 2:
			sys.login(type);
			break;
		case 3:
			std::cout << "Thank you for using our platform!" << std::endl;
			sys.writeInfoIntoFile();
			exit(0);
		default:
			break;
		}
	}
	std::cout << std::endl;
	system("pause");
	system("cls");
}

int runProgram()
{
	System sys;
	sys.readInfoFromFile();
	std::string type;
	while (type == "")
	{
		int key = chooseKey(strings[2], 0, 4);
		executeOption(sys, key, type);
	}
	while (true)
	{
		int key = 0;
		if (strcmp(type.c_str(), "client") == 0)
		{
			 key = chooseKey(strings[0], 0, 9);
		}
		else
		{
			key = chooseKey(strings[1], 0, 9);
		}
		if (key == 8)
		{
			sys.logout(type);
			type = "";
			system("cls");
			while (type == "")
			{
				int key = chooseKey(strings[2], 0, 4);
				executeOption(sys, key, type);
			}
			continue;
		}
		executeOption(sys, key, type);
	}
}

int main()
{
	runProgram();
}
