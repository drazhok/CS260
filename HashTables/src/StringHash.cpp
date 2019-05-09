#include "StringHash.h"

// Creates a hash table of a default size
StringHash::StringHash() {

    table = new std::string[11];
    tableSize = 11;

    initialize();
}

// Creates a hash table with a custom size
StringHash::StringHash(int newSize) {

    table = (newSize <= 0) ? new std::string[11] : new std::string [newSize];
    tableSize = (newSize <= 0) ? 11 : newSize;

    initialize();
}

// Initializes common values that both constructors need
void StringHash::initialize() {

    for(int i = 0; i < tableSize; i++)
        *(table + i) = "_empty_";

    itemCount = 0;
}

// Resizes the array
void StringHash::resize() {

    std::string *temp = new std::string[ (2 * tableSize) ];

    memcpy(temp, table, sizeof(table));

    delete table;

    table = temp;
}

// Adds an item to the hash table
void StringHash::addItem(std::string value) {

    if(itemCount > (tableSize / 2) )
        resize();


}

// Deletes the hash table from memory
StringHash::~StringHash() {
    delete[] table;
}
