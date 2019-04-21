#include "Student.h"

#ifndef STUDENTLIST_H
#define STUDENTLIST_H

class StudentList {
    public:
        StudentList();
        void insertHead(Student *s);
        void insertTail(Student *s);
        Student* deleteHead();
        bool isEmpty();
        bool findKey(std::string name);
        bool deleteKey(std::string name);
        ~StudentList();

    private:
        struct node;
        struct node *head;
        struct node *tail;
};

#endif
