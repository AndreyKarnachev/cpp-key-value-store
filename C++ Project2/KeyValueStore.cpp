#include "KeyValueStore.h"

using namespace std;

// Constructor to initialize with filename and load the data
KeyValueStore::KeyValueStore(const string& file) : filename(file) {
	loadFromFile();
}
// Inserting a key and value into "store"
void KeyValueStore::insert(const string& key, const string& value) {
	store[key] = value;
	cout << "Inserted: " << key << "->" << value << endl;
}

// Get value trough key
string KeyValueStore::get(const string& key) {
	if (store.find(key) != store.end()) {
		return store[key];
	}
	else {
		return "No key was found.";
	}
}
// Update
void KeyValueStore::update(const string& key, const string& value) {
	if (store.find(key) != store.end()) {
		store[key] = value;
		cout << "Update: " << key << "->" << value << endl;
	}
	else {
		cout << "No key was found. " << value << endl;
	}
}
void KeyValueStore::remove(const string& key) {
	if (store.erase(key)) {
		cout << "Deleted " << key << endl;
	}
	else {
		cout << "Key not found." << endl;
	}
}
//Load data from file to "store"
void KeyValueStore::loadFromFile() {
	ifstream file(filename);
	string  key, value;

	if (!file) {  // Check if the file was opened successfully
		cout << "Error opening file!" << endl;
		return;
	}

	store.clear();

	while (file >> key >> value) {
		store[key] = value;
	}
	file.close();
	cout << "Data loaded from file." << endl;
}
void KeyValueStore::saveToFile() {
	ofstream file(filename);

	if (!file) {  // Check if the file was opened successfully
		cout << "Error opening file!" << endl;
		return;
	}

	for (auto i = store.begin(); i != store.end(); ++i) { //auto finds the type of data automatically //++i i is said to be faster and notr create an additional copy of  i
		file << i->first << " " << i->second << "\n";
	}

	file.close();  // Close the file after writing
	cout << "Data saved to file." << endl;
}
