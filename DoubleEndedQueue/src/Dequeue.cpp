#include <iostream>
#include <string.h>
#include "Dequeue.h"

Dequeue::Dequeue() {
    arr = new int[100];
    arrSize = 100;

    Initialize();
}

Dequeue::Dequeue(int newSize) {
    if(newSize <= 0) {
        arr = new int[100];
        arrSize = 100;
    }
    else {
        arr = new int[newSize];
        arrSize = newSize;
    }

    Initialize();
}

void Dequeue::Initialize() {
    left = right = -1;
}

void Dequeue::setSize(int newSize) {
    if(newSize > arrSize) {
        int *tempArr = new int[newSize];

        if(left > right) {
            for(int i = 0; i < arrSize; i++)
                *(tempArr + i) = getLeft();

            left = 0;
            right = arrSize - 1;
        }
        else {
            memcpy(tempArr, arr, sizeof(int) * newSize);
        }

        arrSize = newSize;

        delete[] arr;

        arr = tempArr;
    }
}

void Dequeue::addLeft(int value) {
    if(isFull()) {
        setSize(2 * arrSize);
        left = (left + arrSize - 1) % arrSize;
    }
    else if(isEmpty())
        left = right = 0;
    else
        left = (left + arrSize - 1) % arrSize;

    *(arr + left) = value;
}

void Dequeue::addRight(int value) {
    if(isFull()) {
        setSize(2 * arrSize);
        right = (right + 1) % arrSize;
    }
    else if(isEmpty())
        right = left = 0;
    else
        right = (right + 1) % arrSize;

    *(arr + right) = value;
}

int Dequeue::getLeft() {
    if(isEmpty())
        throw std::range_error("The double-ended queue is empty.");

    int oldLeft = left;
    int value = *(arr + left);

    left = (left + 1) % arrSize;

    if(oldLeft == right)
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

bool Dequeue::isEmpty() {
    if(left == -1 && right == -1)
        return true;
    else
        return false;
}

bool Dequeue::isFull() {
    if((left + arrSize - 1) % arrSize == right)
        return true;
    else
        return false;
}

Dequeue::~Dequeue() {
    delete[] arr;
}
