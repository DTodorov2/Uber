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

void System::validateString(const std::string& desc, std::string& str) const
{
	do {
		std::cout << "The " << desc << " must be at least 1 character!" << std::endl;
		std::cout << "Enter " << desc << ": ";
		std::getline(std::cin, str); // da proverq dali e po-dulgo ot 0 simvola
	} while (str.length() == 0);
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

int System::validateMinutesTillArrival() const
{
	std::string mins;
	std::getline(std::cin, mins);
	size_t pos;
	int num;
	while (true)
	{
		try
		{
			num = std::stoi(mins, &pos);
		}
		catch (const std::exception&)
		{
			std::cout << "Invalid Number!" << std::endl;
			continue;
		}
		if (pos != mins.length())
		{
			std::cout << "The number must not contain symbols!" << std::endl;
			continue;
		}
		break;
	}
	return num;
}

void System::registårUser()
{
	std::string type;
	validateType(type);

	std::string username, pass, firstName, secondName;

	validateString("username", username);
	validateString("password", pass);
	validateString("first name", firstName);
	validateString("second name", secondName);

	if (strcmp(type.c_str(), "client") == 0)
	{
		//Client(clients.size(), username, pass, firstName, secondName);
		clients.push_back(Client(clients.size(), username, pass, firstName, secondName));
	}
	else if (strcmp(type.c_str(), "driver") == 0)
	{
		std::string phoneNum, carNum;

		validatePhoneOrCarNum("^(087|088|089)[0-9]{7}$", "The phone number must be 10 digits and must start with 089/088/087!", "phone", phoneNum);
		validatePhoneOrCarNum("^[A-Z] [0-9]{4} [A-Z]{2}$", "The car number must follow the given pattern: A 0000 AA!", "car", carNum);

		//Driver* driver = new Driver(drivers.size(), username, pass, firstName, secondName, carNum, phoneNum);
		drivers.push_back(Driver(drivers.size(), username, pass, firstName, secondName, carNum, phoneNum));
	}
}

void System::login(std::string& type)
{
	std::string username, pass;

	validateString("username", username);
	validateString("password", pass);

	size_t clientsCount = clients.size();
	for (size_t i = 0; i < clientsCount; i++)
	{
		if (strcmp(clients[i].getUsername().c_str(), username.c_str()) == 0 && strcmp(clients[i].getPassword().c_str(), pass.c_str()) == 0)
		{
			type = "client";
			currentUserIndex = i;
			return;
		}
	}

	size_t driverCount = drivers.size();
	for (size_t i = 0; i < driverCount; i++)
	{
		if (strcmp(drivers[i].getUsername().c_str(), username.c_str()) == 0 && strcmp(drivers[i].getPassword().c_str(), pass.c_str()) == 0)
		{
			type = "driver";
			currentUserIndex = i;
			return;
		}
	}
	return;
}

double System::validateAmount() const
{
	std::string amount;
	do
	{
		std::cout << "Enter the amount of money you must pay: ";
		std::getline(std::cin, amount);

	} while (!Helper::isOnlyDigits(amount));

	return std::stod(amount);
}

void System::initiatePayment()
{
	std::string id = 0;
	std::cout << "Enter id of order you must pay for: ";
	std::getline(std::cin, id);
	while (!Helper::isOnlyDigits(id))
	{
		std::cout << "Id of order must be between 0 and " << orders.size() - 1 << std::endl;
		std::getline(std::cin, id);
	}
	int idOrder = std::stoi(id);
	double doubleAmount = validateAmount();
	clients[currentUserIndex].pay(doubleAmount);
	size_t driverBalance = orders[idOrder].getDriver()->getBalance();
	orders[idOrder].getDriver()->setBalance(driverBalance + doubleAmount);
}

void System::initiateCheckingMessages() const
{
	std::vector<size_t> vecOrders = drivers[currentUserIndex].check_messages();
	size_t orderVecLen = vecOrders.size();
	for (size_t i = 0; i < orderVecLen; i++)
	{
		std::cout << "Order number: " << vecOrders[i] << std::endl;
		std::cout << orders[vecOrders[i]].getNameOwner() << "has made an order from: " << std::endl;
		std::cout << orders[vecOrders[i]].getStartAddress().getName() << " "
				<< orders[vecOrders[i]].getStartAddress().getPoint().getCoordX() << " "
				<< orders[vecOrders[i]].getStartAddress().getPoint().getCoordY() << " "
				<< orders[vecOrders[i]].getStartAddress().getAddInfo() << std::endl;
		std::cout << "To: " << std::endl;
		std::cout << orders[vecOrders[i]].getDestAddress().getName() << " "
			<< orders[vecOrders[i]].getDestAddress().getPoint().getCoordX() << " "
			<< orders[vecOrders[i]].getDestAddress().getPoint().getCoordY() << " "
			<< orders[vecOrders[i]].getDestAddress().getAddInfo() << std::endl;
	}
}

size_t System::findFirstEmptyIndex() const
{
	size_t ordersLen = orders.size();
	for (size_t i = 0; i < ordersLen; i++)
	{
		if (orders[i].getIdOrder() == -1)
		{
			return i;
		}
	}
	return orders.size();
}

void System::showUserMessages(const std::string& type) const
{
	std::vector<std::string> vecMess;
	if (strcmp(type.c_str(), "client") == 0)
	{
		vecMess = clients[currentUserIndex].getMessages();
	}
	else
	{
		vecMess = drivers[currentUserIndex].getMessages();
	}
	size_t lenMessUser = vecMess.size();

	for (size_t i = 0; i < lenMessUser; i++)
	{
		std::cout << vecMess[i] << std::endl;
	}
}

void System::initiateMakingOrder()
{
	int numPassengers;
	Address currAddress, finalDest;
	if (clients[currentUserIndex].getOrder().getIdOrder() != -1) // trqbva da vidq kak da proverq dali imam order veche
	{
		std::cout << "You cannot make an order, while you have one in action!" << std::endl;
		return;
	}
	Helper::addressInput("Enter your current address name: ", "Enter your current coordinates:\ncoordX: ", currAddress, 'c');
	Helper::addressInput("Enter the final destination: ", "Enter the final destination coordinates:\ncoordX: ", finalDest, 'c');
	numPassengers = Helper::validateNum("Enter number of passengers (The number must be between 1 and 7): ", '1', '7');
	size_t firstEmptyIndex = findFirstEmptyIndex();
	if (firstEmptyIndex < orders.size())
	{
		orders.insert(orders.begin() + firstEmptyIndex, clients[currentUserIndex].makeOrder(currentUserIndex, firstEmptyIndex, currAddress, finalDest, numPassengers));
	}
	else
	{
		orders.push_back(clients[currentUserIndex].makeOrder(currentUserIndex, orders.size(), currAddress, finalDest, numPassengers));
	}
	sendOrderToClosestDriver(orders[firstEmptyIndex]);
	//trqbva da sloja novonapravenata poruchka v masiva na nai-blizkiq driver, kato moga da napravq funkciq, koqto da mi vrushta indexa\
	na nai-blizkiq driver
}

void System::initiateCheckingOrder() const
{
	clients[currentUserIndex].check_order();
}

void System::initiateCancelingOrder()
{
	size_t idOrder = clients[currentUserIndex].getOrder().getIdOrder();
	size_t idDriver = clients[currentUserIndex].getOrder().getDriver()->getId();
	drivers[idDriver].setStatus(false);
	drivers[idDriver].addMessage("The order has been canceled!");
	orders[idOrder].setIdOrder(-1);
	clients[currentUserIndex].cancel_order();
}

void System::initiateRate()
{
	int newRating = clients[currentUserIndex].rate();
	clients[currentUserIndex].getOrder().getDriver()->setRating(newRating);
}

void System::initateAddingMoney()
{
	clients[currentUserIndex].add_money();
}

void System::initiateChangingAddress()
{
	drivers[currentUserIndex].changeAddress();
}

void System::initiateAcceptingOrder()
{
	std::string id = 0;
	std::cout << "Enter id of order you want to accept: ";
	std::getline(std::cin, id);
	while (!Helper::isOnlyDigits(id))
	{
		std::cout << "Id of order must be between 0 and " << orders.size() - 1 << std::endl;
		std::getline(std::cin, id);
	}
	int idOrder = std::stoi(id);
	int minutes = validateMinutesTillArrival();
	orders[idOrder].setAccepted(true);
	orders[idOrder].setDriver(&drivers[currentUserIndex]);
	orders[idOrder].setMinutes(minutes);
	clients[orders[idOrder].getIdOwner()].addMessage("Your order has been accepted!");
	size_t ordersDriverLen = drivers[currentUserIndex].getOrders().size();
	for (size_t i = 0; i < ordersDriverLen; i++)
	{
		if (i != idOrder)
		{
			sendOrderToClosestDriver(orders[drivers[currentUserIndex].getOrders()[i]]);
		}
	}
}

void System::initiateDecliningOrder()
{
	std::string id = 0;
	std::cout << "Enter id of order you want to decline: ";
	std::getline(std::cin, id);
	while (!Helper::isOnlyDigits(id)) // tuka proverkata trqbva da gleda ot vectora s poruchki na konkretniq driver
	{
		std::cout << "Id of order must be between 0 and " << orders.size() - 1 << std::endl;
		std::getline(std::cin, id);
	}
	int idOrder = std::stoi(id);
	if (orders[idOrder].getDriver() == &drivers[currentUserIndex])
	{
		orders[idOrder].setAccepted(false);
		orders[idOrder].setDriver(nullptr); //tova go pravq, za da moje, ako iskame da otkajem nqkakva poruchka, koqto predi tova sme prieli\
					da q ostavim v purvonachalno sustoqnie
		orders[idOrder].setMinutes(0);
	}
	sendOrderToClosestDriver(orders[drivers[currentUserIndex].getOrders()[idOrder]]);
	//kak da napravq da se trie poruchkata, ako nikoi driver ne q e priel, a vseki q e decline-nal. -> to moje da ne trqq, shtoto kato svurshat \
	driverite shte se prati pak na sledvashtiq nai-blizuk, ama realno taka ima vuzmojnost da se poluchi zaciklqne, shtoto ako purviq e otkaje \
	shte otide kum vtoriq i ako vtoriq q otkaje, shte otide kum purviq. Trqbva da si pazq prez koi indexi e minal (mpje v unordered_set) i kato \
	broq na elementite v set-a stan raven na broq na driver-ite da se izprazva seta i da pochva otnachalo
}

void System::initiateFinishingOrder()
{
	std::string id = 0;
	std::cout << "Enter id of order you want to decline: ";
	std::getline(std::cin, id);
	while (!Helper::isOnlyDigits(id)) // tuka proverkata trqbva da gleda ot vectora s poruchki na konkretniq driver
	{
		std::cout << "Id of order must be between 0 and " << orders.size() - 1 << std::endl;
		std::getline(std::cin, id);
	}
	int idOrder = std::stoi(id);
	drivers[currentUserIndex].finish_order(idOrder);
	drivers[currentUserIndex].setAddress(orders[idOrder].getDestAddress());
	orders[idOrder].setFinished(true);
	clients[orders[idOrder].getIdOwner()].addMessage("The order is finished!");
	orders[idOrder].setIdOrder(-1); //da iztriq poruchkata na tozi index -> tova dostatuchno li e?
}