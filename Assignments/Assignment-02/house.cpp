#include "house.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

House::House(int s, char b, char f) {
    if (s < 3) {
        size = 3;
    } else if (s > 37) {
        size = 37;
    } else {
        size = s;
    }
    
    if (b >= 33 && b <= 126) {
        border = b;
    } else {
        border = 'X';
    }
    
    if (f >= 33 && f <= 126) {
        fill = f;
    } else {
        fill = '*';
    }
}

int House::GetSize() const {
    return size;
}

int House::Perimeter() const {
    int triangleSide = size + 2;
    int trianglePerimeter = 3 * triangleSide;
    int squarePerimeter = 4 * size;
    return trianglePerimeter + squarePerimeter - size;
}

double House::Area() const {
    int triangleSide = size + 2;
    double triangleArea = (sqrt(3.0) / 4.0) * triangleSide * triangleSide;
    double squareArea = size * size;
    return triangleArea + squareArea;
}

void House::Grow() {
    if (size < 37) {
        size++;
    }
}

void House::Shrink() {
    if (size > 3) {
        size--;
    }
}

void House::SetBorder(char b) {
    if (b >= 33 && b <= 126) {
        border = b;
    } else {
        border = 'X';
    }
}

void House::SetFill(char f) {
    if (f >= 33 && f <= 126) {
        fill = f;
    } else {
        fill = '*';
    }
}

void House::Draw() const {
    int roofSize = size + 2;
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            cout << " ";
        }
        
        for (int j = 0; j <= 2 * i; j++) {
            if (j == 0 || j == 2 * i) {
                cout << border;
            } else {
                cout << fill;
            }
            
            if (j < 2 * i) {
                cout << " ";
            }
        }
        cout << endl;
    }
    
    for (int i = 0; i < roofSize; i++) {
        if (i == 0 || i == roofSize - 1) {
            cout << border;
        } else {
            cout << fill;
        }
        
        if (i < roofSize - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    for (int i = 0; i < size - 1; i++) {
        cout << " ";
        for (int j = 0; j < size; j++) {
            if (j == 0 || j == size - 1) {
                cout << border;
            } else {
                cout << fill;
            }
            
            if (j < size - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    
    cout << " ";
    for (int i = 0; i < size; i++) {
        cout << border;
        if (i < size - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

void House::Summary() const {
    cout << "House summary:" << endl;
    cout << "Base size: " << size << endl;
    cout << "Perimeter: " << Perimeter() << endl;
    cout << "Area: " << fixed << setprecision(2) << Area() << endl;
    Draw();
}