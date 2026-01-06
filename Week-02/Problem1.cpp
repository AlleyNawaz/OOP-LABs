/*
Write a C++ program that:
1. Declares a pointer to an integer.
2. Declares a fixed-size array of integers
3. Uses the pointer to input values into the array (through pointer arithmetic).
4. Prints out the values in the array and the addresses of each element using the pointer.
*/
#include <iostream>
using namespace std;

int main()
{
    int *ptr;
    const int SIZE = 5;
    int arr[SIZE];
    ptr = arr;

    cout << "Enter " << SIZE << " integers: ";
    for (int i = 0; i < SIZE; i++)
    {
        cin >> *(ptr + i);
    }

    cout << "\nArray values and addresses:" << endl;
    cout << "Index\tValue\tAddress" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << i << "\t" << *(ptr + i) << "\t" << (ptr + i) << endl;
    }

    return 0;
}