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

void Driver::accept_order(int orderId, int minutes) // shtom go priemam kato argument, predpolagam, che sistemata shte si ima orderId-to veche\
i nqma da ima smisul da go vrushtam ot taq funkciq
{
	busy = true;
} // realno sled kato accept-ne, bi trqbvalo vsichki drugi poruchki da sa izprateni kum drugi driver-i i v orders da ima samo 1 element.

void Driver::decline_order(int orderId) // da vidq v tetradkata kvo sum pisal
{
	busy = false;
	orders[orderId] = orders[orders.size() - 1];
	orders.pop_back();
}

void Driver::finish_order()
{
	busy = false;
	orders.pop_back(); //sled tozi red, bi trqbvalo v orders da nqma nishto i da e sus size 0
	//pri pay se iztriva samata poruchka, sled kato se plati, shtoto vinagi sled finish_order trqbva da se plati i taka nqma da ostane visqshta pamet
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

void Driver::showProfile(std::ostream& ofs) const
{
	Person::showProfile(ofs);
	ofs << "Phone number: " << this->phoneNum << std::endl;
	ofs << "Car number: " << this->carNum << std::endl;
	ofs << "Rating: " << getRating() << std::endl;
	ofs << this->address;
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
