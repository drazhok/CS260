#include <iostream>
#include <string.h>
#include "ArrayInt.h"

// Constructor, default array size of 10
ArrayInt::ArrayInt() {
    arr = new int[10];
    arrSize = 10;
    valueCount = 0;
    lastValueIndex = -1;
}

// Overloaded constructor for a custom size
ArrayInt::ArrayInt(int n) {

    // Creates a new array with a default size if n is an invalid number
    if(n < 1) {
        arr = new int[10];
        arrSize = 10;
        lastValueIndex = -1;
        valueCount = 0;
    }
    else {
        arr = new int[n];
        arrSize = n;
        lastValueIndex = -1;
        valueCount = 0;
    }
}

// Sets the size of the array
void ArrayInt::setSize(int newSize) {
    if(newSize > arrSize) {

        // Creates a temporary array...
        int *tempArr = new int[newSize];

        // ...Then copies the memory from the existing array...
        memcpy(tempArr, arr, newSize * sizeof(int));

        // ...Then finally, deletes the old array.
        delete[] arr;

        arr = tempArr;
        arrSize = newSize;
    }
}

// Gets the size of the array
int ArrayInt::getSize() {
    return arrSize;
}

// Gets the value at the specified index
int ArrayInt::getAt(int index) {
    if(index >= 0 && index < arrSize)
        return *(arr + index);
    else
        throw std::out_of_range("Index is out of range.");
}

// Sets a value at the specified index
void ArrayInt::setAt(int index, int value) {
    if(index >= 0 && index < arrSize) {
        *(arr + index) = value;

        // I'm not sure how to check if a value existed previously, so if
        // there was an existing value, the valueCount goes up anyways.
        valueCount++;

        if(index > lastValueIndex)
            lastValueIndex = index;
    }
    else
        throw std::out_of_range("Index is out of range.");
}

// Inserts a value at the specified index
void ArrayInt::insertAt(int index, int value) {
    int oldValueCount = valueCount;

    // Shifts all values to the right by one
    for(int i = lastValueIndex; i >= index; i--) {

        // Resizes the array if the next index is too large
        if((i + 1) >= arrSize)
            setSize(arrSize * 2);

        setAt((i + 1), *(arr + i));
    }

    valueCount = oldValueCount;

    setAt(index, value);
}

// Removes a value at the specified index
int ArrayInt::removeAt(int index) {

    // Error checking in case the index is incorrect
    if(index < 0 || index >= arrSize || valueCount <= 0 || index > lastValueIndex)
        throw std::out_of_range("Index is out of range.");

    int value = getAt(index);
    int oldValueCount = valueCount;

    // Shifts all values left by one
    for(int i = index; i <= lastValueIndex; i++)
        setAt(i, *(arr + (i + 1)));

    // setAt increments the value count each time, so we have to reset it after shifting everything
    valueCount = oldValueCount;

    // Decrements the last value index and value count
    lastValueIndex--;
    valueCount--;
    return value;
}

// Appends a value to the end of the array
void ArrayInt::append(int value) {

    // Expands the array if the array is full
    if((lastValueIndex + 1) >= arrSize)
        setSize(arrSize * 2);

    setAt(lastValueIndex + 1, value);
}

// Destructor that deletes the array
ArrayInt::~ArrayInt() {
    delete[] arr;
}
