#include <iostream>
using namespace std;

class Student
{
    string name;
    int rollNumber;
    float marks[3];

public:
    Student(string n, int r, float m1, float m2, float m3)
    {
        name = n;
        rollNumber = r;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }
    float totalMarks()
    {
        return marks[0] + marks[1] + marks[2];
    }
    void display()
    {
        cout << "Name: " << name << ", Roll: " << rollNumber << ", Total Marks: " << totalMarks() << endl;
    }
    void updateMarks(float m1, float m2, float m3)
    {
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }
    void addBonusMarks()
    {
        marks[0] += 5;
        marks[1] += 5;
        marks[2] += 5;
    }
};

void showByValue(Student s)
{
    cout << "Inside showByValue (Before change): ";
    s.display();
    s.addBonusMarks();
    cout << "Inside showByValue (After change): ";
    s.display();
}

void showByReference(Student &s)
{
    cout << "Inside showByReference (Before change): ";
    s.display();
    s.addBonusMarks();
    cout << "Inside showByReference (After change): ";
    s.display();
}

void showByPointer(Student *s)
{
    cout << "Inside showByPointer (Before change): ";
    s->display();
    s->addBonusMarks();
    cout << "Inside showByPointer (After change): ";
    s->display();
}

int main()
{
    Student st("Ali", 101, 80, 85, 90);
    cout << "Original Student Data:\n";
    st.display();

    cout << "\nPass by Value \n";
    showByValue(st);
    cout << "After showByValue (in main): ";
    st.display();

    cout << "\nPass by Reference \n";
    showByReference(st);
    cout << "After showByReference (in main): ";
    st.display();

    cout << "\nPass by Pointer\n";
    showByPointer(&st);
    cout << "After showByPointer (in main): ";
    st.display();

    return 0;
}