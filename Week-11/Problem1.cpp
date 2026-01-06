#include <iostream>
using namespace std;

class Complex {
private:
    float real, imag;

public:
    Complex() {
        real = 0;
        imag = 0;
    }

    Complex(float r, float i) {
        real = r;
        imag = i;
    }

    void show() {
        cout << real << " + " << imag << "i" << endl;
    }

    friend Complex addComplex(Complex c1, Complex c2);

    friend Complex operator+(Complex c1, Complex c2);
};

Complex addComplex(Complex c1, Complex c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

Complex operator+(Complex c1, Complex c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

int main() {
    Complex c1(3, 4);
    Complex c2(2, 5);

    cout << "Using friend function: ";
    Complex c3 = addComplex(c1, c2);
    c3.show();

    cout << "Using operator overloading: ";
    Complex c4 = c1 + c2;
    c4.show();
}