#include <iostream>
#include "TextClass.h"

TextClass::TextClass() {

    head = nullptr;
    tail = nullptr;
    iter = nullptr;

}

// Defines each node
struct TextClass::node {

    node(char value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }

    char data;

    struct node *prev;
    struct node *next;

};

// Inserts a new head to the list
void TextClass::insertHead(char value) {

    if(isEmpty())
        head = tail = new node(value);

    else {
        struct node *newNode = new node(value);

        newNode->next = head;
        newNode->prev = nullptr;

        head->prev = newNode;

        head = newNode;
    }

}

// Inserts a new tail to the list
void TextClass::insertTail(char value) {

    if(isEmpty())
        head = tail = new node(value);

    else {
        struct node *newNode = new node(value);

        newNode->prev = tail;
        newNode->next = nullptr;

        tail->next = newNode;

        tail = newNode;
    }

}

// Deletes a head from the list
char TextClass::deleteHead() {

    if(isEmpty())
        throw std::underflow_error("The linked list is empty!");

    struct node *temp = head->next;
    char value = head->data;

    delete head;

    head = temp;

    if(head == nullptr)
        tail = nullptr;

    if(iter == head)
        iter = nullptr;

    return value;

}

// Deletes a tail from the list
char TextClass::deleteTail() {

    if(isEmpty())
        throw std::underflow_error("The linked list is empty!");

    struct node *temp = tail->prev;
    char value = tail->data;

    delete tail;

    tail = temp;

    if(tail == nullptr)
        head = nullptr;

    if(iter == tail)
        iter = nullptr;

    return value;

}

// Determines if the list is empty
bool TextClass::isEmpty() {

    if(tail == nullptr || head == nullptr)
        return true;
    else
        return false;

}

// Finds a key and sets iter to it
bool TextClass::findKey(char value) {

    // EDIT: my code now successfully wraps. Thanks for the help, Alexander.
    struct node *currentNode = (iter == nullptr) ? head : iter->next;

    for (struct node *ptr = currentNode; ptr != nullptr; ptr = ptr->next) {
        if (ptr->data == value) {
            iter = ptr;
            return true;
        }
    }

    if (iter != nullptr) {

        for (struct node *ptr = head; ptr != iter; ptr = ptr->next) {
            if (ptr->data == value) {

                iter = ptr;
                return true;
            }
        }
    }


    iter = nullptr;
    return false;
}

// Inserts a key behind the location of iter
bool TextClass::insertKey(char value) {

    // If iter is nullptr, we can't insert at any location
    if(iter == nullptr)
        return false;

    if(iter == head ) {
        insertHead(value);
        return true;
    }

    struct node *newNode = new node(value);

    struct node *previous = iter->prev;

    newNode->prev = previous;
    newNode->next = iter;

    previous->next = newNode;

    iter->prev = newNode;

    return true;


}

// Deletes the node at iter
bool TextClass::deleteIter() {

    if(iter == nullptr)
        return false;

    else {
        struct node *left = iter->prev;
        struct node *right = iter->next;

        delete iter;

        left->next = right;
        right->prev = left;

        iter = nullptr;

        return true;
    }

}

// Deletes the first key with the given value
bool TextClass::deleteKey(char value) {

    struct node *currentNode = head;

    while(currentNode != nullptr) {

        if(currentNode->data == value) {

            if(iter == currentNode)
                iter = nullptr;

            struct node *left = currentNode->prev;
            struct node *right = currentNode->next;

            delete currentNode;

            left->next = right;
            right->prev = left;

            return true;
        }

        currentNode = currentNode->next;

    }

    return false;

}

// Displays a list of all the nodes
std::string TextClass::displayList() {

    std::string list = "";

    char value;

    struct node *currentNode = head;

    while(currentNode != nullptr) {

        value = currentNode->data;

        list += value;

        currentNode = currentNode->next;

    }

    return list;
}

// Appends a given list to the list
void TextClass::appendList(TextClass &list) {

    std::string word = list.displayList();

    for(int i = 0; i < word.length(); i++)
        insertTail(list.deleteHead());

}

// Deletes all the nodes
TextClass::~TextClass() {

    struct node *currentNode = head;

    if(!isEmpty()) {
        while(currentNode != nullptr) {
            struct node *tempNode = currentNode;

            currentNode = tempNode->next;

            delete tempNode;
        }
    }
}
