#include <iostream>
#include <cmath>
using namespace std;

class Point
{
public:
    float x, y;
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(float a, float b)
    {
        x = a;
        y = b;
    }
};

float pDistance(Point p1, Point p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

float pathLength(Point path[], int size)
{
    float total = 0;
    for (int i = 0; i < size - 1; i++)
        total += pDistance(path[i], path[i + 1]);
    return total;
}

int main()
{
    Point path[4] = {Point(0, 0), Point(3, 4), Point(6, 8), Point(9, 12)};
    cout << "Total Path Length: " << pathLength(path, 4);
    return 0;
}