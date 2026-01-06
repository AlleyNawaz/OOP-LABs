#include <iostream>
using namespace std;

class Student
{
    string name;
    int rollNumber;
    float marks[3];
    int age;
    char gender;
    string address;

public:
    Student(string n, int r, float m1, float m2, float m3, int a, char g, string addr)
    {
        name = n;
        rollNumber = r;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
        age = a;
        gender = g;
        address = addr;
    }
    float totalMarks()
    {
        return marks[0] + marks[1] + marks[2];
    }
    void display()
    {
        cout << "Name: " << name << ", Roll: " << rollNumber << ", Marks: " << totalMarks()
             << ", Age: " << age << ", Gender: " << gender << ", Address: " << address << endl;
    }
    void updatePersonalInfo(int newAge, char newGender, string newAddress)
    {
        age = newAge;
        gender = newGender;
        address = newAddress;
    }
    int getAge() { return age; }
    char getGender() { return gender; }
    string getAddress() { return address; }
};

void modifyByValue(Student s)
{
    cout << "Inside modifyByValue (Before): ";
    s.display();
    s.updatePersonalInfo(25, s.getGender(), "Lahore, Pakistan");
    cout << "Inside modifyByValue (After): ";
    s.display();
}

void modifyByReference(Student &s)
{
    cout << "Inside modifyByReference (Before): ";
    s.display();
    s.updatePersonalInfo(s.getAge(), 'F', "Islamabad, Pakistan");
    cout << "Inside modifyByReference (After): ";
    s.display();
}

void modifyByPointer(Student *s)
{
    cout << "Inside modifyByPointer (Before): ";
    s->display();
    s->updatePersonalInfo(30, s->getGender(), s->getAddress());
    cout << "Inside modifyByPointer (After): ";
    s->display();
}

int main()
{
    Student s("Ali", 101, 80, 85, 90, 20, 'M', "Rawalpindi, Pakistan");

    cout << "Original Student:\n";
    s.display();

    cout << "\nPass by Value \n";
    modifyByValue(s);
    cout << "After modifyByValue (in main): ";
    s.display();

    cout << "\nPass by Reference \n";
    modifyByReference(s);
    cout << "After modifyByReference (in main): ";
    s.display();

    cout << "\nPass by Pointer \n";
    modifyByPointer(&s);
    cout << "After modifyByPointer (in main): ";
    s.display();

    return 0;
}