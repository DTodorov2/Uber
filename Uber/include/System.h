#pragma once
#include "Person.h"
#include "Driver.h"
#include "Client.h"

class System
{
	std::vector<Driver*> drivers; //tuka moje i da trqbva da e Driver bez *, shtoto dostupa taka e po-lesen, a az dostup shte opravqm
	std::vector<Client*> clients; // tuka sushto kato gornoto
public:
	void regist�rUser();
	void login() const;
	void logout() const;
};