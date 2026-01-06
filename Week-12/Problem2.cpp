#include <iostream>
using namespace std;

class Mammal {
public:
    virtual void Move() {
        cout << "Mammal moves (generic)" << endl;
    }

    virtual void Speak() {
        cout << "Mammal sound" << endl;
    }

    virtual ~Mammal() {
        cout << "Mammal destroyed" << endl;
    }
};

class Dog : public Mammal {
public:
    void Move() override {
        cout << "Dog runs" << endl;
    }

    void Speak() override {
        cout << "Woof!" << endl;
    }

    void WagTail() {
        cout << "Dog wags tail" << endl;
    }

    ~Dog() override {
        cout << "Dog destroyed" << endl;
    }
};

class Cat : public Mammal {
public:
    void Move() override {
        cout << "Cat sneaks" << endl;
    }

    void Speak() override {
        cout << "Meow" << endl;
    }

    ~Cat() override {
        cout << "Cat destroyed" << endl;
    }
};

class Horse : public Mammal {
public:
    void Move() override {
        cout << "Horse gallops" << endl;
    }

    void Speak() override {
        cout << "Neigh" << endl;
    }

    ~Horse() override {
        cout << "Horse destroyed" << endl;
    }
};

class GuineaPig : public Mammal {
public:
    void Move() override {
        cout << "Guinea pig scurries" << endl;
    }

    void Speak() override {
        cout << "Weep weep" << endl;
    }

    ~GuineaPig() override {
        cout << "GuineaPig destroyed" << endl;
    }
};

int main ()
{
   Mammal* theArray[5];
   Mammal* ptr;
   int choice, i;

   for (i = 0; i < 5; i++)
   {
      cout << "(1)dog (2)cat (3)horse (4)guinea pig: ";
      cin >> choice;

      switch (choice)
      {
         case 1: ptr = new Dog; break;
         case 2: ptr = new Cat; break;
         case 3: ptr = new Horse; break;
         case 4: ptr = new GuineaPig; break;
         default: ptr = new Mammal; break;
      }
      theArray[i] = ptr;
   }

   cout << "\nSpeak for each Mammal (polymorphic)\n";
   for (i = 0; i < 5; i++)
      theArray[i]->Speak();

   cout << "\nExample WagTail (only if element 0 is a Dog)\n";
   Dog* maybeDog = dynamic_cast<Dog*>(theArray[0]);
   if (maybeDog) {
       maybeDog->WagTail();
   } else {
       cout << "Element 0 is not a Dog; cannot call WagTail()\n";
   }

   cout << "\nDeleting objects\n";
   for (i = 0; i < 5; i++)
       delete theArray[i];

   return 0;
}
