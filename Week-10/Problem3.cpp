#include <iostream>
using namespace std;

class Staff {
private:
    string name;
    int id;
    double salary;

public:

    Staff() {
        name = "Not set";
        id = 0;
        salary = 0;
        cout << "Default staff profile created with placeholder values." << endl;
    }

    Staff(string n) {
        name = n;
        id = 0;
        salary = 0;
        cout << "Staff registered with name only." << endl;
    }

    Staff(string n, int i) {
        name = n;
        id = i;
        salary = 0;
        cout << "Staff registered with name and ID." << endl;
    }

    Staff(string n, int i, double s) {
        name = n;
        id = i;
        if (s < 0) {
            salary = 0;
            cout << "Invalid salary entered. Setting salary to 0." << endl;
        } else {
            salary = s;
            cout << "Staff registered with full details." << endl;
        }
    }

    void setSalary(double amt) {
        if (amt > 0) {
            salary = amt;
            cout << "Salary updated successfully." << endl;
        } else {
            cout << "Salary not updated. Invalid amount." << endl;
        }
    }

    void display() const {
        cout << "Staff Name: " << name << endl;
        cout << "Staff ID: " << id << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    Staff S1;
    Staff S2("Hamza");
    Staff S3("Abaid", 102);    
    Staff S4("Dr. Ejaz", 500, 80000);

    S3.setSalary(25000);

    S1.display();
    S2.display();
    S3.display();
    S4.display();

    return 0;
}