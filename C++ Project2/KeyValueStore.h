#pragma once
#ifndef KEYVALUESTORE_H
#define KEYVALUESTORE_H

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

class KeyValueStore {
private:
	unordered_map < string, string > store;
	string filename;
public:
	KeyValueStore(const string& key);

	//CRUD 
	void insert(const string& key, const string& value); // using insert , instead of create
	string get(const string& key); 
	void update(const string& key, const string& value);
	void remove(const string& key); // using remove , because delete is not possible as a name

	//File handling
	void loadFromFile();
	void saveToFile();
};
#endif