#include <iostream>
using namespace std;

int main()
{
    double deposit, annualRate;

    cout << "This program will project how much you can earn by investing money in a high-yield savings account over a 3-month period.\n";

    cout << "Enter your initial deposit amount: ";
    cin >> deposit;

    cout << "Enter the annual interest rate (e.g. 0.12 for 12%): ";
    cin >> annualRate;

    double monthlyRate = annualRate / 12;
    double balance = deposit;

    cout << "\nCalculating...\n";
    cout << "Month\tStarting Balance\tInterest\tEnding Balance\n";

    for (int month = 1; month <= 3; month++)
    {
        double interest = balance * monthlyRate;
        double endingBalance = balance + interest;

        cout << month << "\t"
             << balance << "\t\t"
             << interest << "\t\t"
             << endingBalance << endl;

        balance = endingBalance;
    }

    return 0;
}