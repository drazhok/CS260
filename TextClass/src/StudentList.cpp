#include "StudentList.h"

StudentList::StudentList() {
    head = tail = nullptr;
}

// Defines an individual node in the list
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

// Inserts a new head
void StudentList::insertHead(Student *s) {
    if(isEmpty())
        head = tail = new node(s);

    else {
        struct node *newNode = new node(s);

        newNode->next = head;

        head = newNode;
    }
}

// Inserts a new tail
void StudentList::insertTail(Student *s) {
    if(isEmpty())
        head = tail = new node(s);

    else {
        struct node *newNode = new node(s);

        tail->next = newNode;

        tail = newNode;
    }
}

// Deletes the current head and returns it
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

// Detects if the list is empty
bool StudentList::isEmpty() {
    if(head == nullptr || tail == nullptr)
        return true;
    else
        return false;
}

// Finds a single node's data by the student's name
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

// Deletes a key by name
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

// Deletes all the nodes
StudentList::~StudentList() {
    struct node *currentNode = head;

    if(!isEmpty()) {
        while(currentNode != nullptr) {
            struct node *temp = currentNode;

            currentNode = currentNode->next;

            delete temp;
        }
    }
}
