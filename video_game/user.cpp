#include "user.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>

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

