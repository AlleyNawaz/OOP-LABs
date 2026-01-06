#include <iostream>
#include "design_example.h"
using namespace std;

int main() {
    Box box1, box2;

    box1.setDimensions(4, 3, 2);
    cout << "\nBox 1:" << endl;
    box1.display();

    box2.setDimensions(6, 4, 3);
    cout << "\nBox 2:" << endl;
    box2.display();

    return 0;
}