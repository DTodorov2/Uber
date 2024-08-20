#pragma once

#include "Person.h"

class Driver : public Person
{
	std::string phoneNum;
	std::string carNum;
	bool busy;
	double rating;
	std::vector<size_t> orders; // pravq go taka, shtoto mnogo poveche shte dostupvam poruchkite i taka shte bude po-byrz samiqt dostup
	Address address;	

public:
	Driver(size_t id, const std::string& username, const std::string& pass, const std::string& firstName, const std::string& secondName, const std::string& carNum, const std::string& phoneNum);
	
	void changeAddress(); //promenq tekushtiq address na shofiora, kato pita za ime na adresa, i koordinati.
	const std::vector<size_t>& check_messages() const; // proverqva suobshteniqta, koito sistemata e izpratila na driver-a
	//void accept_order(int orderId, int minutes); //priema pruchka po neinoto id i do kolko minuti shte e na adresa. -> kogato prieme dadena \
	poruchka, avtomatichno vsichki drugi se preprashtat na sledvashtite nai-blizki shofiori
	void decline_order(int id); // shoforiut otkazva poruchka po podadeno id na poruchka
	void finish_order(); // tova smenq adresa mu i go pravi na svoboden.
	void addOrder(size_t idOrder);
	void removeOrder();
	void swapElementsInOrders(size_t ind1, size_t ind2);

	const std::string& getCarNum() const;
	const std::string& getPhoneNum() const;
	double getRating() const;
	std::vector<size_t> getOrders() const;
	const Address& getAddress() const;
	bool isBusy() const;
	void showProfile() const override;
	void writePersonIntoFile(std::ofstream& ofs) const override;
	
	void setStatus(bool isBusy);
	void setRating(int rating);
	void setAddress(const Address& newAdd);
	void setPhoneNum(const std::string& newPhoneNum);
	void setCarNum(const std::string& newCarNum);
};