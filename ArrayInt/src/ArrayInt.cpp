#include <iostream>
#include <string.h>
#include "ArrayInt.h"

// Constructor, default array size of 10
ArrayInt::ArrayInt() {
    arr = new int[10];
    arrSize = 10;
    valueCount = 0;
    initializeValues();
}

// Overloaded constructor for a custom size
ArrayInt::ArrayInt(int n) {
    if(n < 1) {
        arr = new int[10];
        arrSize = 10;
        valueCount = 0;
    }
    else {
        arr = new int[n];
        arrSize = n;
        valueCount = 0;
    }

    initializeValues();
}

// Sets the size of the array
void ArrayInt::setSize(int newSize) {
    if(newSize > arrSize) {
        int *tempArr = new int[newSize];

        memcpy(tempArr, arr, newSize * sizeof(int));

        delete[] arr;

        arr = tempArr;
        arrSize = newSize;
    }
}

// Initializes the array pointer values to NULL for comparison
void ArrayInt::initializeValues() {
    for(int i = 0; i < arrSize; i++)
        *(arr + i) = NULL;
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
        valueCount++;
    }
    else
        throw std::out_of_range("Index is out of range.");
}

// Shifts the array to the right starting at the given (or default) index
void ArrayInt::shiftArrRight(int startingIndex = 0) {
    // Start loop
        // If the next value is out of range, resize array

        // Store temp of next value
        // Set next value to current value

    /*for(int i = startingIndex; i < arrSize; i++) {
        if((i + 1) >= arrSize)
            setSize(arrSize * 2);

        int tempValue = *(arr + (i + 1));
        *(arr + (i + 1)) = *(arr + i);
    }*/
}

// Inserts a value at the specified index
void ArrayInt::insertAt(int index, int value) {
    //shiftArr();
    //*(arr + index) = value;
}

// Removes a value at the specified index
int ArrayInt::removeAt(int index) {

}

// Appends a value to the end of the array
void ArrayInt::append(int value) {
    for(int i = 0; i < arrSize; i++) {
        if(valueCount == arrSize) {
            setSize(2 * arrSize);
        }
        if(*(arr + i) == NULL) {
            setAt(i, value);
            valueCount++;
            break;
        }
    }
}

// Destructor that deletes the array
ArrayInt::~ArrayInt() {
    delete[] arr;
}
