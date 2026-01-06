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
    friend ostream & operator<<(ostream &out, Complex &c);
};

    ostream & operator<<(ostream &out, Complex &c){
        out << c.real << " + " << c.imag << "i" << endl;
        return out;
    }

int main(){
    Complex c1(5,9);

    cout << c1;

    return 0;
}