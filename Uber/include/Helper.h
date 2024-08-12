#pragma once
#include <iostream>
#include "Address.h"

const int MAX_LENGTH_STRING = 1024;
static int idNum = 0;

class Helper
{
public:
	static void addressInput(const std::string& str1, const std::string& str2, Address& address, char ch = 'd');
	static bool isOnlyDigits(const std::string& str);
	static size_t validateNum(const std::string& str, char constraintL, char constraintR);
};
