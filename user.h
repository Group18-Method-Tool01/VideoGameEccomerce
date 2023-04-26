#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class user
{
private:
    string userID, password, fname, lname, email, phoneNum;

public:
    user();
    user(string n, string pw, string firstname, string lastname, string e, string phone);

    //setters
    void setUserID(string n){userID = n;}
    void setPassword(string pw){password = pw;}
    void setFirst(string firstname){fname = firstname;}
    void setLast(string lastname){lname = lastname;}
    void setEmail(string e){email = e;}
    void setPhone(string phone){phoneNum = phone;}


    //getters
    string getUserID() {return userID;}
    string getPassword() {return password;}
    string getFirst() {return fname;}
    string getLast() {return lname;}
    string getEmail() {return email;}
    string getPhone() {return phoneNum;}
   // int Register();

    void updateAccount(string n, string pw, string firstname, string lastname, string e, string phone)
    {
        userID = n;
        password = pw;
        fname = firstname;
        lname = lastname;
        email = e;
        phoneNum = phone;

    }
    void Register();
    void login();


};

#endif // USER_H
