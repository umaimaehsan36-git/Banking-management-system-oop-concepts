#include "FileManager.h"

// ================= ENCRYPTION =================
string FileManager::encrypt(string data) {
    char key = 'K';
    for (int i = 0; i < data.size(); i++)
        data[i] ^= key;
    return data;
}

string FileManager::decrypt(string data) {
    char key = 'K';
    for (int i = 0; i < data.size(); i++)
        data[i] ^= key;
    return data;
}

// ================= FIND USER =================
bool FileManager::findUser(string username, string password, double &balance) {
    ifstream file("users.txt");

    string u, p;
    double b;

    while (file >> u >> p >> b) {
        u = decrypt(u);
        p = decrypt(p);

        if (u == username && p == password) {
            balance = b;
            return true;
        }
    }
    return false;
}

// ================= FIND USER BY NAME =================
bool FileManager::findUserByUsername(string username, string &password, double &balance) {
    ifstream file("users.txt");

    string u, p;
    double b;

    while (file >> u >> p >> b) {
        u = decrypt(u);

        if (u == username) {
            password = decrypt(p);
            balance = b;
            return true;
        }
    }
    return false;
}

// ================= USER EXISTS =================
bool FileManager::userExists(string username) {
    ifstream file("users.txt");

    string u, p;
    double b;

    while (file >> u >> p >> b) {
        if (decrypt(u) == username)
            return true;
    }
    return false;
}

// ================= CREATE USER =================
void FileManager::createUser(string username, string password) {
    ofstream file("users.txt", ios::app);

    file << encrypt(username) << " "
         << encrypt(password) << " "
         << 0 << endl;
}

// ================= UPDATE BALANCE =================
void FileManager::updateBalance(string username, double balance) {
    ifstream file("users.txt");
    ofstream temp("temp.txt");

    string u, p;
    double b;

    while (file >> u >> p >> b) {
        if (decrypt(u) == username)
            temp << u << " " << p << " " << balance << endl;
        else
            temp << u << " " << p << " " << b << endl;
    }

    file.close();
    temp.close();

    remove("users.txt");
    rename("temp.txt", "users.txt");
}

// ================= UPDATE PASSWORD =================
void FileManager::updatePassword(string username, string newPassword) {
    ifstream file("users.txt");
    ofstream temp("temp.txt");

    string u, p;
    double b;

    while (file >> u >> p >> b) {
        if (decrypt(u) == username)
            temp << u << " " << encrypt(newPassword) << " " << b << endl;
        else
            temp << u << " " << p << " " << b << endl;
    }

    file.close();
    temp.close();

    remove("users.txt");
    rename("temp.txt", "users.txt");
}

// ================= DELETE USER =================
bool FileManager::deleteUser(string username) {
    ifstream file("users.txt");
    ofstream temp("temp.txt");

    string u, p;
    double b;
    bool found = false;

    while (file >> u >> p >> b) {
        if (decrypt(u) == username) {
            found = true;
            continue;
        }
        temp << u << " " << p << " " << b << endl;
    }

    file.close();
    temp.close();

    remove("users.txt");
    rename("temp.txt", "users.txt");

    return found;
}

// ================= INTEREST 2% =================
void FileManager::applyInterest(double rate) {
    ifstream file("users.txt");
    ofstream temp("temp.txt");

    string u, p;
    double b;

    while (file >> u >> p >> b) {
        b += (b * rate / 100);
        temp << u << " " << p << " " << b << endl;
    }

    file.close();
    temp.close();

    remove("users.txt");
    rename("temp.txt", "users.txt");
}

// ================= TRANSACTIONS =================
void FileManager::addTransaction(string username, string record) {
    ofstream file("transactions_" + username + ".txt", ios::app);
    file << record << endl;
}

void FileManager::showTransactions(string username) {
    ifstream file("transactions_" + username + ".txt");

    string line;
    cout << "\n--- Mini Statement ---\n";

    if (!file) {
        cout << "No transactions found.\n";
        return;
    }

    while (getline(file, line))
        cout << line << endl;
}

// ================= ADMIN =================
bool FileManager::findAdmin(string username, string password) {
    ifstream file("admin.txt");

    string u, p;

    while (file >> u >> p)
        if (u == username && p == password)
            return true;

    return false;
}

void FileManager::createAdmin(string username, string password) {
    ofstream file("admin.txt", ios::app);
    file << username << " " << password << endl;
}

void FileManager::deleteAdmin(string username) {
    ifstream file("admin.txt");
    ofstream temp("temp.txt");

    string u, p;

    while (file >> u >> p) {
        if (u != username)
            temp << u << " " << p << endl;
    }

    file.close();
    temp.close();

    remove("admin.txt");
    rename("temp.txt", "admin.txt");
}