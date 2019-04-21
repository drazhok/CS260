#include <iostream>
#include "TextClass.h"

TextClass::TextClass() {

    head = nullptr;
    tail = nullptr;
    iter = nullptr;

}

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

bool TextClass::isEmpty() {

    if(tail == nullptr || head == nullptr)
        return true;
    else
        return false;

}

bool TextClass::findKey(char value) {

    struct node *currentNode = head;

    while(currentNode != nullptr) {

        if(currentNode->data == value && iter != currentNode) {
            iter = currentNode;
            return true;
        }
        else {
            currentNode = currentNode->next;
        }

    }

    iter = nullptr;

    return false;

}

bool TextClass::insertKey(char value) {

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

void TextClass::appendList(TextClass &list) {

    std::string word = list.displayList();

    for(int i = 0; i < word.length(); i++)
        insertTail(word[i]);

}

TextClass::~TextClass() {

    struct node *currentNode = head;

    while(currentNode != nullptr) {
        struct node *tempNode = currentNode;

        currentNode = tempNode->next;

        delete tempNode;
    }

}
