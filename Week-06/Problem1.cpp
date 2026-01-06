#include <iostream>
using namespace std;

class Faculty
{
public:
    string facultyName, designation;
    int publications;
    void showFaculty()
    {
        cout << facultyName << " (" << designation << ") - Publications: " << publications << endl;
    }
};

class Department
{
public:
    string deptName;
    Faculty faculty[3];
    void inputFaculty()
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "Enter Faculty " << i + 1 << " Name: ";
            getline(cin, faculty[i].facultyName);
            cout << "Enter Designation: ";
            getline(cin, faculty[i].designation);
            cout << "Enter Publications: ";
            cin >> faculty[i].publications;
            cin.ignore();
        }
    }
    void showDepartment()
    {
        cout << "Department: " << deptName << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "  Faculty " << i + 1 << ": ";
            faculty[i].showFaculty();
        }
    }
};

class University
{
public:
    string uniName, location;
    Department dept;
    void showUniversity()
    {
        cout << "University: " << uniName << endl;
        cout << "Location: " << location << endl;
        dept.showDepartment();
    }
};

int main()
{
    University u;
    u.uniName = "NUST";
    u.location = "Islamabad";
    u.dept.deptName = "IGIS";
    u.dept.faculty[0] = {"Dr. Ayesha", "Professor", 25};
    u.dept.faculty[1] = {"Mr. Bilal", "Lecturer", 10};
    u.dept.faculty[2] = {"Ms. Sara", "Assistant Professor", 18};
    u.showUniversity();
}