#include "../include/Driver.h"

Driver::Driver(size_t id, const std::string& username, const std::string& pass, const std::string& firstName, const std::string& secondName, const std::string& carNum, const std::string& phoneNum) :
	Person(id, username, pass, firstName, secondName)
{
	setCarNum(carNum);
	setPhoneNum(phoneNum);
};

void Driver::changeAddress()
{
	Helper::addressInput("Enter the new destination name: ", "Enter the new coordinates : \ncoordX: ", this->address);
}

const std::vector<size_t>& Driver::check_messages() const
{
	return orders;
}

void Driver::accept_order(int orderId, int minutes) // shtom go priemam kato argument, predpolagam, che sistemata shte si ima orderId-to veche\
i nqma da ima smisul da go vrushtam ot taq funkciq
{
	if (orderId < 1 || orderId > orders.size())
	{
		throw std::invalid_argument("Invalid orderId!");
	}
	busy = true;
} // realno sled kato accept-ne, bi trqbvalo vsichki drugi poruchki da sa izprateni kum drugi driver-i i v orders da ima samo 1 element.

void Driver::decline_order(int orderId) // da vidq v tetradkata kvo sum pisal
{
	busy = false;
	orders[orderId] = orders[orders.size() - 1];
	orders.pop_back();
}

void Driver::finish_order(int orderId)
{
	if (orderId < 1 || orderId > orders.size())
	{
		throw std::invalid_argument("Invalid orderId!");
	}
	busy = false;
	orders.pop_back(); //sled tozi red, bi trqbvalo v orders da nqma nishto i da e sus size 0
	//pri pay se iztriva samata poruchka, sled kato se plati, shtoto vinagi sled finish_order trqbva da se plati i taka nqma da ostane visqshta pamet
}

const std::string& Driver::getCarNum() const
{
	return carNum;
}

const std::string& Driver::getPhoneNum() const
{
	return phoneNum;
}

size_t Driver::getCapacity() const
{
	return capacity;
}

double Driver::getRating() const
{
	return rating;
}

void Driver::setRating(int givenRating)
{
	rating = (rating + givenRating) / 2;
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