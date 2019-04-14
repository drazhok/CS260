#include <iostream>
#include <string.h>
#include "Dequeue.h"

Dequeue::Dequeue() {
    arr = new int[100]; // Defaults to an array of size 100
    arrSize = 100;
    left = right = -1; // Initializes left and right to -1, since no value exists yet
}

Dequeue::Dequeue(int newSize) {
    if(newSize <= 0) { // Defaults to 100 if an invalid number is given
        arr = new int[100];
        arrSize = 100;
    }
    else {
        arr = new int[newSize];
        arrSize = newSize;
    }

    left = right = -1;
}

void Dequeue::setSize(int newSize) {
    if(newSize > arrSize) { // Verifies that the new size is valid
        int *tempArr = new int[newSize]; // Creates a new array with the new size

        if(left > right) { // If left is  greater than right, there must have been a wrap
            for(int i = 0; i < arrSize; i++) // Iterate through and copy all values to the new array
                *(tempArr + i) = getLeft();

            left = 0; // All values are on the left side of the array, so left must be 0
            right = arrSize - 1; // The array was previously full, so right is arrSize - 1
        }
        else {
            memcpy(tempArr, arr, sizeof(int) * newSize); // Otherwise, left must be 0 and right must be arrSize - 1 already, so we just copy the memory
        }

        arrSize = newSize; // Updates arrSize

        delete[] arr; // Deletes the original array

        arr = tempArr; // Sets the array to the new array
    }
}

void Dequeue::addLeft(int value) {
    if(isFull()) {
        setSize(2 * arrSize); // If the array is full, double the size
        left = (left + arrSize - 1) % arrSize; // In a circular array, the previous value is given with this math operation
    }
    else if(isEmpty())
        left = right = 0; // If the array is empty, left and right will be zero
    else
        left = (left + arrSize - 1) % arrSize;

    *(arr + left) = value; // Adds the value
}

void Dequeue::addRight(int value) {
    if(isFull()) {
        setSize(2 * arrSize);
        right = (right + 1) % arrSize;
    }
    else if(isEmpty())
        right = left = 0;
    else
        right = (right + 1) % arrSize; // In a circular array, the next value is given with this math operation

    *(arr + right) = value;
}

int Dequeue::getLeft() {
    if(isEmpty()) // Throws an error if the array is empty
        throw std::range_error("The double-ended queue is empty.");

    int oldLeft = left;
    int value = *(arr + left);

    left = (left + 1) % arrSize;

    if(oldLeft == right) // Checks if we're removing the final value
        left = right = -1;

    return value;
}

int Dequeue::getRight() {
    if(isEmpty())
        throw std::range_error("The double-ended queue is empty.");

    int oldRight = right;
    int value = *(arr + right);

    right = (right + arrSize - 1) % arrSize;

    if(oldRight == left)
        right = left = -1;

    return value;
}

std::string Dequeue::listLeftRight() {
    if(isEmpty()) return "Queue is empty";

    std::string list = "";

    for(int i = left; i != (right + 1) % arrSize; i = (i + 1) % arrSize) // Loops through the array (with wrapping)
        list += std::to_string(*(arr + i)) + " "; // Self explanatory. Converts the integer to a string and concatenates it to the list string

    return list;
}

bool Dequeue::isEmpty() {
    if(left == -1 && right == -1) return true; // If left and right are -1, the array is empty
    else return false;
}

bool Dequeue::isFull() {
    if((left + arrSize - 1) % arrSize == right) return true; // If the previous value index is the same value as the right index, the array is full
    else return false;
}

Dequeue::~Dequeue() {
    delete[] arr; // Deletes the array at the end to prevent a memory leak
}
