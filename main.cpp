#include <iostream>
#include "User.h"
#include "Admin.h"

using namespace std;

int main() {
    int choice;

    while (true) {
        cout << "\n===== NovaBank =====\n";
        cout << "1. User Login\n";
        cout << "2. Admin Login\n";
        cout << "3. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            User user;
            if (user.login()) {
                user.menu();
            }
        }
        else if (choice == 2) {
            Admin admin;
            if (admin.login()) {
                admin.menu();
            }
        }
        else {
            break;
        }
    }

    return 0;
}