# Key-Value Store in C++

This is a small C++ project that implements a basic key-value store system.  
It allows saving, retrieving, and displaying key-value pairs using simple file storage.

## Features

- Add key-value pairs
- Search for keys
- Load and save data from a file

## Files

- `main.cpp` - Runs the program
- `KeyValueStore.cpp` / `KeyValueStore.h` - Core logic of the key-value store
- `data` - File used to save key-value data

## How to Compile

You can compile it using g++:

```bash
g++ main.cpp KeyValueStore.cpp -o kvstore
