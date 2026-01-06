#include<iostream>
using namespace std;

class Complex{
private:
    int real;
    int imag;

public:
    Complex(int r = 0, int i = 0){
        real = r;
        imag = i;
    }

    friend istream & operator>>(istream &in, Complex &c);
    friend ostream & operator<<(ostream &out, Complex &c);
};

// extraction operator
istream & operator>>(istream &in, Complex &c){
    in >> c.real >> c.imag;
    return in;
}

// insertion operator
ostream & operator<<(ostream &out, Complex &c){
    out << c.real << " + " << c.imag << "i";
    return out;
}

int main(){
    Complex c1;

    cin >> c1;
    cout << c1;

    return 0;
}
