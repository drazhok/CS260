#include <iostream>
#include "Dequeue.h"
#include "Stack.h"

Stack::Stack() {
    dequeue = new Dequeue();
}

Stack::Stack(int newSize) {
    dequeue = new Dequeue(newSize);
}

void Stack::push(int value) {
    dequeue->addRight(value);
}

int Stack::peek() {

    if(dequeue->isEmpty())
        throw std::range_error("The stack is empty!");

    int value = dequeue->getRight(); // Stores the last value
    dequeue->addRight(value); // Adds it back after using getRight

    return value;

}

int Stack::pop() {
    if(dequeue->isEmpty()) // Throws an exception if the stack is empty
        throw std::range_error("The stack is empty!");

    return dequeue->getRight();
}

Stack::~Stack() {
    delete dequeue;
}
