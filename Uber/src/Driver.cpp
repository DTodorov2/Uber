#include "../include/Driver.h"

Driver::Driver(size_t id, const std::string& username, const std::string& pass, const std::string& firstName, const std::string& secondName, const std::string& carNum, const std::string& phoneNum) :
	Person(id, username, pass, firstName, secondName)
{
	setCarNum(carNum);
	setPhoneNum(phoneNum);
	rating = -1;
	busy = false;
};

void Driver::addOrder(size_t idOrder)
{
	orders.push_back(idOrder);
}

const Address& Driver::getAddress() const
{
	return address;
}

void Driver::changeAddress()
{
	Helper::addressInput("Enter the destination name: ", "Enter the coordinates : ", this->address);
}

const std::vector<size_t>& Driver::check_messages() const
{
	return orders;
}

void Driver::decline_order(int orderId)
{
	busy = false;
	orders[orderId] = orders[orders.size() - 1];
	orders.pop_back();
}

void Driver::finish_order()
{
	busy = false;
	orders.pop_back(); 
}

void Driver::swapElementsInOrders(size_t ind1, size_t ind2)
{
	size_t indexOrder = 0;
	size_t ordersLen = orders.size();
	for (size_t i = 0; i < ordersLen; i++)
	{
		if (orders[i] == ind2)
		{
			indexOrder = i;
			break;
		}
	}
	std::swap(orders[0], orders[indexOrder]);
}

const std::string& Driver::getCarNum() const
{
	return carNum;
}

const std::string& Driver::getPhoneNum() const
{
	return phoneNum;
}

bool Driver::isBusy() const
{
	return busy;
}

void Driver::readPersonFromFile(std::stringstream& ss)
{
	Person::readPersonFromFile(ss);
	std::string currInfo, coordY;
	std::getline(ss, currInfo, ',');
	this->phoneNum = currInfo;
	std::getline(ss, currInfo, ',');
	this->carNum = currInfo;
	std::getline(ss, currInfo, ',');
	this->rating = std::stod(currInfo);
	std::getline(ss, currInfo, ',');
	this->address.setName(currInfo);
	std::getline(ss, currInfo, ',');
	std::getline(ss, coordY, ',');
	this->address.setPoint(std::stoi(currInfo), std::stoi(coordY));
}

void Driver::writePersonIntoFile(std::ofstream& ofs) const
{
	Person::writePersonIntoFile(ofs);
	ofs << this->phoneNum << "," << this->carNum << "," << getRating();
	address.writeAddressIntoFile(ofs);
}

void Driver::showProfile() const
{
	Person::showProfile();
	std::cout << "Phone number: " << this->phoneNum << std::endl;
	std::cout << "Car number: " << this->carNum << std::endl;
	std::cout << "Rating: " << getRating() << std::endl;
	std::cout << this->address;
}

double Driver::getRating() const
{
	if (rating == -1)
	{
		return 0;
	}
	return rating;
}

void Driver::setRating(int givenRating)
{
	if (rating == -1)
	{
		rating = givenRating;
	}
	else
	{
		rating = (rating + givenRating) / 2;
	}
}

void Driver::setAddress(const Address& newAdd)
{
	address = newAdd;
}

void Driver::setCarNum(const std::string& carNum)
{
	this->carNum = carNum;
}

void Driver::setPhoneNum(const std::string& phoneNum)
{
	this->phoneNum = phoneNum;
}

void Driver::setStatus(bool isBusy)
{
	busy = isBusy;
}

std::vector<size_t> Driver::getOrders() const
{
	return orders;
}

void Driver::removeOrder()
{
	orders.pop_back();
}
