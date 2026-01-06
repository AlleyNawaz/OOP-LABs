#include <iostream>
using namespace std;

class Mammal
{
public:
    Mammal(void);
    ~Mammal(void);

    virtual void Move() const;
    virtual void Speak() const;

protected:
    int itsAge;
};

Mammal::Mammal(void): itsAge(1)
{
    cout << "Mammal constructor..." << endl;
}

Mammal::~Mammal(void)
{
    cout << "Mammal destructor..." << endl;
}

void Mammal::Move() const
{
    cout << "Mammal moves a step!" << endl;
}

void Mammal::Speak() const
{
    cout << "What does a mammal speak? Mammilian!" << endl;
}

class Dog : public Mammal
{
public:
    Dog()  { cout << "Dog constructor..." << endl; }
    ~Dog() { cout << "Dog destructor..." << endl; }

    void Move() const override  { cout << "Dog runs!" << endl; }
    void Speak() const override { cout << "Woof!" << endl; }
};

int main ()
{
    Mammal *pDog = new Dog;

    pDog->Move();
    pDog->Speak();

    delete pDog;

    return 0;
}
