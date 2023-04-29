#include "navigation.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include "user.h"
using namespace std;

Navigation::Navigation()
{

}

void Navigation::mainmenu()
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

    m:
    //print web name
    cout << "=========================================" << endl;
    cout << "=========================================" << endl;
    cout << "   GROUP EIGHTEEN VIDEO GAME STORE       " << endl;
    cout << "=========================================" << endl;
    cout << "=========================================" << endl;

    int option;
    cout << endl << "MENU:" << endl;
    cout << "1. Exit" << endl;
    cout << "2. Login" << endl;
    cout << "3. Create Account" << endl;

    cout << "Choose an option: ";  //prompt user for an option
    cin >> option;
    cout << endl;

    switch(option)
    {
        case 1:
            {
                exit(0);
            }
        case 2:
            {
                login(users);
            }
        case 3:
            {
                createAccount(users);
            }
        default:
            {
                cout << "Invalid Option. Please try again." << endl;
            }

    }

goto m;
}

void Navigation::login(vector<user>& users)
{
    b:
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
            mainmenu(); //break from function and go back to main
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
        afterLogin();
    }
    else
    {
        cout << "Login Error. Incorrect username or password." << endl;
        goto b;
    }


}

void Navigation::createAccount(vector<user>& users)
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

                    mainmenu();

                }
                else
                {
                    cout << "\nPassword confirmation does not match. \n" << endl;
                }
            }
        }

    }


}

void Navigation::afterLogin()
{
    int choice;
    cout << "|____1) Browse Game ____|" << endl;
    cout << "|____2) View Cart ______|" << endl;
    cout << "|____3) Manage Profile _|" << endl;
    cout << "|____4) Logout__________|" << endl;

    cout << "Please select a choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            {
                cout << "Browse Game" << endl;
            }
        case 2:
            {
                cout << "View Cart" << endl;
            }
        case 3:
            {
                cout << "Manage Profile" << endl;
            }
        case 4:
            {
                mainmenu();
            }

    }
}

void Navigation::manageProfile(vector<user>& users)
{

}
