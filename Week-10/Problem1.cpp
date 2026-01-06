#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:

    Rectangle() {
        length = 1;
        width = 1;
        cout << "Default constructor: Creating a standard 1x1 room." << endl;
    }

    Rectangle(double l, double w) {
        if (l <= 0 || w <= 0) {
            length = 1;
            width = 1;
            cout << "Invalid dimensions! Using default room size 1x1." << endl;
        } else {
            length = l;
            width = w;
            cout << "Custom room created using parameterized constructor." << endl;
        }
    }

    Rectangle(const Rectangle &obj) {
        if (obj.length * obj.width == 0) {
            length = 1;
            width = 1;
            cout << "Cannot copy a room with zero area. Using default dimensions." << endl;
        } else {
            length = obj.length;
            width = obj.width;
            cout << "Copy constructor: Room copied successfully." << endl;
        }
    }

    double calculateArea() const {
        return length * width;
    }

    void display() const {
        cout << "Length: " << length << ", Width: " << width 
             << ", Area: " << calculateArea() << endl;
    }

    inline bool isSquare() const {
        return length == width;
    }
};

int main() {
    Rectangle room1;
    Rectangle room2(5, 3);
    Rectangle room3(-5, 0);

    Rectangle room4(room2);

    Rectangle room5(room3);

    return 0;
}