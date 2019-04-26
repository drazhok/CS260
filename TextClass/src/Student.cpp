#include "Student.h"

// Students initialize with an empty name and an age of 0
Student::Student() {
    name = "";
    age = 0;
}

// Initializes students with custom variables
Student::Student(std::string newName, int newAge) {
    name = newName;
    age = newAge;
}

// Sets the name of the student
void Student::setName(std::string newName) {
    name = newName;
}

// Gets the name of the student
std::string Student::getName() {
    return name;
}

// Set the age of the student
void Student::setAge(int newAge) {
    age = newAge;
}

// Gets the age of the student
int Student::getAge() {
    return age;
}
