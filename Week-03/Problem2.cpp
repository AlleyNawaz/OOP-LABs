#include <iostream>
#include <cstring>
using namespace std;

class Student
{
private:
    char name[50];
    int rollno;
    double marks[5];
    float percentage;

public:
    void SetData()
    {
        cout << "Enter student name: ";
        cin.ignore();
        cin.getline(name, 50);

        cout << "Enter roll number: ";
        cin >> rollno;

        cout << "Enter marks for 5 subjects:\n";
        for (int i = 0; i < 5; i++)
        {
            cout << "Subject " << (i + 1) << ": ";
            cin >> marks[i];
        }
    }

    void CalculatePercentage()
    {
        double total = 0;
        for (int i = 0; i < 5; i++)
        {
            total += marks[i];
        }
        percentage = (total / 500) * 100;
    }

    void Grade()
    {
        CalculatePercentage();

        cout << "\n--- Student Report ---\n";
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollno << endl;
        cout << "Percentage: " << percentage << "%" << endl;

        // Display grade based on percentage
        if (percentage >= 90)
        {
            cout << "Grade: A+" << endl;
        }
        else if (percentage >= 80)
        {
            cout << "Grade: A" << endl;
        }
        else if (percentage >= 70)
        {
            cout << "Grade: B" << endl;
        }
        else if (percentage >= 60)
        {
            cout << "Grade: C" << endl;
        }
        else if (percentage >= 50)
        {
            cout << "Grade: D" << endl;
        }
        else
        {
            cout << "Grade: F (Fail)" << endl;
        }
    }
};

int main()
{
    Student student;

    student.SetData();

    student.Grade();

    return 0;
}