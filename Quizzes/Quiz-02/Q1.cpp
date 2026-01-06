/*
Q1. Planet Class – Surface Gravity

Task:
Design a class named Planet that models a celestial body.

Specifications:
Data Members => (string name, double radius (in km), double mass (in kg))

Constructors => A parameterized constructor to initialize all data members

Member Functions:
double surfaceGravity()
Calculates surface gravity using the formula:

g = {G x mass}/{radius^2}
Where
G = 6.674 x 10^{-11}
void display()
Prints the planet name and calculated surface gravity

Main Requirements:
Create two planet objects (e.g., Earth and Mars)
Display their surface gravities
Compare which planet has stronger gravity
*/

#include <iostream>
#include <cmath>
using namespace std;

class Planet {
private:
    string name;
    double radius;  // in km
    double mass;    // in kg
    const double G = 6.674e-11; // gravitational constant

public:
    // Parameterized constructor
    Planet(string n, double r, double m) {
        name = n;
        radius = r * 1000; // converting km → meters
        mass = m;
    }

    // Calculate surface gravity
    double surfaceGravity() {
        return (G * mass) / (radius * radius);
    }

    // Display details
    void display() {
        cout << "Planet: " << name << endl;
        cout << "Surface Gravity: " << surfaceGravity() << " m/s^2\n\n";
    }
};

int main() {
    Planet earth("Earth", 6371, 5.972e24);
    Planet mars("Mars", 3389.5, 6.39e23);

    earth.display();
    mars.display();

    if (earth.surfaceGravity() > mars.surfaceGravity())
        cout << "Earth has stronger gravity than Mars.\n";
    else
        cout << "Mars has stronger gravity than Earth.\n";

    return 0;
}