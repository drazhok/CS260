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
    int value = dequeue->getRight();
    dequeue->addRight(value); // Gets the right value and adds it back after storing it
    return value;
}

int Stack::pop() {
    return dequeue->getRight();
}

Stack::~Stack() {
    delete dequeue;
}
