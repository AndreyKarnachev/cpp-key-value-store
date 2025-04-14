#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <string>
#include "KeyValueStore.h"

using namespace std;

void printMenu() {
	cout << "\n   Key-Value Store Menu   \n";
	cout << "1.Insert\n";
	cout << "2.Get\n";
	cout << "3.Update\n";
	cout << "4.Remove\n";
	cout << "5.Save\n";
	cout << "6.Load\n";
	cout << "7.Exit\n";
	cout << "Enter command number: \n";
}

int main()
{
	KeyValueStore db("data.txt");
	int storage; //stores the chosen number
	string key, value;
	while (true) {
		printMenu();
		cin >> storage;

		if (cin.fail()) {
			cin.clear(); // Clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores the unwanted inputs
			cout << "You need to input a valid command number!" << endl;
			continue; // Print menu again and ask for input
		}

		// Check if the number is within the valid range (1-7)
		if (storage < 1 || storage > 7) {
			cout << "Not a valid command number!" << endl;
			continue; 
		}

		switch (storage) {
		case 1:
			cout << "Enter key: ";
			cin >> key;
			cout << "Enter value: ";
			cin >> value;
			db.insert(key,value);
			break;

		case 2:
			cout << "Enter key: ";
			cin >> key;
			cout << "Value of the given key: " << db.get(value) << endl;
			break;

		case 3:
			cout << "Enter key: ";
			cin >> key;
			cout << "Enter value to update: ";
			cin >> value;
			db.update(key, value);
			break;

		case 4:
			cout << "Enter key you  want to remove: ";
			cin >> key;
			db.remove(key);
			break;

		case 5:
			db.saveToFile();
			break;

		case 6:
			db.loadFromFile();
			break;

		case 7:
			db.saveToFile();
			cout << "Exiting and autosaving." << "\n";
			return 0;

		default: 
			cout << "Not a valid command number!";
			break;

		}
		
		

	}
	return 0;
}