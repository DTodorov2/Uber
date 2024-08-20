#include "../include/Client.h"
#include <sstream>

Client::Client(size_t id, const std::string& username, const std::string& pass, const std::string& firstName, const std::string& secondName) :
	Person(id, username, pass, firstName, secondName) {};

const Order& Client::getOrder() const
{
	return order;
}

Order Client::makeOrder(size_t idOwner, size_t id, Address& currAddress, Address& finalDest, int& numPassengers)
{
	std::string personName = getFirstName() + " " + getSecondName();
	this->order = Order(idOwner, id, currAddress, finalDest, numPassengers, personName);
	return this->order; // RVO?
}

void Client::check_order() const
{
	if (order.getIdOrder() == -1)
	{
		std::cout << "You have not ordered yet!" << std::endl;
		return;
	}
	std::cout << "Your order is ";
	if (order.isAccepted())
	{
		std::cout << "accepted!" << std::endl;
	}
	else
	{
		std::cout << "not accepted yet!" << std::endl;
		return;
	}
	std::cout << "Your driver's name: " << order.getDriver()->getFirstName() << " " << order.getDriver()->getSecondName() << std::endl;
	std::cout << "The car number is: " << order.getDriver()->getCarNum() << std::endl;
	std::cout << "The driver's phone number is: " << order.getDriver()->getPhoneNum() << std::endl;
	std::cout << "The driver's rating is: " << order.getDriver()->getRating() << std::endl;
}

void Client::cancel_order()
{
	order = Order();
	std::cout << "You have canceled your order successfully!" << std::endl;
}

double Client::validateAmount() const
{
	double num;
	while (true)
	{
		std::cout << "The amount must me positive number and greater than 0!" << std::endl;
		std::string amount;
		std::cout << "Enter amount of money: ";
		std::getline(std::cin, amount);
		std::stringstream ss(amount);
		char c;

		if (!(ss >> num)) {
			continue;
		}

		if (ss >> c) {
			continue;
		}

		if (num <= 0)
		{
			continue;
		}
		break;
	}
	return num;
}

bool Client::pay(double& doubleAmount) //pay se griji za plashtaneto na driver-a
{
	if (order.getIdOrder() == -1)
	{
		std::cout << "You have not ordered yet!" << std::endl;
		return false;
	}
	if (order.getDriver() == nullptr)
	{
		std::cout << "Your order is not accepted yet!" << std::endl;
		return false;
	}
	doubleAmount = validateAmount();
	if (order.isFinished())
	{
		double newBalance = getBalance() - doubleAmount;
		if (newBalance < 0)
		{
			std::cout << "You must add money to your balance first!" << std::endl;
			return false;
		}
		setBalance(newBalance);
	}
	else
	{
		std::cout << "You must wait for the driver to assure the order is finished." << std::endl;
		return false;
	}
	return true;
}

int Client::rate() const
{
	std::string rating;
	std::cout << "Your rating must be between 1 and 5!" << std::endl;
	return Helper::validateNum("Choose your rating: ", '1', '5');
}

void Client::add_money()
{
	std::cout << "\nYour current balance is: " << getBalance() << std::endl;
	std::cout << "\nEnter the amount of money you want to add to your balance: " << std::endl;;
	double amount = validateAmount();
	double newBalance = getBalance() + amount;
	setBalance(newBalance);
	std::cout << "You added money to your account successfully!" << std::endl;
	std::cout << "\nThe new balance is: " << getBalance() << std::endl;
	std::cout << std::endl;
}

void Client::setOrder(const Order& order)
{
	this->order = order;
}

