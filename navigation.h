#ifndef NAVIGATION_H
#define NAVIGATION_H

#include "user.h"

class Navigation
{
private:

public:
    Navigation();
    void mainmenu();
    void login(vector<user>& users);
    void createAccount(vector<user>& users);
    void afterLogin();
    void browseGame();
    void manageProfile(vector<user>& users);
};

#endif // NAVIGATION_H
