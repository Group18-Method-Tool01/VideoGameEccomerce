#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include "user.h"

using namespace std;

void createAccount(vector<user>& users);
void login(vector<user>& users);

int main()
{
    //creating a user class vector to store all the user class object
    vector<user> users;

    //parsing through text file and store everything in the vector
    ifstream openfile;
    openfile.open("accounts.txt");
    string id, pw, fn, ln, em, ph;
    while(openfile >> id >> pw >> fn >> ln >> em >>ph)
    {
        //make a user class and store all information
        user temp(id, pw, fn, ln, em, ph);

        //push the user class into the vector
        users.push_back(temp);
    }

    //print web name
    cout << "=========================================" << endl;
    cout << "=========================================" << endl;
    cout << "   GROUP EIGHTEEN VIDEO GAME STORE       " << endl;
    cout << "=========================================" << endl;
    cout << "=========================================" << endl;

    //creating and printing main menu
    while(1)
    {
        string option;
        cout << endl << "MENU:" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Login" << endl;
        cout << "2. Create Account" << endl;

        cout << "Choose an option: ";  //prompt user for an option
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

            login(users);
        }
        //Create Account
        else if(option == "2")
        {
            createAccount(users);
        }
        //Not an option
        else
        {
            cout << "Invalid Option. Please try again." << endl;
        }


    }

    return 0;
}

//create account function that utilize passed by reference to modify actual content
void createAccount(vector<user>& users)
{
    string newUsername, checkUsername, newPassword, confirmPassword, firstName, lastName, phoneNum, email;
    int checkPassSize; //int variable to store new password length to validate
    bool oo = true;
    bool valid = true; //Boolean to check if username is valid

    cout << "\n-----Create New Account-----\n";

    while(oo)
    {
        string choice;
        cout << "Do you want to start registering? (yes/no): "; //make sure user didn't choose the wrong menu option
        cin >> choice;
        if(choice != "yes" && choice != "no") //if not yes and no
        {
            cout << "Invalid answer. Try again." << endl;
            cout << "Do you want to start registeringg? (yes/no): ";
            cin >> choice;
        }
        if (choice == "no")
        {
            return; //break from function and go back to main
        }
        oo = false;
    }

    cout << endl;
    //if 'yes', continue to registration process
    cout << "Username: ";
    cin >> newUsername;

    //loop through vector<user> users and see if new username is taken already
    for(unsigned int i = 0; i < users.size(); i++)
    {
        if(users[i].getUserID() == newUsername)
        {
            cout << "\n" << newUsername << " is already taken. Try another one.\n" << endl;
            valid = false;
        }
    }

    //if username not taken
    if(valid)
    {
        //validating password
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
                    user temp(newUsername, newPassword, firstName, lastName, email, phoneNum);
                    users.push_back(temp);

                    //write the contents in the file
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


}

void login(vector<user>& users)
{
    bool oo = true;
    while(oo)
    {
        string choice;
        cout << "Do you want to continue logging in? (yes/no): "; //make sure user didn't choose the wrong menu option
        cin >> choice;
        if(choice != "yes" && choice != "no") //if not yes and no
        {
            cout << "Invalid answer. Try again." << endl;
            cout << "Do you want to continue logging in? (yes/no): ";
            cin >> choice;
        }
        if (choice == "no")
        {
            return; //break from function and go back to main
        }
        oo = false;
    }
    int exist;
    string logUsername, logPassword, userFirst;
    cout << "Enter the username: ";
    cin >> logUsername;
    cout << "Enter the password: ";
    cin >> logPassword;

    //loop through users vector and see if there is a matching user
    for(unsigned int i = 0; i < users.size(); i++)
    {
        if(users[i].getUserID() == logUsername && users[i].getPassword() == logPassword)
        {
            userFirst = users[i].getFirst();
            exist = 1;
        }
    }

    if(exist == 1)
    {
        cout << endl;
        cout << "Logging in...";
        cout << endl;
        cout << "===================" << endl;
        cout << "Welcome " << userFirst << endl;
        cout << "===================" << endl;
    }
    else
    {
        cout << "Login Error. Incorrect username or password." << endl;
    }


}
