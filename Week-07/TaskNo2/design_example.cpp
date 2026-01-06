#include "design_example.h"
#include <iostream>
using namespace std;

Box::Box() {
    cout << "Constructor called." << endl;
}

Box::~Box() {
    cout << "Destructor called." << endl;
}

void Box::setDimensions(float l, float w, float h) {
    length = l;
    width = w;
    height = h;
}

float Box::calculateVolume() {
    return length * width * height;
}

float Box::calculateSurfaceArea() {
    return 2 * (length * width + width * height + height * length);
}

void Box::display() {
    cout << "Length = " << length << ", Width = " << width << ", Height = " << height << endl;
    cout << "Volume = " << calculateVolume() << endl;
    cout << "Surface Area = " << calculateSurfaceArea() << endl;
}