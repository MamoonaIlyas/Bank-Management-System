This C++ project is a simple bank management system implemented using object-oriented programming (OOP) concepts. Here's a breakdown of its functionality and structure:

Features:
1. Create New Account: Allows users to create a new bank account by providing their name, account number, and initial balance.
2. Show All Accounts: Displays all existing bank accounts with their respective details (name, account number, balance).
3. Search Account: Searches for a specific bank account by its account number and displays its details if found.
4. Deposit Money: Allows users to deposit money into an existing bank account by specifying the account number and the amount to deposit.
5. Withdraw Money: Enables users to withdraw money from an existing bank account by specifying the account number and the amount to withdraw.
6. Exit: Exits the program.

Classes:
1. BankAccount: Represents a single bank account. It has attributes such as name, account number, and balance. It provides methods for depositing and withdrawing money, as well as retrieving account details.
2. BankManagement: Manages all bank accounts. It contains a vector of `BankAccount` objects and provides methods for adding new accounts, displaying all accounts, searching for specific accounts, and finding accounts by account number.

Functions:
1. LandingPage(): Displays the main menu options for the user to choose from.
2. createAccount(BankManagement &Bank): Function to create a new bank account by taking input for name, account number, and initial balance, then adding it to the `BankManagement` object.

Main Function:
1. main(): The main function of the program. It initializes a `BankManagement` object and enters a loop where the user can choose from various options provided by the `LandingPage()` menu. Depending on the chosen option, it calls corresponding functions to perform the desired operation.

Overall:
This project demonstrates a simple implementation of a bank management system using classes, objects, and vector containers in C++. It provides basic functionalities for managing bank accounts such as creating, displaying, searching, depositing, and withdrawing money.
