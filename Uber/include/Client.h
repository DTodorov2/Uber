#pragma once

#include "Person.h"
#include "Order.h"
//#include "Address.h"

class Client : public Person
{
	Order order; //trqbva li da triq tozi pointer pri iztrivane na obekta

	size_t validateNum(const std::string& str, char constraintL, char constraintR) const;
public:
	Client() = default;
	Client(size_t id, const std::string& username, const std::string& pass, const std::string& firstName, const std::string& secondName);
	Order makeOrder(Address& CurrAddress, Address& finalDest, int& numPassengers) const; // prashta se na shofiora, koito e nai-blizko po adres \
	kato ne moje da se prati na zaet shofior.
	void check_order() const; //proverqva segashnata mi poruchka
	void cancel_order(); //cancel-va negovata si poruchka. Edin potrebitel shte moje da pravi samo edna poruchka ednovremenno.
	void pay(double amount); //plashta na shofiora SLED kato e otbelqzal poruchkata za izpulnena.
	int rate() const; //rate-va shofiora, koito e izpulnin poruchkata, kato pri zavurshvane se zadava vupros kum potrebitelq dali iska da dade \
	ocenka, ako kaje da, to se vzema id-to na shofiora ot order-a i se dava ocenka, ako ne - produljava se deistvieto na programata.
	void add_money(); //dobavq pari kum balance-a si.

	void changeOrderStatus(bool isFinished);
};