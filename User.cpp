#include "User.h"
#include <conio.h>

using namespace std;

// ================= PASSWORD MASK =================
string maskPassword() {
    string pass;
    char ch;

    while ((ch = _getch()) != 13) {
        if (ch == 8 && !pass.empty()) {
            cout << "\b \b";
            pass.pop_back();
        } else {
            cout << "*";
            pass += ch;
        }
    }
    cout << endl;
    return pass;
}

// ================= LOGIN (WITH 2% INTEREST) =================
bool User::login() {
    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    password = maskPassword();

    double bal;

    if (FileManager::findUser(username, password, bal)) {

        // 2% INTEREST
        bal += (bal * 0.02);

        account.setBalance(bal);
        FileManager::updateBalance(username, bal);

        cout << " Login successful\n";
        return true;
    }

    cout << " Login failed\n";
    return false;
}

// ================= MENU =================
void User::menu() {
    int choice;

    do {
        cout << "\n--- User Dashboard ---\n";
        cout << "1. Deposit\n2. Withdraw\n3. Transfer\n4. Check Balance\n5. Change Password\n6. Mini Statement\n7. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: deposit(); break;
            case 2: withdraw(); break;
            case 3: transfer(); break;
            case 4: checkBalance(); break;
            case 5: changePassword(); break;
            case 6: FileManager::showTransactions(username); break;
            case 7: cout << " Logged out\n"; break;
            default: cout << " Invalid choice\n";
        }

    } while (choice != 7);
}

// ================= DEPOSIT =================
void User::deposit() {
    double amt;
    cout << "Enter amount: ";
    cin >> amt;

    if (amt <= 0) {
        cout << " Invalid amount\n";
        return;
    }

    account.deposit(amt);

    FileManager::updateBalance(username, account.getBalance());
    FileManager::addTransaction(username, "+ " + to_string(amt) + " Deposit");

    cout << " Deposit successful\n";
}

// ================= WITHDRAW =================
void User::withdraw() {
    double amt;
    cout << "Enter amount: ";
    cin >> amt;

    if (amt <= 0) {
        cout << " Invalid amount\n";
        return;
    }

    if (!account.withdraw(amt)) {
        cout << " Insufficient balance\n";
        return;
    }

    FileManager::updateBalance(username, account.getBalance());
    FileManager::addTransaction(username, "- " + to_string(amt) + " Withdraw");

    cout << " Withdrawal successful\n";
}

// ================= TRANSFER =================
void User::transfer() {
    string recv;
    double amt;

    cout << "Enter receiver username: ";
    cin >> recv;

    if (recv == username) {
        cout << " Cannot transfer to yourself\n";
        return;
    }

    if (!FileManager::userExists(recv)) {
        cout << " User not found\n";
        return;
    }

    cout << "Enter amount: ";
    cin >> amt;

    if (amt <= 0) {
        cout << " Invalid amount\n";
        return;
    }

    if (!account.withdraw(amt)) {
        cout << " Insufficient balance\n";
        return;
    }

    FileManager::updateBalance(username, account.getBalance());
    FileManager::addTransaction(username, "- " + to_string(amt) + " Transfer to " + recv);

    double recvBal;
    string pass;

    if (FileManager::findUserByUsername(recv, pass, recvBal)) {
        recvBal += amt;
        FileManager::updateBalance(recv, recvBal);

        FileManager::addTransaction(recv,
            "+ " + to_string(amt) + " Received from " + username);
    }

    cout << " Transfer successful\n";
}

// ================= BALANCE =================
void User::checkBalance() {
    cout << " Balance: Rs " << account.getBalance() << endl;
}

// ================= PASSWORD =================
void User::changePassword() {
    string newPass;

    cout << "Enter new password: ";
    newPass = maskPassword();

    FileManager::updatePassword(username, newPass);
    password = newPass;

    cout << " Password updated\n";
}