#include "Student.h"

Student::Student() {
    name = "";
    age = 0;
}

Student::Student(std::string newName, int newAge) {
    name = newName;
    age = newAge;
}

void Student::setName(std::string newName) {
    name = newName;
}

std::string Student::getName() {
    return name;
}

void Student::setAge(int newAge) {
    age = newAge;
}

int Student::getAge() {
    return age;
}
