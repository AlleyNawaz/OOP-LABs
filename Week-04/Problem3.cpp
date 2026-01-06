#include <iostream>
using namespace std;

class Room
{
    int length, width, height;

public:
    Room()
    {
        length = 0;
        width = 0;
        height = 0;
    }
    Room(int l, int w, int h)
    {
        length = l;
        width = w;
        height = h;
    }
    ~Room() { cout << "Room object destroyed" << endl; }
    int volume() { return length * width * height; }
    int surfaceArea() { return 2 * (length * width + width * height + height * length); }
    bool canFitInside(Room other)
    {
        return (length < other.length && width < other.width && height < other.height);
    }
};

int main()
{
    Room r1(10, 12, 8);
    int l, w, h;
    cout << "Enter length, width, and height of Room 2: ";
    cin >> l >> w >> h;
    Room r2(l, w, h);

    cout << "\nRoom 1 Volume: " << r1.volume() << ", Surface Area: " << r1.surfaceArea() << endl;
    cout << "Room 2 Volume: " << r2.volume() << ", Surface Area: " << r2.surfaceArea() << endl;

    if (r1.canFitInside(r2))
        cout << "\nRoom 1 can fit inside Room 2." << endl;
    else
        cout << "\nRoom 1 cannot fit inside Room 2." << endl;

    return 0;
}