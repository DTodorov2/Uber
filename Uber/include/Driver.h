#pragma once

#include "Person.h"

class Driver : public Person
{
	std::string phoneNum;
	std::string carNum;
	bool busy;
	double rating;
	std::vector<Order*> orders; // pravq go taka, shtoto shte e po-lesno smenqneto na mestata, mahaneto i dobavqneto na elementi.
	Address address;
	size_t capacity;

	//BIG 6
public:
	void changeAddress(); //promenq tekushtiq address na shofiora, kato pita za ime na adresa, i koordinati.
	void check_messages() const; // proverqva suobshteniqta, koito sistemata e izpratila na driver-a
	void accept_order(int orderId, int minutes); //priema pruchka po neinoto id i do kolko minuti shte e na adresa. -> kogato prieme dadena \
	poruchka, avtomatichno vsichki drugi se preprashtat na sledvashtite nai-blizki shofiori
	void decline_order(int id); // shoforiut otkazva poruchka po podadeno id na poruchka
	void finish_order(int id); // tova smenq adresa mu i go pravi na svoboden.

	const std::string& getCarNum() const;
	const std::string& getPhoneNum() const;
	size_t getCapacity() const;
	double getRating() const;

	void setRating(int rating);
	void setAddress(const Address& newAdd);
};