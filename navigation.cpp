#include "navigation.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include "user.h"
#include "videogame.h"

using namespace std;

Navigation::Navigation()
{

}

void Navigation::mainmenu()
{

    //creating a user class vector to store all the user class object
    vector<user> users;

    //creating a game class vector to store all the games in
    vector<videoGame> games;
    readInventory(games);



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

    cout << "Choose an option (1-3): ";     //prompt user for an option
    cin >> option;
    cout << endl;

    //utilize switch case to peform certain action base on user option input
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
                break;
            }
        default:
            {
                cout << "Invalid Option. Please try again." << endl;
            }

    }

//go back to m if the option picked was invalid
goto m;
}

//login validation function
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

            // You just need to return because return goes out of the function and return back to the mainmenu automatically
            return;
        }
        oo = false;
    }
    int exist = 0;
    string logUsername, logPassword, userFirst;
    user person; // Initialize the user object to know who is the person accessing the account
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
            person = users[i]; // Make a new user object that stores the user
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
        afterLogin(users, person); // you could pass users vector in as a argument as well as the user object to know who is logged in
    }
    else
    {
        cout << "Login Error. Incorrect username or password." << endl;
        goto b;
    }


}

// creating account function
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

                    //write the contents in the file in append mode
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
                //did not pass password confirmation
                else
                {
                    cout << "\nPassword confirmation does not match. \n" << endl;
                }
            }
        }

    }


}

// You could just pass users vector in as a parameter so you don't need to parse the user file again
// You could also pass the person object so you know who is logged in
void Navigation::afterLogin(vector<user>& users, user& person)
{
    vector<videoGame> games;
    readInventory(games);
    r:
    int choice;
    cout << "=========================" << endl;
    cout << "|____1) Browse Game ____|" << endl;
    cout << "|____2) Buy ____________|" << endl;
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
                displayInventory(games);
                break;
            }
        case 2:
            {
                buymenu();
                break;
                //code needed for viewing cart item
            }
        case 3:
            {
                //call manageProfile function
                manageProfile(users, person);
                break;

            }
        case 4:
            {
                //call back to the mainmenu() function
                mainmenu();
                break;
            }

        default:
            {
                //choice not in the choice option
                cout << endl;
                cout << "Invalid Choice. Please try again." << endl << endl;
                goto r;
            }


    }
}

void Navigation::manageProfile(vector<user>& users, user& person)
{
    int exist;
    string ID, profileID, profilePW, profileFirst, profileLast, profileEmail, profilePhone;
    b:
    cout << "Please enter userID to proceed: ";
    cin >> ID;
    /*for(unsigned int i = 0; i < users.size(); i++)
    {*/
        if(person.getUserID() == ID)
        {
            r:
            //creating each variable to store the information from user profile
            profileID = person.getUserID();
            profilePW = person.getPassword();
            profileFirst = person.getFirst();
            profileLast = person.getLast();
            profileEmail = person.getEmail();
            profilePhone = person.getPhone();
            int choice;

            cout << "======================================" << endl;
            cout << "            Manage Profile            " << endl;
            cout << "======================================" << endl;
            cout << "|____1) Edit Account Information ____|" << endl;
            cout << "|____2) View Order History___________|" << endl;
            cout << "|____3) Delete Account_______________|" << endl;
            cout << "|____4) Go Back______________________|" << endl;
            cout << "======================================" << endl;
            cout << endl;

            cout << "Please select a choice: ";
            cin >> choice;

            switch(choice)
            {
                case 1:
                    {   s:
                        cout << "================================" << endl;
                        cout << "       Account Information      " << endl;
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
                        cout << "SELECT 7 to GO BACK" << endl;
                        cout << endl;
                        cout << "Select an option (1-7) : ";
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
                                            // This modifies the user vector
                                            for (unsigned int i = 0; i < users.size(); i++)
                                            {
                                                if (users[i].getUserID() == person.getUserID()) // Check to see if the user in the list equal to the user. Note* if this doesn't work you could check to see if the username is the same
                                                {
                                                    users[i].setUserID(changeID);
                                                    person.setUserID(changeID);
                                                    cout << "UserID successfully changed!" << endl;
                                                }
                                            }

                                        }
                                    }
                                    goto w;
                                    break;

                                }
                            case 2:
                                {

                                    string changePW, confirmPW;
                                    cout << "Enter new password: ";
                                    cin >> changePW;
                                    cout << "Confirm new password: ";
                                    cin >> confirmPW;
                                    if(changePW == confirmPW)
                                    {
                                        for(unsigned int i = 0; i < users.size(); i++)
                                        {
                                            if(users[i].getUserID() == person.getUserID())
                                            {
                                                users[i].setPassword(changePW);
                                                person.setPassword(changePW);
                                                cout << "Password successfully changed!" << endl;
                                            }
                                        }
                                    }
                                    goto w;
                                    break;


                               }
                            case 3:
                                {
                                    string changeFirst;
                                    cout << "Enter new first name: ";
                                    cin >> changeFirst;
                                    for(unsigned int i = 0; i < users.size(); i++)
                                    {
                                        if(users[i].getUserID() == person.getUserID())
                                        {
                                            users[i].setFirst(changeFirst);
                                            person.setFirst(changeFirst);
                                            cout << "First name successfully changed!" << endl;
                                        }
                                    }
                                    goto w;
                                    break;

                                }
                            case 4:
                                {
                                    string changeLast;
                                    cout << "Enter new last name: ";
                                    cin >> changeLast;
                                    for(unsigned int i = 0; i < users.size(); i++)
                                    {
                                        if(users[i].getUserID() == person.getUserID())
                                        {
                                            users[i].setLast(changeLast);
                                            person.setLast(changeLast);

                                            cout << "Last name successfully changed!" << endl;
                                        }
                                    }
                                    goto w;
                                    break;
                                }
                            case 5:
                                {
                                    string changeEmail;
                                    cout << "Enter new email: ";
                                    cin >> changeEmail;
                                    for(unsigned int i = 0; i < users.size(); i++)
                                    {
                                        if(users[i].getUserID() == person.getUserID())
                                        {
                                            users[i].setEmail(changeEmail);
                                            person.setEmail(changeEmail);

                                            cout << "Email successfully changed!" << endl;
                                        }
                                    }
                                    goto w;
                                    break;
                                }
                            case 6:
                                {
                                    string changePhone;
                                    cout << "Enter new phone number: ";
                                    cin >> changePhone;
                                    for(unsigned int i = 0; i < users.size(); i++)
                                    {
                                        if(users[i].getUserID() == person.getUserID())
                                        {
                                            users[i].setPhone(changePhone);
                                            person.setPhone(changePhone);
                                            cout << "Phone number successfully changed!" << endl;
                                        }
                                    }
                                    goto w;
                                    break;
                                 }
                        case 7:
                        {
                            goto r;
                            break;
                        }




                            default:
                                {
                                    cout << endl;
                                    cout << "Invalid Choice. Please try again." << endl << endl;
                                    goto s;
                                }
                        }
                        w:
                        fstream user;
                        user.open("accounts.txt", ios::out);
                        for (unsigned int i = 0; i < users.size(); i++)
                        {
                            if(user.is_open())
                            {
                                user << users[i].getUserID() << " " << users[i].getPassword() << " " << users[i].getFirst() << " " << users[i].getLast() << " " << users[i].getEmail() << " " << users[i].getPhone() << endl;

                            }
                        }
                        user.close();
                        goto r;
                        break;


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
                 case 4:
                     {
                        afterLogin(users, person);
                        break;
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
    //}

    cout << "UserID does not match. Please try again." << endl;
    goto b;



}

//display everything in store for user
void Navigation::displayInventory(vector<videoGame> &games)
{
    for (unsigned int i = 0; i < games.size(); i++)
    {
        cout << "Title: " << games[i].getName() << "  ";
        cout << "Cost: " << games[i].getCost() << "  ";
        cout << "ItemNumber: " << games[i].getItemNum() << "  ";
        cout << "Stock: " << games[i].getStock() << "  ";
        cout << endl;
    }
}

//function that reads everything from Inventory.txt into a vector class object
void Navigation::readInventory(vector<videoGame> &games)
{
    // opens file
    ifstream infile;
    infile.open("Inventory.txt");

    string name;
    double cost;
    int itemnum;
    int stock;

    while (infile >> name >> cost >> itemnum >> stock)
    {
        videoGame temp(name, cost, itemnum, stock);
        games.push_back(temp);
    }

    infile.close();

}

//FUNCTION IS NOT WORKING CORRECTLY**********
void Navigation::buymenu()
{
    vector<videoGame> games;
    readInventory(games);
    fstream openfile;

    string gname;
    double price;
    int itemnum;
    int q;


    int arrcode[100], arrqty[100];
    string choice;
    int c=0;
    float amount = 0, total = 0;

    cout << "=======================================================" << endl;
    cout << "                     RECEIPT                           " << endl;
    cout << "=======================================================" << endl;

    //displayInventory(games);
    openfile.open("Inventory.txt", ios::in);
    if(!openfile)
    {
        cout << "Empty Inventory" << endl;
    }
    else
    {   openfile.close();
        displayInventory(games);
    cout << endl << "Please place the order..." << endl;
    do
    {
        a:
        cout << "Enter item number: ";
        cin >> arrcode[c];
        cout << "Enter the product quantity: ";
        cin >> arrqty[c];
        for(int i=0; i<c; i++)
        {
            if(arrcode[c]==arrcode[i])
            {
                cout << "\n\n Duplicate item number.Please try again.";
                goto a;
            }

        }
        c++;
        cout << "\n\n Do you want to buy another product? if 'yes' PRESS 'y'";
        cin >> choice;
    }
    while (choice == "y");

    cout << "______________________________RECEIPT________________________________________________\n" << endl;
    cout << "Game" << "                 " << "Price" << "           " << "ItemNum" << "         " << "Qty" << "         "  << "Amount" << endl;

    for(int i =0; i<c; i++)
    {
        openfile.open("Inventory.txt", ios::in);
        openfile >>gname >>price >> itemnum>> q;
        while(!openfile.eof())
        {
            if(itemnum == arrcode[i])
            {
                amount = price*arrqty[i];
                total = total + amount;
                cout << endl << gname << "              "<< price << "              " << itemnum << "         " << arrqty[i] <<"         "<<  amount<< endl;

            }
            openfile >>gname >>price >> itemnum>> q;
        }


    }
    openfile.close();
}
    cout << "\n_______________________________________________________________________________________";
    cout << "\n Total Amount: " <<total;














}



