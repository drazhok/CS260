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
        int *tempArr = new int[newSize];

        memcpy(tempArr, arr, newSize * sizeof(int));

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

    for(int i = lastValueIndex; i >= index; i--) {
        if((i + 1) >= arrSize)
            setSize(arrSize * 2);

        setAt((i + 1), *(arr + i));
    }

    valueCount = oldValueCount;

    setAt(index, value);
}

// Removes a value at the specified index
int ArrayInt::removeAt(int index) {
    if(index < 0 || index >= arrSize || valueCount <= 0)
        throw std::out_of_range("Index is out of range.");

    int value = getAt(index);
    int oldValueCount = valueCount;

    for(int i = index; i <= lastValueIndex; i++) {
        setAt(i, *(arr + (i + 1)));
    }

    valueCount = oldValueCount;

    lastValueIndex--;
    valueCount--;
    return value;
}

// Appends a value to the end of the array
void ArrayInt::append(int value) {
    if((lastValueIndex + 1) >= arrSize)
        setSize(arrSize * 2);

    setAt(lastValueIndex + 1, value);
}

// Destructor that deletes the array
ArrayInt::~ArrayInt() {
    delete[] arr;
}
