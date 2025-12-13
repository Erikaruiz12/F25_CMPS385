//Erika Ruiz
// 9-2-25
//CMPS 385 
// Data Structure

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
class Book {
private:  //Private Variables
	int id;
	string title;
	string author;
	int year;
	bool available;
public: //public variables
	Book() {
		id = 0;
		title = " ";
		author = " ";
		year = 0;
		available = true;
	}
	Book(int newId, string newTitle, string newAuthor, int newYear) { //sets intergers
		id = newId;
		title = newTitle;
		author = newAuthor;
		year = newYear;
		available = true;
	}
	//create the intinces where we get the variables
	int getID() {
		return id;
	}
	string getTitle() {
		return title;

	}
	string getAuthor() {
		return author;
	}
	int getYear() {
		return year;
	}
	//sets book avaiablilty
	bool availability() {
		return available;
	}
	//sets the new variables
	void setID(int newId) {
		id = newId;
	}
	void setTitle(string newTitle) {
		title = newTitle;
	}
	void setAuthor(string newAuthor) {
		author = newAuthor;
	}
	void setYear(int newYear) {
		year = newYear;
	}
	//checks if the book is available
	bool borrowbook() {
		if (available) {
			available = false;
			return true;
		}
		return false;
	}
	//checks if the book exsists and is returned
	bool returnbook() {
		if (!available) {
			available = true;
			return true;
		}
		return false;
	}
	//diplay
	void display() {
		cout << "ID: " << id << endl;
		cout << "Title: " << title << endl;
		cout << "Author: " << author << endl;
		cout << "Year: " << year << endl;
		cout << "Status: " << (available ? "Available" : "Borrowed") << endl;
	}
};
int main() {
	srand(time(0)); //random number gen
	Book books[100]; //sets array
	int count = 0; //sets count to 0
	int choice = -1;
	//options selecter
	while (choice != 0) {
		cout << "*************** Welcome to the Library ***************" << endl;
		cout << "Please choose one of the following operations: " << endl;
		cout << "1: Add a new book \n" << endl;
		cout << "2: Borrow a book\n" << endl;
		cout << "3: Return a book\n" << endl;
		cout << "4: Display details of a book (by ID) \n" << endl;
		cout << "5: List all available books \n" << endl;
		cout << "6: Exit\n" << endl;
		cin >> choice;
		cin.ignore();
		if (choice == 1) {
			string title;
			string author;
			int year;
			cout << "Enter Title: ";
			getline(cin, title);
			cout << "Enter Author: ";
			getline(cin, author);
			cout << "Enter Year: ";
			cin >> year;
			cin.ignore();
			int id = rand() % 8000 + 1000; //gets random ID #
			Book newInput(id, title, author, year);
			books[count++] = newInput;
			cout << "Book successfully added!\n";
			cout << "Title: " << title << endl;
			cout << "ID: " << id << endl;

		}
		else if (choice == 2) {
			int bID;
			cout << "Enter ID: " << endl;
			cin >> bID;
			//checks book abailibilty and allows book borrow
			bool found = false;
			for (int i = 0; i < count; i++)
			{
				if (books[i].getID() == bID) {
					found = true;
					if (books[i].borrowbook())
					{
						cout << "You have borrwed " << books[i].getTitle() << ".\n" << endl;
					}
					else {
						cout << "Book is not availble at the moment." << endl;
					}
				}

			}
			if (!found) {
				cout << "Book not found.\n" << endl;
			}
		}
		else if (choice == 3) {
			int bID;
			cout << "Enter Book ID:";
			cin >> bID;
			bool found = false;
			//checks if book exsists and is returnable
			for (int i = 0; i < count; i++)
			{
				if (books[i].getID() == bID) {
					found = true;
					if (books[i].returnbook())
					{
						cout << "You have returned " << books[i].getTitle() << ".\n" << endl;
					}
					else {
						cout << "Book has not been borrowed.";
					}
				}

			}
			if (!found) {
				cout << "Book not found.\n" << endl;
			}
		}
		else if (choice == 4) {
			int bID;
			cout << "Enter Book ID: ";
			cin >> bID;
			bool found = false;
			for (int i = 0; i < count; i++)
			{
				if (books[i].getID() == bID) {
					//pulls diplay from outside main
					books[i].display();
					found == true;
				}
			}
			if (!found) {
				cout << "This book does not exists." << endl;
			}
		}
		else if (choice == 5) {
			bool a = false;
			cout << "Available Books: \n" << endl;
			for (int j = 0; j < count; j++)
			{
				if (books[j].availability()) {
					cout << "\nID: " << books[j].getID();
					cout << "\nTitle: " << books[j].getTitle();
					cout << "\nAuthor:" << books[j].getAuthor();
					cout << "\nYear: " << books[j].getYear() << endl;
					a = true;
				}
			}
			if (!a) {
				cout << "No Books Available" << endl;
			}
		}
		else if (choice == 6) {
			cout << "Thank you for using our Libary System!";
		}
	}

	system("pause");
	return 0;
}