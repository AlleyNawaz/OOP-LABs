#include <iostream>
#include <cmath>
using namespace std;

class Complex_No
{
private:
    float Real;
    float Imaginary;

public:
    void SetReIm(float r, float i)
    {
        Real = r;
        Imaginary = i;
    }

    void Display()
    {
        if (Imaginary >= 0)
            cout << Real << " + " << Imaginary << "i" << endl;
        else
            cout << Real << " - " << -Imaginary << "i" << endl;
    }

    float Magnitude()
    {
        return sqrt(Real * Real + Imaginary * Imaginary);
    }
};

int main()
{
    Complex_No c;
    c.SetReIm(3, 4);
    cout << "Complex Number: ";
    c.Display();
    cout << "Magnitude: " << c.Magnitude() << endl;
    return 0;
}