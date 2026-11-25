# Bank-System-C-Project
Bank System C++ Final Project for Programming of Problem solving Subject Semester 2

# 🏦 Bank Management System

A lightweight, console-based **Bank Management System** developed in C/C++ (`250670107132BankSystem.cpp`). The application simulates core banking workflows through role-based **Admin** and **Customer** modes, complete with 6-digit numeric PIN authentication and persistent file storage.

---

## ✨ Features

### 👨‍💼 Admin Mode
* **Create New Accounts:** Register customers with an auto-incremented Account ID, account holder name, initial deposit validation, and a strictly validated **6-digit numeric password** (up to 3 attempts).
* **View All Accounts:** Display a tabular overview of all registered accounts (Account ID, Name, and Current Balance) without exposing sensitive passwords.
* **System Capacity Management:** Supports up to **50 concurrent accounts** with built-in overflow protection.

### 👤 Customer Mode
* **Secure Authentication:** Verifies both Account ID and 6-digit PIN before authorizing any financial operation.
* **Deposit Funds:** Validates positive deposit amounts and updates account balances in real time.
* **Withdraw Funds:** Prevents overdrafts and zero-balance withdrawals through balance verification checks.
* **Balance Inquiry:** Displays verified account details (ID, Name, and Balance).

### 💾 Persistent File Storage
* Automatically loads existing records from `Data.txt` on startup via `collectData()`.
* Saves changes immediately after account creation, deposits, withdrawals, and program exit via `keepData()` in comma-separated format (`ID,Name,Balance,Password`).

---

## 🛠️ Tech Stack & Concepts Used

* **Language:** C / C++ (`<stdio.h>`, `<stdlib.h>`, `<string.h>`, `bool`)
* **Core Concepts:**
  * Structures (`struct Acount`) & Arrays of Structures
  * File I/O (`fopen`, `fprintf`, `fscanf`, `fclose`)
  * Modular Function Design & Input Validation
  * Role-Based Menu Navigation (`switch-case` & `do-while` loops)

---

## 📂 Project Structure

```text
Bank-System-C-Project/
├── 250670107132BankSystem.cpp   # Main source code containing all logic and file I/O
├── Data.txt                     # Auto-generated flat-file database storing account records
└── README.md                    # Project documentation

🚀 Getting Started
Prerequisites
A C++ compiler such as G++ (MinGW / GCC), Clang, or an IDE like Code::Blocks, Dev-C++, or VS Code.

Platform Note: The source code uses system("cls") and system("pause"), which are native to Windows. (If running on Linux/macOS, replace system("cls") with system("clear") and remove system("pause")).

📖 Usage Guide
Select Mode: Upon launch, enter 1 for Admin Mode or 2 for Customer Mode.

Create an Account (Admin): Choose option 1, enter the customer's first name (single word without spaces), initial deposit amount, and a 6-digit numeric password.

Perform Transactions (Customer): Choose option 1 (Deposit), 2 (Withdraw), or 3 (Check Balance), then authenticate using your assigned Account ID and 6-digit password.

Exit Safely: Select the Exit option and enter X or x to confirm and save all records to Data.txt.

1,Ahmed,1500.00,123456
2,Sara,3250.50,987654

👤 Author
Mohammed Lutfi Mahfoodh Basseif

GitHub: @Mohammed-Lutfi144
