#ifndef HOUSE_H
#define HOUSE_H

using namespace std;

class House {
private:
    int size;
    char border;
    char fill;

public:
    House(int s, char b = 'X', char f = '*');
    
    int GetSize() const;
    int Perimeter() const;
    double Area() const;
    
    void Grow();
    void Shrink();
    
    void SetBorder(char b);
    void SetFill(char f);
    
    void Draw() const;
    void Summary() const;
};

#endif