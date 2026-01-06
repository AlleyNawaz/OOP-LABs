#include <iostream>
#include <string>
using namespace std;

class Post {
protected:
    string Name;
    string To;
    float StampCost;
public:
    Post() {
        StampCost = 1;
        To = "";
    }
    void Read() {
        cout << "Enter Name: ";
        getline(cin, Name);
        cout << "Enter Receiver's Address: ";
        getline(cin, To);
        cout << "Enter Stamp Cost: ";
        cin >> StampCost;
    }
    void Print() {
        cout << "Name: " << Name << endl;
        cout << "Receiver's Address: " << To << endl;
        cout << "Stamp Cost: $" << StampCost << endl;
    }
    float TotalCost() {
        return StampCost;
    }
};

class RegisteredPost : public Post {
protected:
    float Weight;
    float RegistrationCost;
public:
    RegisteredPost() {
        Weight = 20;
        RegistrationCost = 10;
    }
    void Read() {
        Post::Read();
        cout << "Enter Weight (in grams): ";
        cin >> Weight;
        cout << "Enter Registration Cost: ";
        cin >> RegistrationCost;
    }
    void Print() {
        Post::Print();
        cout << "Weight: " << Weight << " g" << endl;
        cout << "Registration Cost: $" << RegistrationCost << endl;
    }
    float TotalCost() {
        return StampCost + RegistrationCost;
    }
};

int main() {
    RegisteredPost r;
    r.Read();
    r.Print();
    cout << "Total Cost: $" << r.TotalCost() << endl;
    return 0;
}