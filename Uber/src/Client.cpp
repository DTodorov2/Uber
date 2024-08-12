#include "../include/Client.h"

Client::Client(size_t id, const std::string& username, const std::string& pass, const std::string& firstName, const std::string& secondName) :
	Person(id, username, pass, firstName, secondName) {};

//size_t Client::validateNum(const std::string& str, char constraintL, char constraintR) const
//{
//	std::string passengers;
//	do
//	{
//		std::cout << str;
//		std::getline(std::cin, passengers);
//		if (passengers.size() >= 2)
//		{
//			continue;
//		}
//	} while (passengers[0] < constraintL || passengers[0] > constraintR);
//	return passengers[0] - '0';
//}

Order Client::makeOrder(size_t idOwner, size_t id, Address& currAddress, Address& finalDest, int& numPassengers)
{
	this->order = Order(idOwner, id, currAddress, finalDest, numPassengers, getFirstName() + " " + getSecondName());
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
}

void Client::pay(double amount) //pay se griji za plashtaneto na driver-a
{
	if (order.isFinished())
	{
		double newBalance = getBalance() - amount;
		if (newBalance < 0)
		{
			std::cout << "You must add money to your balance first!" << std::endl;
			return;
		}
		setBalance(newBalance);
	}
	else
	{
		std::cout << "You must wait for the driver to assure the order is finished." << std::endl;
	}
}

int Client::rate() const
{
	std::string rating;
	std::cout << "Your rating must be between 1 and 5!" << std::endl;
	return Helper::validateNum("Choose your rating: ", '1', '5');
}

void Client::add_money()
{
	std::string amount;
	std::cout << "Enter the amount of money you want to add to your balance: ";
	std::getline(std::cin, amount);
	try
	{
		size_t pos;
		setBalance(getBalance() + std::stod(amount, &pos));
		if (pos < amount.length())
		{
			throw std::invalid_argument("");
		}
	}
	catch (const std::exception&)
	{
		std::cout << "The amount must contain only digits!" << std::endl;
		add_money();
	}
}