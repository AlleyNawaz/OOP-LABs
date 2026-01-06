#include <iostream>
#include <string>
using namespace std;

int calculateAge(int birthYear, int currentYear)
{
    return currentYear - birthYear;
}

float calculateAggregate(float fsc, float test)
{
    return (0.75 * fsc) + (0.25 * test);
}

string scholarship(float testPercent)
{
    if (testPercent >= 90)
        return "100%";
    else if (testPercent >= 80)
        return "50%";
    else
        return "Nil";
}

int main()
{
    string name, cnic, dob;
    float fsc, test;
    int birthDay, birthMonth, birthYear;
    char dash;
    int currentYear = 2025;

    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter CNIC: ";
    getline(cin, cnic);
    cout << "Enter DOB (dd-mm-yyyy): ";
    cin >> birthDay >> dash >> birthMonth >> dash >> birthYear;
    dob = to_string(birthDay) + "-" + to_string(birthMonth) + "-" + to_string(birthYear);

    cout << "Enter NUST Test %: ";
    cin >> test;
    cout << "Enter FSc %: ";
    cin >> fsc;

    int age = calculateAge(birthYear, currentYear);
    float aggregate = calculateAggregate(fsc, test);
    bool admission = (age > 16 && age < 25 && aggregate > 75);

    cout << "\nName:\t\t" << name << endl;
    cout << "CNIC:\t\t" << cnic << endl;
    cout << "DOB:\t\t" << dob << endl;
    cout << "Test:\t\t" << test << " %" << endl;
    cout << "FSc:\t\t" << fsc << " %" << endl;

    if (admission)
    {
        cout << "Admission:\tYes" << endl;
        cout << "Scholarship:\t" << scholarship(test) << endl;
    }
    else
    {
        cout << "Admission:\tNo" << endl;
        cout << "Scholarship:\tNil" << endl;
    }

    return 0;
}