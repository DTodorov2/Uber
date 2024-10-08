#include "../include/System.h"
#include <regex>

void System::validateType(std::string& type) const
{
	while (strcmp(type.c_str(), "client") != 0 && strcmp(type.c_str(), "driver") != 0)
	{
		std::cout << "Enter type (driver or client): ";
		std::getline(std::cin, type);
	}
}
template <typename T>
bool System::isTheUsernameUniqueInCollection(const std::string& username, const std::vector<T>& collection) const
{
	size_t len = collection.size();
	for (size_t i = 0; i < len; i++)
	{
		if (collection[i].getUsername() == username.c_str())
		{
			std::cout << "This username is already taken!" << std::endl;
			return false;
		}
	}
	return true;
}

bool System::doesUsernameExist(const std::string& username) const
{
	if (!isTheUsernameUniqueInCollection(username, clients) || !isTheUsernameUniqueInCollection(username, drivers))
	{
		return false;
	}
	return true;
}


void System::validateString(const std::string& desc, std::string& str, char ch = 'c') const
{
	std::cout << "Enter " << desc << ": ";
	std::getline(std::cin, str);
	if (ch == 'u')
	{
		while (true)
		{
			std::regex reg_username("^[a-zA-Z0-9]+$");
			if (!std::regex_match(str, reg_username))
			{
				std::cout << "Enter " << desc << ": ";
				std::getline(std::cin, str);
			}
			else if (!doesUsernameExist(str))
			{
				std::cout << "Enter " << desc << ": ";
				std::getline(std::cin, str);
				continue;
			}
			break;
		}
	}
	else if (ch == 'n')
	{
		std::regex reg_name("^[a-zA-Z]+$");
		while (!std::regex_match(str, reg_name))
		{
			std::cout << "Enter " << desc << ": ";
			std::getline(std::cin, str);
		}
	}
	else if (ch == 'p')
	{
		std::regex reg_pass("^.+$");
		while (!std::regex_match(str, reg_pass))
		{
			std::cout << "Enter " << desc << ": ";
			std::getline(std::cin, str);
		}
	}
	else
	{
		while (str == "")
		{
			std::cout << "The number must be at least 1 character!" << std::endl;
			std::cout << "Enter " << desc << ": ";
			std::getline(std::cin, str);
		}
	}
}

void System::validatePhoneOrCarNum(const std::string& regex, const std::string& str, const std::string& which, std::string& phoneNum) const
{
	std::regex reg_exp(regex);
	do
	{
		std::cout << str << std::endl;
		std::cout << "Enter " << which << " number: ";
		std::getline(std::cin, phoneNum);
	} while (!std::regex_match(phoneNum, reg_exp));
}

size_t System::validateMinutesTillArrival() const
{
	std::regex min_regex("^[1-9][0-9]*$");
	std::string mins;
	std::cout << "Enter how many minutes until you arrive to the destination: ";
	std::getline(std::cin, mins);
	while (!std::regex_match(mins, min_regex))
	{
		std::cout << "The number must be greater than 0 and should not start with 0!" << std::endl;
		std::cout << "Enter minutes: ";
		std::getline(std::cin, mins);
	}
	return std::stoull(mins);
}

void System::sendOrderToClosestDriver(Order& order)
{
	size_t driversLen = drivers.size();
	int closestDriverId = -1;
	double minDistance = DBL_MAX;
	for (size_t i = 0; i < driversLen; i++)
	{
		double distanceNextDriver = order.getStartAddress().getPoint().getDist(drivers[i].getAddress().getPoint());
		if (distanceNextDriver < minDistance && order.getDriversPassed().find(i) == order.getDriversPassed().end() && !drivers[i].isBusy())
		{
			minDistance = distanceNextDriver;
			closestDriverId = i;
			order.addNumberToSet(i);
		}
	}
	if (closestDriverId == -1)
	{
		clients[order.getIdOwner()].addMessage("Your order has been declined!");
		clients[order.getIdOwner()].setOrder(Order());
		order.setIdOrder(-1);
		return;
	}
	drivers[closestDriverId].addOrder(order.getIdOrder());
}

void System::registerUser()
{
	std::string type;
	validateType(type);

	std::string username, pass, firstName, secondName;

	validateString("username", username, 'u');
	validateString("password", pass, 'p');
	validateString("first name", firstName, 'n');
	validateString("second name", secondName, 'n');

	if (type == "client")
	{
		clients.push_back(Client(clients.size(), username, pass, firstName, secondName));
		std::cout << "User successfully registered!" << std::endl;
		return;
	}
	else if (type == "driver")
	{
		std::string phoneNum, carNum;

		validatePhoneOrCarNum("^(087|088|089)[0-9]{7}$", "The phone number must be 10 digits and must start with 089/088/087!", "phone", phoneNum);
		validatePhoneOrCarNum("^[A-Z] [0-9]{4} [A-Z]{2}$", "The car number must follow the given pattern: A 0000 AA!", "car", carNum);

		drivers.push_back(Driver(drivers.size(), username, pass, firstName, secondName, carNum, phoneNum));
		std::cout << "User successfully registered!" << std::endl;
		std::cout << "You must enter your current address: " << std::endl;
		drivers[drivers.size() - 1].changeAddress();
	}
}

template <typename T>
bool System::doesUserExist(const std::vector<T>& collection, const std::string& username, const std::string& pass)
{
	size_t len = collection.size();
	for (size_t i = 0; i < len; i++)
	{
		if (collection[i].getUsername() == username && collection[i].getPassword() == pass)
		{
			currentUserIndex = i;
			std::cout << "User logged successfully!" << std::endl;
			return true;
		}
	}
	return false;
}

void System::login(std::string& type)
{
	std::string username, pass;

	validateString("username", username);
	validateString("password", pass, 'p');

	if (doesUserExist(clients, username, pass))
	{
		type = "client";
	}
	else if (doesUserExist(drivers, username, pass))
	{
		type = "driver";
	}
	else
	{
		std::cout << "Wrong username or password!" << std::endl;
	}
}

template <typename T>
void System::readInfoFromCurrentCollectionFile(const std::string& file, std::vector<T>& collection)
{
	std::ifstream readCollectionFile(file, std::ios::in);
	if (!readCollectionFile.is_open())
	{
		std::cout << "No users in the system yet!" << std::endl;
		return;
	}

	std::string currRow;
	std::getline(readCollectionFile, currRow);
	std::stringstream ss(currRow);
	size_t counter = 0;
	while (!readCollectionFile.eof())
	{
		T newEntity;
		newEntity.readPersonFromFile(ss);
		newEntity.setId(counter);
		collection.push_back(newEntity);
		counter++;
		std::getline(readCollectionFile, currRow);
		std::stringstream ss(currRow);
	}
	readCollectionFile.close();
}

void System::readInfoFromFile()
{
	readInfoFromCurrentCollectionFile("clients", clients);
	readInfoFromCurrentCollectionFile("drivers", drivers);
}

template <typename T>
void System::writeUsersFromCurrentCollectionIntoFile(const std::string& fileName, const std::vector<T>& collection) const
{
	std::ofstream newFile(fileName, std::ios::out | std::ios::trunc);
	if (!newFile.is_open())
	{
		throw std::exception("Error while opening file for writing.");
	}
	size_t len = collection.size();
	for (size_t i = 0; i < len; i++)
	{
		collection[i].writePersonIntoFile(newFile);
		newFile << std::endl;
	}
	newFile.close();
}

void System::writeInfoIntoFile() const
{
	writeUsersFromCurrentCollectionIntoFile("clients", clients);
	writeUsersFromCurrentCollectionIntoFile("drivers", drivers);
}

void System::logout(const std::string& type)
{
	deleteUserMessages(type);
	currentUserIndex = -1;
}

size_t System::findFirstEmptyIndex() const
{
	size_t lenOrders = orders.size();
	for (size_t i = 0; i < lenOrders; i++)
	{
		if (orders[i].getIdOrder() == -1)
		{
			return i;
		}
	}
	return lenOrders;
}

void System::initiatePayment()
{
	int idOrder = clients[currentUserIndex].getOrder().getIdOrder();
	double doubleAmount = 0;
	if (!clients[currentUserIndex].pay(doubleAmount))
	{
		return;
	}
	size_t driverBalance = orders[idOrder].getDriver()->getBalance();
	orders[idOrder].getDriver()->setBalance(driverBalance + doubleAmount);
	std::cout << "You have paid successfully!" << std::endl;

	orders[idOrder].setIdOrder(-1);
	initiateRate();
	clients[currentUserIndex].setOrder(Order());
}

void System::initiateCheckingMessages() const
{
	std::vector<size_t> vecOrders = drivers[currentUserIndex].check_messages();
	size_t orderVecLen = vecOrders.size();
	if (orderVecLen == 0)
	{
		std::cout << "There are no orders to see!" << std::endl;
		return;
	}
	for (size_t i = 0; i < orderVecLen; i++)
	{
		std::cout << "Order number: " << vecOrders[i] << std::endl;
		std::cout << orders[vecOrders[i]].getNameOwner() << " has made an order \nFrom: " << std::endl;
		std::cout << orders[vecOrders[i]].getStartAddress().getName() << " "
			<< orders[vecOrders[i]].getStartAddress().getPoint().getCoordX() << " "
			<< orders[vecOrders[i]].getStartAddress().getPoint().getCoordY() << " "
			<< orders[vecOrders[i]].getStartAddress().getAddInfo() << std::endl;
		std::cout << "To: " << std::endl;
		std::cout << orders[vecOrders[i]].getDestAddress().getName() << " "
			<< orders[vecOrders[i]].getDestAddress().getPoint().getCoordX() << " "
			<< orders[vecOrders[i]].getDestAddress().getPoint().getCoordY() << " "
			<< orders[vecOrders[i]].getDestAddress().getAddInfo() << std::endl;
		std::cout << std::endl;
	}
}

void System::showUserMessages(const std::string& type) const
{
	std::queue<std::string> queueMess;
	if (strcmp(type.c_str(), "client") == 0)
	{
		queueMess = clients[currentUserIndex].getMessages();
	}
	else
	{
		queueMess = drivers[currentUserIndex].getMessages();
	}
	size_t lenMessUser = queueMess.size();
	if (lenMessUser != 0)
	{
		std::cout << "\nYour messages!" << std::endl;
	}
	else
	{
		std::cout << "\nNo messages to show!" << std::endl;
		return;
	}
	for (size_t i = 0; i < lenMessUser; i++)
	{
		std::cout << queueMess.front() << std::endl;
		queueMess.pop();
	}
}

void System::deleteUserMessages(const std::string& type)
{
	std::queue<std::string> emptyVec;
	if (type == "client")
	{
		clients[currentUserIndex].setMessages(emptyVec);
	}
	else
	{
		drivers[currentUserIndex].setMessages(emptyVec);
	}
}

void System::initiateMakingOrder()
{
	int numPassengers;
	Address currAddress, finalDest;
	if (clients[currentUserIndex].getOrder().getIdOrder() != -1)
	{
		std::cout << "You cannot make an order, while you have one in action!" << std::endl;
		return;
	}
	Helper::addressInput("Enter your current address name: ", "Enter your current coordinates: ", currAddress, 'c');
	Helper::addressInput("Enter the final destination: ", "Enter the final destination coordinates: ", finalDest, 'c');
	numPassengers = Helper::validateNum("Enter number of passengers (The number must be between 1 and 7): ", '1', '7');
	size_t firstEmptyIndex = findFirstEmptyIndex();
	if (firstEmptyIndex < orders.size())
	{
		orders[firstEmptyIndex] = clients[currentUserIndex].makeOrder(currentUserIndex, firstEmptyIndex, currAddress, finalDest, numPassengers);
	}
	else
	{
		orders.push_back(clients[currentUserIndex].makeOrder(currentUserIndex, orders.size(), currAddress, finalDest, numPassengers));
	}
	std::cout << "You have made an order successfully!" << std::endl;
	sendOrderToClosestDriver(orders[firstEmptyIndex]);
}

void System::initiateCheckingOrder() const
{
	clients[currentUserIndex].checkOrder();
}

void System::removeOrderFromDrivers(size_t idOrder)
{
	size_t driversLen = drivers.size();
	for (size_t i = 0; i < driversLen; i++)
	{
		size_t currDriverLenOrders = drivers[i].getOrders().size();
		for (size_t j = 0; j < currDriverLenOrders; j++)
		{
			if (drivers[i].getOrders()[j] == idOrder)
			{
				drivers[i].swapElementsInOrders(j, currDriverLenOrders - 1);
				drivers[i].removeOrder();
				return;
			}
		}
	}
}

void System::initiateCancelingOrder()
{
	if (clients[currentUserIndex].getOrder().getIdOrder() == -1)
	{
		std::cout << "You have not ordered yet!" << std::endl;
		return;
	}
	if (clients[currentUserIndex].getOrder().isFinished() == true)
	{
		std::cout << "There is an order you need to pay for first!" << std::endl;
		return;
	}
	size_t idOrder = clients[currentUserIndex].getOrder().getIdOrder();
	removeOrderFromDrivers(idOrder);
	if (orders[idOrder].getDriver() != nullptr)
	{
		size_t idDriver = clients[currentUserIndex].getOrder().getDriver()->getId();
		drivers[idDriver].setStatus(false);
		drivers[idDriver].addMessage("The order has been canceled!");
	}
	orders[idOrder].setIdOrder(-1);
	clients[currentUserIndex].cancelOrder();
}

void System::initiateRate()
{
	std::cout << "Do you want to rate this driver - y/n?" << std::endl;
	std::cout << "Your answer: ";
	std::string answer;
	std::getline(std::cin, answer);
	while (strcmp(answer.c_str(), "y") != 0 && strcmp(answer.c_str(), "n") != 0)
	{
		std::cout << "The answer must be 'y' or 'n'!" << std::endl;
		std::getline(std::cin, answer);
	}
	if (answer[0] == 'y')
	{
		clients[currentUserIndex].getOrder().getDriver()->setRating(clients[currentUserIndex].rate());
		std::cout << "You have rated successfully!" << std::endl;
	}
}

void System::initateAddingMoney()
{
	clients[currentUserIndex].addMoney();
}

void System::initiateChangingAddress()
{
	drivers[currentUserIndex].changeAddress();
}

int System::validateOrderId() const
{
	std::string id;
	std::cout << "Enter id of order you want to accept: ";
	std::getline(std::cin, id);
	while (!Helper::isOnlyDigits(id))
	{
		std::getline(std::cin, id);
	}
	int num = std::stoi(id);
	int upperLimit = -1;
	int currDriverOrdersLen = drivers[currentUserIndex].getOrders().size();
	for (size_t i = 0; i < currDriverOrdersLen; i++)
	{
		int currOrderId = drivers[currentUserIndex].getOrders()[i];
		if (upperLimit < currOrderId)
		{
			upperLimit = currOrderId;
		}
	}
	// The last check is to check wether the order still exists
	if (num < 0 || num > upperLimit || orders[num].getIdOrder() == -1) 
	{
		num = -1;
	}
	return num;
}

void System::initiateAcceptingOrder()
{
	if (drivers[currentUserIndex].isBusy())
	{
		std::cout << "You have already accepted an order!" << std::endl;
		return;
	}
	int idOrder = validateOrderId();
	if (idOrder == -1)
	{
		std::cout << "No such order!" << std::endl;
		return;
	}
	size_t minutes = validateMinutesTillArrival();

	orders[idOrder].changeOrderStatusToAccepted(&drivers[currentUserIndex], minutes);

	clients[orders[idOrder].getIdOwner()].addMessage("Your order has been accepted!");
	clients[orders[idOrder].getIdOwner()].setOrder(orders[idOrder]);

	drivers[currentUserIndex].swapElementsInOrders(0, idOrder);
	drivers[currentUserIndex].setStatus(true);

	size_t ordersDriverLen = drivers[currentUserIndex].getOrders().size();
	for (size_t i = 1; i < ordersDriverLen; i++)
	{
		sendOrderToClosestDriver(orders[drivers[currentUserIndex].getOrders()[i]]);
		drivers[currentUserIndex].removeOrder();
	}
	std::cout << "You have accepted order with id " << idOrder << " successfully!" << std::endl;
}

void System::initiateDecliningOrder()
{
	int idOrder = validateOrderId();
	if (idOrder == -1)
	{
		std::cout << "No such order!" << std::endl;
		return;
	}
	//Do this, because I want to leave the order in the initial state if a driver has already accepted it
	if (orders[idOrder].getDriver() == &drivers[currentUserIndex]) 
	{
		orders[idOrder].changeOrderStatusToDeleted();
		drivers[currentUserIndex].setStatus(false);
	}
	sendOrderToClosestDriver(orders[drivers[currentUserIndex].getOrders()[idOrder]]);

	drivers[currentUserIndex].swapElementsInOrders(drivers[currentUserIndex].getOrders().size() - 1, idOrder);
	drivers[currentUserIndex].removeOrder();

	std::cout << "You have declined order with id " << idOrder << "successfully!" << std::endl;
}

void System::initiateFinishingOrder()
{
	size_t orderNum = 0;
	if (drivers[currentUserIndex].getOrders().size() == 0)
	{
		orderNum = -1;
	}
	if (orderNum == -1 || orders[orderNum].getDriver() != &drivers[currentUserIndex])
	{
		std::cout << "No accepted order!" << std::endl;
		return;
	}

	orderNum = drivers[currentUserIndex].getOrders()[0];
	size_t idOwnerOfOrder = orders[orderNum].getIdOwner();


	drivers[currentUserIndex].finish_order();
	drivers[currentUserIndex].setAddress(orders[orderNum].getDestAddress());

	orders[orderNum].setFinished(true);

	clients[idOwnerOfOrder].addMessage("The order is finished!");
	clients[idOwnerOfOrder].setOrder(orders[orderNum]);

	orders[orderNum].setIdOrder(-1);
	std::cout << "You have checked order with id " << orderNum << " as finished successfully!" << std::endl;
}

void System::initiateShowingProfile(char ch) const
{
	if (ch == 'c')
	{
		clients[currentUserIndex].showProfile();
	}
	else
	{
		drivers[currentUserIndex].showProfile();
	}
}


template bool System::isTheUsernameUniqueInCollection<Client>(const std::string&, const std::vector<Client>& collection) const;
template bool System::isTheUsernameUniqueInCollection<Driver>(const std::string&, const std::vector<Driver>& collection) const;

template bool System::doesUserExist<Client>(const std::vector<Client>& collection, const std::string& username, const std::string& pass);
template bool System::doesUserExist<Driver>(const std::vector<Driver>& collection, const std::string& username, const std::string& pass);

template void System::writeUsersFromCurrentCollectionIntoFile<Client>(const std::string& fileName, const std::vector<Client>& collection) const;
template void System::writeUsersFromCurrentCollectionIntoFile<Driver>(const std::string& fileName, const std::vector<Driver>& collection) const;

template void System::readInfoFromCurrentCollectionFile<Client>(const std::string& file, std::vector<Client>& collection);
template void System::readInfoFromCurrentCollectionFile<Driver>(const std::string& file, std::vector<Driver>& collection);