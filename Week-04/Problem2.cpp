#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
    string name;
    int age;
    float salary;
    string department;
    Employee() {}
    Employee(string n, int a, float s, string d)
    {
        name = n;
        age = a;
        salary = s;
        department = d;
    }
    void display()
    {
        cout << "Name: " << name << ", Age: " << age << ", Salary: " << salary << ", Department: " << department << endl;
    }
};

int main()
{
    Employee e1("Ali", 22, 60000, "IT");
    Employee e2("Ahsan", 24, 75000, "HR");
    Employee e3("Fatima", 26, 90000, "Finance");
    Employee e4("Sara", 23, 65000, "IT");
    Employee e5("Bilal", 27, 85000, "Finance");
    Employee e6("Zain", 25, 70000, "Marketing");

    Employee employees[] = {e1, e2, e3, e4, e5, e6};
    int totalEmployees = 6;

    cout << "All Employees:\n";
    for (int i = 0; i < totalEmployees; i++)
        employees[i].display();

    cout << "\nTotal Employees: " << totalEmployees << endl;

    Employee highest = employees[0];
    for (int i = 1; i < totalEmployees; i++)
        if (employees[i].salary > highest.salary)
            highest = employees[i];

    cout << "\nEmployee with Highest Salary:\n";
    highest.display();

    string dept;
    cout << "\nEnter Department to Search: ";
    cin >> dept;

    cout << "\nEmployees in " << dept << " Department:\n";
    bool found = false;
    for (int i = 0; i < totalEmployees; i++)
    {
        if (employees[i].department == dept)
        {
            employees[i].display();
            found = true;
        }
    }
    if (!found)
        cout << "No employees found in this department.";
    return 0;
}