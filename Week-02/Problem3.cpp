/*
  Write a C++ program that:
1. Declares a static array of 7 integers.
2. Declares a pointer to the array.
3. Reverses the array in-place using pointer arithmetic.
4. Prints the reversed array.
*/
#include <iostream>
using namespace std;

int main()
{
    int arr[7];
    const int SIZE = 7;
    int *ptr = arr;

    cout << "Enter 7 integers: ";
    for (int i = 0; i < SIZE; i++)
    {
        cin >> *(ptr + i);
    }

    cout << "\nOriginal array: ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    int *start = ptr;
    int *end = ptr + SIZE - 1;

    while (start < end)
    {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    cout << "Reversed array: ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    return 0;
}