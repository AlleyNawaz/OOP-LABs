#include <iostream>
#include "house.h"

using namespace std;

int main() {
    House h1(5);
    cout << "House 1 (size 5, default border and fill):" << endl;
    h1.Draw();
    cout << endl;
    
    House h2(7, '#', 'o');
    cout << "House 2 (size 7, border '#', fill 'o'):" << endl;
    h2.Draw();
    cout << endl;
    
    House h3(2);
    cout << "House 3 (requested size 2, should be 3):" << endl;
    cout << "Actual size: " << h3.GetSize() << endl;
    h3.Draw();
    cout << endl;
    
    House h4(40);
    cout << "House 4 (requested size 40, should be 37):" << endl;
    cout << "Actual size: " << h4.GetSize() << endl;
    cout << endl;
    
    House h5(5);
    cout << "House 5 initial (size 5):" << endl;
    h5.Draw();
    
    h5.Grow();
    cout << "\nAfter Grow (size should be 6):" << endl;
    h5.Draw();
    
    h5.Shrink();
    h5.Shrink();
    cout << "\nAfter 2 Shrinks (size should be 4):" << endl;
    h5.Draw();
    cout << endl;
    
    House h6(8, '+', '-');
    cout << "House 6 Summary:" << endl;
    h6.Summary();
    cout << endl;
    
    House h7(6);
    cout << "House 7 before character changes:" << endl;
    h7.Draw();
    
    h7.SetBorder('@');
    h7.SetFill('=');
    cout << "\nAfter SetBorder('@') and SetFill('='):" << endl;
    h7.Draw();
    
    h7.SetBorder('~' + 1);
    h7.SetFill(' ' - 1);
    cout << "\nAfter invalid character attempts (should revert to X and *):" << endl;
    h7.Draw();
    cout << endl;
    
    House h8(10);
    cout << "House 8 (size 10):" << endl;
    cout << "Perimeter: " << h8.Perimeter() << endl;
    cout << "Area: " << h8.Area() << endl;
    
    return 0;
}