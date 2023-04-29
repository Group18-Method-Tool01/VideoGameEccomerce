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
    cout << endl;
    cout << "=========================================" << endl;
    cout << "=========================================" << endl;
    cout << "   GROUP EIGHTEEN VIDEO GAME STORE       " << endl;
    cout << "=========================================" << endl;
    cout << "=========================================" << endl;

    int option;
    cout << endl << "MENU:" << endl;
    cout << "1. Login" << endl;
    cout << "2. Create Account" << endl;
    cout << "3. Exit" << endl;

    cout << "Choose an option: ";  //prompt user for an option
    cin >> option;
    cout << endl;

    switch(option)
    {
        case 1:
            {
                login(users);
                break;
            }
        case 2:
            {
                createAccount(users);
                break;
            }
        case 3:
            {
                exit(0);
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
        cout << "=========================" << endl;
        cout << "Welcome " << userFirst << endl;
        cout << "=========================" << endl;
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
    r:
    int choice;
    cout << "=========================" << endl;
    cout << "|____1) Browse Game ____|" << endl;
    cout << "|____2) View Cart ______|" << endl;
    cout << "|____3) Manage Profile _|" << endl;
    cout << "|____4) Logout__________|" << endl;
    cout << "=========================" << endl;
    cout << endl;

    cout << "Please select a choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            {
                browseGame();
                break;
            }
        case 2:
            {
                cout << "CODE NEEDED" << endl;
                break;
                //code needed for viewing cart item
            }
        case 3:
            {
                manageProfile(users);
                break;

            }
        case 4:
            {
                mainmenu();
                break;
            }
        default:
            {
                cout << endl;
                cout << "Invalid Choice. Please try again." << endl << endl;
                goto r;
            }


    }
}

void Navigation::browseGame()
{
    cout << "hello...."<< endl;
    //CODE NEEDED for displaying all the game to the user;
}

void Navigation::manageProfile(vector<user>& users)
{
    int exist;
    string ID, profileID, profilePW, profileFirst, profileLast, profileEmail, profilePhone;
    b:
    cout << "Please enter userID to proceed: ";
    cin >> ID;
    for(unsigned int i = 0; i < users.size(); i++)
    {
        if(users[i].getUserID() == ID)
        {
            r:
            //creating each variable to store the information from user profile
            profileID = users[i].getUserID();
            profilePW = users[i].getPassword();
            profileFirst = users[i].getFirst();
            profileLast = users[i].getLast();
            profileEmail = users[i].getEmail();
            profilePhone = users[i].getPhone();
            int choice;

            cout << "======================================" << endl;
            cout << "            Manage Profile            " << endl;
            cout << "======================================" << endl;
            cout << "|____1) Edit Account Information ____|" << endl;
            cout << "|____2) View Order History___________|" << endl;
            cout << "|____3) Delete Account_______________|" << endl;
            cout << "======================================" << endl;
            cout << endl;

            cout << "Please select a choice: ";
            cin >> choice;

            switch(choice)
            {
                case 1:
                    {   s:
                        cout << "================================" << endl;
                        cout << "         Manage Profile         " << endl;
                        cout << "================================" << endl;
                        cout << "UserID: " << profileID << endl;
                        cout << "Password: *******" << endl;
                        cout << "First Name: " << profileFirst << endl;
                        cout << "Last Name: " << profileLast << endl;
                        cout << "Email: " << profileEmail << endl;
                        cout << "Phone#: " << profilePhone << endl;
                        cout << "================================" << endl;

                        int option;
                        cout << endl;
                        cout << "What would you like to change?" << endl;
                        cout << "1. UserID" << endl;
                        cout << "2. Password" << endl;
                        cout << "3. First Name" << endl;
                        cout << "4. Last Name" << endl;
                        cout << "5. Email" << endl;
                        cout << "6. Phone#" << endl;
                        cout << endl;
                        cout << "Select an option: ";
                        cin >> option;
                        switch(option)
                        {
                            case 1:
                                {
                                    bool valid = true;
                                    string changeID;
                                    cout << "Enter new userID: ";
                                    cin >> changeID;
                                    //loop through vector<user> users and see if new username is taken already
                                    for(unsigned int i = 0; i < users.size(); i++)
                                    {
                                        if(users[i].getUserID() == changeID)
                                        {
                                            cout << "\n" << changeID << " is already taken. Try another one.\n" << endl;
                                            valid = false;
                                        }
                                        //new userID not taken
                                        if(valid)
                                        {
                                            cout << "UNFINISH CODING!!!" << endl;
                                            //modify in vector and change in accounts.txt file
                                        }
                                    }

                                }
                            case 2:
                                {

                                    string changePW, confirmPW;
                                    cout << "Enter new password: ";
                                    cin >> changePW;
                                    cout << "Confirm new password: ";
                                    if(changePW == confirmPW)
                                    {
                                        cout << "UNFINISH CODING!!!!" << endl;
                                        //modify password in vector and accounts.txt
                                    }


                               }
                            case 3:
                                {
                                    cout << "UNFINISH CODING!!!" << endl;
                                    //NOT FINISH
                                }
                            case 4:
                                {
                                    cout << "UNFINISH CODING!!!" << endl;
                                    //NOT FINISH
                                }
                            case 5:
                                {
                                    cout << "UNFINISH CODING!!!" << endl;
                                    //NOT FINISH
                                }
                            case 6:
                                {
                                    cout << "UNFINISH CODING!!!" << endl;
                                    //NOT FINISH
                                }
                            default:
                                {
                                    cout << endl;
                                    cout << "Invalid Choice. Please try again." << endl << endl;
                                    goto s;
                                }
                        }

                    }
                 case 2:
                     {
                        cout << "CODE NEEDED" << endl;
                        break;
                        //CODE NEEDED for viewing order history
                     }
                 case 3:
                     {
                        cout << "CODE NEEDED" << endl;
                        break;
                        //CODE NEEDED for removing account and all its information from file;

                     }

                 default:
                     {
                        cout << endl;
                        cout << "Invalid Choice. Please try again." << endl << endl;
                        goto r;
                     }


            }

        exist = 1;
        }
    }

    cout << "UserID does not match. Please try again." << endl;
    goto b;



}
