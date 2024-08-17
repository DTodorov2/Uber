#pragma once
#include <iostream>
#include <vector>
#include "Address.h"

const int MAX_LENGTH_STRING = 1024;
static int idNum = 0;

const std::vector<std::string> strings = {
	"-------------------\n1 - Make an order\n2 - Check your order\n3 - Cancel your order\n4 - Pay\n5 - Add money to your balance\n6 - View profile\n7 - Show my messages\n8 - Logout\n-------------------",
	"-------------------\n1 - Change your address\n2 - Check your orders\n3 - Accept order\n4 - Decline order\n5 - Finish order\n6 - View profile\n7 - Show my messages\n8 - Logout\n-------------------",
	"-------------------\nYou must register or login first\n1 - Register\n2 - Login\n3 - Exit\n-------------------"
};

class Helper
{
	static void validateCoordinate(const std::string& coord, double& coordinateNum, std::string& coordinateString);
public:
	static void addressInput(const std::string& str1, const std::string& str2, Address& address, char ch = 'd');
	static bool isOnlyDigits(const std::string& str);
	static size_t validateNum(const std::string& str, char constraintL, char constraintR);
};
