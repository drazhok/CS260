#include <iostream>

#ifndef STUDENT_H
#define STUDENT_H

class Student {
    public:
        Student();
        Student(std::string newName, int newAge);
        void setName(std::string newName);
        std::string getName();
        void setAge(int newAge);
        int getAge();

    private:
        std::string name;
        int age;
};

#endif
