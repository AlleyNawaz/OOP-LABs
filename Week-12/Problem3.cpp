#include <iostream>
using namespace std;

class Shape {
public:
    virtual void Draw() {
        cout << "Drawing Shape" << endl;
    }

    ~Shape() {
        cout << "Shape destroyed" << endl;
    }
};

class Circle : public Shape {
public:
    void Draw() override {
        cout << "Drawing Circle" << endl;
    }

    ~Circle() {
        cout << "Circle destroyed" << endl;
    }
};

int main() {
    Shape* s = new Circle();
    s->Draw();
    delete s;
    
    return 0;
}
