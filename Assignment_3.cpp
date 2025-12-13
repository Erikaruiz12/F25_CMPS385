/*
Erika Ruiz
Assignment #3
September 17, 2025
CMPS 385 Data Structures
*/
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class BankAccount {
private:
	string accountHolderName;
	int accountNumber;
	double balance;

public:
	//Constructors to initialize the account details
	BankAccount(string name, int number, double initialBalance) {
		accountHolderName = name;
		accountNumber = number;
		balance = initialBalance;
	}
	BankAccount() {
		accountHolderName = " ";
		accountNumber = 0;
		balance = 0.0;
	}
	//Creates the Account number and initialized balance
	void createAcc(string name, double initialBalance) {
		accountHolderName = name;
		balance = initialBalance;
		accountNumber = rand() % 90000 + 10000;
		cout << "Congratualations " << accountHolderName
			<< "! You have successfully opened your new bank account with the initial balance of $" << balance
			<< ". Your account number is " << accountNumber << ".\n";
	}
	int getAccNum() {
		return accountNumber;
	}
	string getName() {
		return accountHolderName;
	}
	//Function to deposit money
	void deposit(double amount) {
		//Add the 'amount' to the balance
		balance += amount;
		//Update the Balance
		cout << "Congratulations " << accountHolderName << "! You have deposited $" << amount << ". Your balance is now $" << balance << ".\n";
	}
	void withdraw(double amount) {
		if (amount > balance) {
			cout << "Insufficient Funds. Processed Failed. Please try again. \n";
		}
		else {
			balance -= amount;
			cout << "Congratulations " << accountHolderName << "! You have successfully withdrawn $" << amount << ". Your current balance is $" << balance << ".\n";
		}
	}
	void displayBalance() {
		cout << "Your current balance is $" << balance << ".\n";
	}
};
int main() {
	srand(time(0));
	BankAccount accounts[10];
	int totalAcc = 0;
	int choice;
	do {
		cout << "\nPlease choose one of the following operations:\n";
		cout << "1 - Create a new bank account with an initial balance\n";
		cout << "2 - Deposit Money to an Account\n";
		cout << "3 - Withdraw Money from an Account\n";
		cout << "4 - Display Current Balance of an Account\n";
		cout << "5 - Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 1) {
			string name;
			double balance;
			cout << "Enter your name: ";
			cin.ignore();
			getline(cin, name);
			cout << "Enter your initial balance: $";
			cin >> balance;
			accounts[totalAcc].createAcc(name, balance);
			totalAcc++;
			cout << " Press any key to retun to main menu!/n";
			cin.ignore();
			cin.get();
		}
		else if (choice == 2) {
			int accNumber;
			cout << " Enter the account number: ";
			cin >> accNumber;
			bool found = false;
			for (int i = 0; i < totalAcc; i++)
			{
				if (accounts[i].getAccNum() == accNumber) {
					double amount;
					cout << "Enter the amount deposited: $";
					cin >> amount;
					accounts[i].deposit(amount);
					found = true;
					break;
				}
			}
			if (!found) {
				cout << "No account number exists!\n";
			}
			cout << "Press any key to return to Main Menu!\n";
			cin.ignore();
			cin.get();
		}
		else if (choice == 3) {
			int accNumber;
			cout << "Enter the account number: ";
			cin >> accNumber;
			bool found = false;
			for (int j = 0; j < totalAcc; j++)
			{
				if (accounts[j].getAccNum() == accNumber) {
					double amount;
					cout << "Enter the amout you would like to withdraw: $";
					cin >> amount;
					accounts[j].withdraw(amount);
					found = true;
					break;
				}
			}
			if (!found) {
				cout << "No account number exists!\n";
			}

			cout << "Press any key to return to Main Menu!\n";
			cin.ignore();
			cin.get();
		}
		else if (choice == 4) {
			int accNum;
			cout << "Enter the account number: ";
			cin >> accNum;
			bool found = false;

			for (int i = 0; i < totalAcc; i++) {
				if (accounts[i].getAccNum() == accNum) {
					accounts[i].displayBalance();
					found = true;
					break;
				}
			}

			if (!found) {
				cout << "No account number exists!\n";
			}

			cout << "Press any key to return to Main Menu!\n";
			cin.ignore();
			cin.get();
		}
		else if (choice == 5) {
			cout << "Thank you for banking with ERIKA'S BANK! Goodbye!\n";
		}
		else {
			cout << "Invalid option! Try again.\n";
		}

	} while (choice != 5);
	system("pause");
	return 0;
}