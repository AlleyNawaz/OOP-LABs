/*
Write a C++ program that:
1. Declares two integer variables.
2. Declares two pointers pointing to these variables.
3. Uses the pointers to swap the values of the two integers.
4. Prints the values before and after swapping.
*/
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    int *p1 = &a;
    int *p2 = &b;

    cout << "\nBefore swap: a = " << a << ", b = " << b << endl;

    // Swapping using pointers
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    cout << "After swap: a = " << a << ", b = " << b << endl;

    return 0;
}