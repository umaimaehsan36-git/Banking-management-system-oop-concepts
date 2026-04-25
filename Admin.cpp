#include "Admin.h"
#include <iostream>
#include <fstream>
using namespace std;

// ---------- LOGIN ----------
bool Admin::login() {
    string u, p;

    cout << "\n--- Admin Login ---\n";
    cout << "Username: ";
    cin >> u;

    cout << "Password: ";
    cin >> p;

    ifstream file("admin.txt");
    string au, ap;

    while (file >> au >> ap) {
        if (u == au && p == ap) {
            cout << "Login successful!\n";
            return true;
        }
    }

    cout << "Login failed!\n";
    return false;
}

// ---------- MENU ----------
void Admin::menu() {
    int c;

    do {
        cout << "\n===== Admin Panel =====\n";
        cout << "1. Create User\n";
        cout << "2. Delete User\n";
        cout << "3. Exit\n";
        cout << "Choice: ";
        cin >> c;

        string u, p;

        switch (c) {

        case 1:
            cout << "Username: ";
            cin >> u;
            cout << "Password: ";
            cin >> p;

            FileManager::createUser(u, p);
            cout << "User created successfully!\n";
            break;

        case 2:
            cout << "Enter username: ";
            cin >> u;

            if (FileManager::deleteUser(u))
                cout << "User deleted successfully!\n";
            else
                cout << "User not found!\n";

            break;

        case 3:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (c != 3);
}