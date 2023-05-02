#include "cart.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>

//constructor
Cart::Cart()
{
    item = " ";
    totals;
}

Cart::Cart(string i, float t)
{
    item = i;
    totals = t;
}