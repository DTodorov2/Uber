#pragma once
#include "Person.h"
#include "Driver.h"
#include "Client.h"

class System
{
	std::vector<Driver*> drivers; //tuka moje i da trqbva da e Driver bez *, shtoto dostupa taka e po-lesen, a az dostup shte opravqm
	std::vector<Client*> clients; // tuka sushto kato gornoto

	void validateType(std::string& type) const;
	void validateString(const std::string& desc, std::string& str) const;
	void validatePhoneOrCarNum(const std::string& regex, const std::string& str, const std::string& which, std::string& phoneNum) const;
	//void validateCarNum(std::string& carNum) const;
	//BIG 6
public:
	void registårUser();
	int login(std::string& type) const; //vrushta int, za da moga da vzema id-to na suotevtniq potrebitel i v type zapisvam kakuv e potrebitelq\
	ako vurne -1, to nqma takuv potrebitel
	void logout() const; //tova nz oshte kvo da go praq
};