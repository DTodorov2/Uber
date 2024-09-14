#pragma once

#include "Person.h"

class Driver : public Person
{
	std::string phoneNum;
	std::string carNum;
	bool busy;
	double rating;
	std::vector<size_t> orders;
	Address address;	

public:
	Driver() = default;
	Driver(size_t id, const std::string& username, const std::string& pass, const std::string& firstName, const std::string& secondName, const std::string& carNum, const std::string& phoneNum);
	
	void changeAddress();
	const std::vector<size_t>& check_messages() const;
	void decline_order(int id);
	void finish_order();
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
	void readPersonFromFile(std::stringstream& ss) override;
	
	void setStatus(bool isBusy);
	void setRating(int rating);
	void setAddress(const Address& newAdd);
	void setPhoneNum(const std::string& newPhoneNum);
	void setCarNum(const std::string& newCarNum);

	~Driver() = default;
};