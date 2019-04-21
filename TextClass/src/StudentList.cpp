#include "StudentList.h"

StudentList::StudentList() {
    head = tail = nullptr;
}

struct StudentList::node {
    node() {
        next = nullptr;
        data = nullptr;
    }

    node(Student *s) {
        next = nullptr;
        data = s;
    }

    Student *data;
    struct node *next;
};

void StudentList::insertHead(Student *s) {
    if(isEmpty())
        head = tail = new node(s);

    else {
        struct node *newNode = new node(s);

        newNode->next = head;

        head = newNode;
    }
}

void StudentList::insertTail(Student *s) {
    if(isEmpty())
        head = tail = new node(s);

    else {
        struct node *newNode = new node(s);

        tail->next = newNode;

        tail = newNode;
    }
}

Student* StudentList::deleteHead() {
    if(isEmpty())
        throw std::underflow_error("The StudentList is empty!");

    else {
        struct node *temp = head->next;
        Student *data = head->data;

        delete head;

        head = temp;

        if(head == nullptr)
            tail = nullptr;

        return data;
    }
}

bool StudentList::isEmpty() {
    if(head == nullptr || tail == nullptr)
        return true;
    else
        return false;
}

bool StudentList::findKey(std::string name) {
    struct node *currentNode = head;

    while(currentNode != nullptr) {
        if(currentNode->data->getName() == name)
            return true;
        else
            currentNode = currentNode->next;
    }

    return false;
}

bool StudentList::deleteKey(std::string name) {
    struct node *lastNode;
    struct node *currentNode = head;

    while(currentNode != nullptr) {
        if(currentNode->data->getName() == name) {
            if(currentNode == head) {
                deleteHead();
                return true;
            }
            else {
                struct node *temp = currentNode->next;
                lastNode->next = temp;

                delete currentNode;

                return true;
            }
        }
        else {
            lastNode = currentNode;
            currentNode = currentNode->next;
        }
    }

    return false;
}

StudentList::~StudentList() {
    struct node *currentNode = head;

    while(currentNode != nullptr) {
        struct node *temp = currentNode;

        currentNode = currentNode->next;

        delete temp;
    }
}
