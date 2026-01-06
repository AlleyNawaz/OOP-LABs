#include <iostream>
#include <cstring>
using namespace std;

class Person {
protected:
    char name[50];

public:
    Person(const char* n = "Unknown") {
        strcpy(name, n);
        cout << "Person constructor called.\n";
    }
    void displayPerson() {
        cout << "Name: " << name << endl;
    }
};

class Student : virtual public Person {
protected:
    int rollNo;

public:
    Student(const char* n = "Unknown", int r = 0) : Person(n), rollNo(r) {
        cout << "Student constructor called.\n";
    }
    void displayStudent() {
        cout << "Roll No: " << rollNo << endl;
    }
};

class Employee : virtual public Person {
protected:
    int empID;

public:
    Employee(const char* n = "Unknown", int e = 0) : Person(n), empID(e) {
        cout << "Employee constructor called.\n";
    }
    void displayEmployee() {
        cout << "Employee ID: " << empID << endl;
    }
};

class WorkingStudent : public Student, public Employee {
public:
    WorkingStudent(const char* n, int r, int e)
        : Person(n), Student(n, r), Employee(n, e) {
        cout << "WorkingStudent constructor called.\n";
    }

    void display() {
        cout << "\n Working Student Details" << endl;
        displayPerson();
        displayStudent();
        displayEmployee();
    }
};

int main() {
    WorkingStudent ws("Ali Khan", 101, 5001);
    ws.display();

    return 0;
}