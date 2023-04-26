#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include "user.h"

using namespace std;

void createAccount();
void login();

int main()
{
    cout << "Web name...." << endl;
    //creating the menu
    while(1)
    {
        string option;
        cout << endl << "Menu:" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Login" << endl;
        cout << "2. Create Account" << endl;

        cout << "Choose an option: ";
        cin >> option;
        cout << endl;

        //Exit
        if(option == "0")
        {
            cout << "Exiting program..." << endl;
            break;
        }
        //Login
        else if(option == "1")
        {
            user user;
            user::login();
        }
        //Create Account
        else if(option == "2")
        {
            user newuser;
            user::Register();
        }
        //Not an option
        else
        {
            cout << "Invalid Option. Please try again." << endl;
        }
    }
    return 0;
}

void createAccount()
{
    string newUsername, checkUsername, newPassword, confirmPassword, firstName, lastName, address, phoneNum, email, creditcardNum;
    int userSize;
    int checkPassSize;
    bool ON = true;
    bool oo = true;
    cout << "\n-----Create New Account-----\n";

    //checking if username is taken or not
    while(oo)
    {
        string choice;
        cout << "Do you want to start registering? (yes/no): ";
        cin >> choice;
        if (choice != "yes" && choice != "no" )
        {
            cout << "Invalid answer. Try again." << endl;
            cout << "Do you want to start registering? (yes/no): ";
            cin >> choice;
        }
        if(choice == "no")
        {
            main();
        }

        cout << endl;

        cout << "Username: ";
        cin >> newUsername;

        userSize = newUsername.length();
        fstream users;
        users.open("accounts.txt", ios::in);
        if(ON && userSize >= 1 && users.is_open())
        {
            string line;
            while(getline(users, line))
            {
                stringstream OnlyUsers(line);
                OnlyUsers >> checkUsername;
                if(newUsername == checkUsername)
                {
                    cout << "\n" << newUsername << " is already taken. Try another one.\n" << endl;
                    ON = false;
                }
            }
        }
        users.close();
        if(!ON)
        {
            ON = true;
        }
        else
        {
            oo = false;
        }

    }

    //Validating Password
    while(1)
    {
        cout << "Password: ";
        cin >> newPassword;

        checkPassSize = newPassword.length();
        if(checkPassSize < 7)
        {
            cout << endl << "Password is too weak, need to have a length of 7+" << endl << endl;

        }
        else
        {
            cout << "Confirm password: ";
            cin >> confirmPassword;
            if(confirmPassword == newPassword)
            {
                cout << "Enter firstname: ";
                cin >> firstName;
                cout << "Enter lastname: ";
                cin >> lastName;
                cout << "Enter email: ";
                cin >> email;
                cout << "Enter phone number: ";
                cin >> phoneNum;

                fstream users;
                users.open("accounts.txt", ios::app);
                if(users.is_open())
                {
                    users << newUsername << " " << newPassword << " " << firstName << " " << lastName << " " << email << " " << phoneNum << endl;
                    users.close();
                }
                cout << "\n=================================\n";
                cout <<"Account sucessfully created! \n";
                cout << "==================================\n";
                cout << endl;

                main();

            }
            else
            {
                cout << "\nPassword confirmation does not match. \n" << endl;
            }
        }


    }

}

void login()
{
    string choice;
    cout << "Do you want to proceed with login process? (yes/no): ";
    cin >> choice;
    if (choice != "yes" && choice != "no" )
    {
        cout << "Invalid answer. Try again." << endl;
        cout << "Do you want to proceed with login process? (yes/no): ";
        cin >> choice;
    }
    if(choice == "no")
    {
        main();
    }
    int exist;
    string logUsername, logPassword, u, p;
    cout << "Enter the username: ";
    cin >> logUsername;
    cout << "Enter the password: ";
    cin >> logPassword;
    ifstream user("accounts.txt");

    while(user>>u>>p)
    {
        if(u == logUsername && p == logPassword)
        {
            exist = 1;
        }
    }
    user.close();
    if(exist == 1)
    {
        cout << endl;
        cout << "===================" << endl;
        cout << "Login Successfully!" << endl;
        cout << "===================" << endl;
    }
    else
    {
        cout << "Login Error. Incorrect username or password." << endl;
    }


}
