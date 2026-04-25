#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
using namespace std;

class FileManager {
public:
    // AUTH
    static bool findUser(string username, string password, double &balance);
    static bool findUserByUsername(string username, string &password, double &balance);
    static bool userExists(string username);

    // CORE
    static void updateBalance(string username, double balance);
    static void updatePassword(string username, string newPassword);
    static void createUser(string username, string password);
    static bool deleteUser(string username);

    // ADMIN
    static bool findAdmin(string username, string password);
    static void createAdmin(string username, string password);
    static void deleteAdmin(string username);

    // TRANSACTIONS
    static void addTransaction(string username, string record);
    static void showTransactions(string username);

    // INTEREST
    static void applyInterest(double rate);

    // ENCRYPTION
    static string encrypt(string data);
    static string decrypt(string data);
};

#endif