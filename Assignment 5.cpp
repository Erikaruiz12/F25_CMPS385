/*
Erika Ruiz
10/06/25
Data Structures
Store Inventory and Profit Tracker
*/
#include <iostream>
#include <fstream>
#include<string>
using namespace std;

struct Item {
	string name;
	string category;
	int quantity;
	double price;
};
struct Transaction {
	string type; // "BUY" or "RETURN"
	string itemName;
	int quantity;
	double unitPrice;
};
// Function Declarations
int loadInventory(Item items[]);
void saveInventory(Item items[], int count);
int loadTransactions(Transaction txns[]);
void saveTransaction(Transaction t);
void displayInventory(Item items[], int count);
void buyItem(Item items[], int counter);
void returnItem(Item items[], int count);
void showProfitReport(Transaction txns[], int count);
int main() {
	//sets item array max
	Item items[100];
	int counter = loadInventory(items);
	int choice = 0;
	cout << "******** Welcome to Store Inventory & Profit Tracker ********";
	//menu
	while (choice != 6) {
		cout << "1. Add New Item" << " " << "2. Display Inventory" << " " << "3. Buy Item" << " " << "4. Return Item" << " " << "View Profit Report" << "6. Exit\n";
		cout << "Please Enter choice: ";
		cin >> choice;
		if (choice == 1) {
			cout << "Enter item Name: ";
			cin >> items[counter].name;
			cout << "Enter Category: ";
			cin >> items[counter].category;
			cout << "Enter the Price: ";
			cin >> items[counter].price;
			cout << "Enter Quantity: ";
			cin >> items[counter].quantity;
		}
		else if (choice == 2) {
			displayInventory(items, counter);
		}
		else if (choice == 3) {
			buyItem(items, counter);
		}
		else if (choice == 4) {
			returnItem(items, counter);
		}
		else if (choice == 5) {
			showProfitReport;
		}
		else if (choice == 6) {
			saveInventory(items, counter);
			cout << "Inventory and transactions saved. Goodbye!\n";

		}

	}
	system("pause");
	return 0;
}
//loads the inventory
int loadInventory(Item items[])
{
	//creates the file
	ifstream invF("inventory.txt");
	int counter = 0;
	if (!invF) {
		return 0;
	}
	string head;
	getline(invF, head);
	while (!invF.eof()) {
		invF >> items[counter].name >> items[counter].category >> items[counter].price >> items[counter].quantity;
		if (invF.fail())
			break;
		counter++;
	}
	invF.close();
	return counter;;
}

void saveInventory(Item items[], int counter)
{
	ofstream invF("inventory.txt");
	invF << "Name| Catergory |Price| Quantity\n";
	int count = 0;
	while (count < counter) {
		invF << items[counter].name << "| " << items[counter].category << "| " << items[counter].price << "| " << items[counter].quantity;
		count++;
	}
	invF.close();
}

int loadTransactions(Transaction txns[])
{
	ifstream invF("transactions.txt");
	int counter = 0;
	if (!invF)
		return 0;
	string head;
	getline(invF, head);
	while (!invF.eof()) {
		invF >> txns[counter].type >> txns[counter].itemName >> txns[counter].unitPrice >> txns[counter].unitPrice;
		if (invF.fail())
			break;
		counter++;
	}
	invF.close();
	return counter;
}

void saveTransaction(Transaction t)
{
	ofstream invF("transactions.txt");
	invF << t.type << " |" << t.itemName << "|" << t.unitPrice << "|" << t.quantity;
	invF.close();
}

void displayInventory(Item items[], int count)
{
	cout << "----------Inventory------------- \n\n  Name    Catergory   Price   Quantity  ----------------";
	for (int i = 0; i < count; i++)
	{
		cout << items[i].name << " |" << items[i].category << " |" << items[i].price << " |" << items[i].quantity;

	}
}

void buyItem(Item items[], int counter)
{
	string itemName;
	int quantity;
	cout << "Enter the Item you wish to buy";
	cin >> itemName;
	cout << "Quanitty: ";
	cin >> quantity;
	for (int i = 0; i < counter; i++)
	{
		if (items[i].name == itemName) {
			items[i].quantity -= quantity;
			double total = quantity * items[i].price;
			cout << "You bought " << quantity << "for $" << total << endl;
			Transaction transaction = { "Buy",itemName ,quantity, items[i].price };
			saveTransaction(transaction);
			return;
		}
	}

}

void returnItem(Item items[], int count)
{
	string itemName;
	int quantity;
	cout << "Enter item yoi wish to return: ";
	cin >> itemName;
	cout << "Quanitty: ";
	cin >> quantity;
	for (int i = 0; i < count; i++)
	{
		if (items[i].name == itemName) {
			items[i].quantity += quantity;
			Transaction transaction = { "Return", itemName , quantity, items[i].price };
			saveTransaction(transaction);
			cout << quantity << " " << itemName << "returned.";
			return;
		}
	}
}

void showProfitReport(Transaction txns[], int count)
{
	double rev = 0;
	double refund = 0;
	Transaction transactions;
	ifstream invF("transactions.txt");
	if (!invF) {
		cout << "No transaction found.";
		return;
		while (invF >> transactions.type >> transactions.itemName >> transactions.unitPrice >> transactions.quantity) {
			if (transactions.type == "Buy") {
				rev += transactions.quantity * transactions.unitPrice;
			}
			else if (transactions.type == "Return") {
				refund += transactions.quantity * transactions.unitPrice;
			}
			cout << "-------Profit Report--------";
			cout << "Total Revenue: $" << rev << endl;
			cout << "Total Refund: $" << refund << endl;
			cout << "Total Profit: $" << (rev - refund) << endl;
			cout << "-----------------------------------";
			invF.close();

		}
	}
}