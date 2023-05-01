#ifndef NAVIGATION_H
#define NAVIGATION_H

#include "user.h"
#include "videogame.h"


class Navigation
{
private:

public:
    Navigation();
    void mainmenu();
    void login(vector<user>& users);
    void createAccount(vector<user>& users);
    void afterLogin(vector<user>& users, user& person);
    void browseGame();
    void manageProfile(vector<user>& users, user& person);
    void displayInventory(vector<videoGame> &games);
    void readInventory(vector<videoGame> &games);
    void buymenu();

};

#endif // NAVIGATION_H
