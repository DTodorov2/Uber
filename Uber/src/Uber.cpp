#include <iostream>
#include "../include/Client.h"

int main()
{
    Client cl = Client();
    Address ad1, ad2;
    int pass;
    cl.makeOrder(ad1, ad2, pass);
}
