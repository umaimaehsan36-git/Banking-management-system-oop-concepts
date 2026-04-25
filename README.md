# 💻 File Management System (C++ OOP Project)

## 📌 Overview

This project is a **C++ Object-Oriented Programming (OOP)** based system that simulates basic file and account management operations.
It demonstrates core OOP concepts such as **encapsulation, inheritance, abstraction, and modular design**.

---

## Features

* 👤 User account management
* 🔐 Admin control system
* 📂 File handling (read/write data)
* 💳 Transaction management
* 📄 Data stored using text files
* 🧩 Modular code using classes and headers

---

## Technologies Used

* **C++**
* Object-Oriented Programming (OOP)
* File Handling (fstream)

---

## Project Structure

```id="t8x3r2"
Account.cpp / Account.h      → Handles account-related operations  
Admin.cpp / Admin.h          → Admin functionalities  
User.cpp / User.h            → User-related operations  
FileManager.cpp / .h         → File handling system  
main.cpp                     → Program entry point  

Data Files:
users.txt
admin.txt
transactions_*.txt
```

---

## How to Run the Project

### Option 1: Using Executable

1. Open the project folder
2. Run:

```id="3k2p8x"
main.exe
```

---

### Option 2: Compile Manually

1. Open terminal / command prompt
2. Navigate to project folder
3. Compile:

```id="c9x7l1"
g++ main.cpp Account.cpp Admin.cpp User.cpp FileManager.cpp -o main
```

4. Run:

```id="k3d9z0"
./main
```

---

## OOP Concepts Used

* **Encapsulation** → Classes like `User`, `Admin`, `Account`
* **Abstraction** → Separation of logic into different modules
* **Modularity** → Multiple `.cpp` and `.h` files

---

## Data Handling

* User data stored in: `users.txt`
* Admin data stored in: `admin.txt`
* Transactions stored in separate files

---

## Sample Output

<img width="751" height="519" alt="image" src="https://github.com/user-attachments/assets/27b947a8-45ab-4e1b-9ebf-8c6a3480fd47" />
<img width="858" height="545" alt="image" src="https://github.com/user-attachments/assets/427047af-502b-4b19-8a2c-7486148add19" />
<img width="1025" height="624" alt="image" src="https://github.com/user-attachments/assets/04173b65-0769-4e88-a56b-51d9bc028716" />
<img width="976" height="669" alt="image" src="https://github.com/user-attachments/assets/ae0103c0-87ec-49cc-a70f-ed844f07b2f7" />


---

## Learning Purpose

This project was built to practice:

* Object-Oriented Programming in C++
* File handling using text files
* Structuring large programs using multiple classes

---

## Author

**Umaima**

---

## 📄 License

This project is open-source and free to use for learning purposes.
