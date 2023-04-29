#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include "user.h"

using namespace std;

//constructor; initializing everything to empty string
user::user()
{
    userID = " ";
    password = " ";
    fname = " ";
    lname = " ";
    email = " ";
    phoneNum = " ";
}

user::user(string n, string pw, string firstname, string lastname, string e, string phone)
{
    userID = n;
    password = pw;
    fname = firstname;
    lname = lastname;
    email = e;
    phoneNum = phone;
}
