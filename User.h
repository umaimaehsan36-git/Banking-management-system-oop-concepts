#ifndef USER_H
#define USER_H

#include <iostream>
#include "Account.h"
#include "FileManager.h"
using namespace std;

class User {
private:
    string username;
    string password;
    Account account;

public:
    bool login();
    void menu();

    void deposit();
    void withdraw();
    void transfer();
    void checkBalance();
    void changePassword();
};

#endif