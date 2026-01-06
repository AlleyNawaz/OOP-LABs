#ifndef DESIGN_EXAMPLE_H
#define DESIGN_EXAMPLE_H

class Box {
private:
    float length;
    float width;
    float height;

public:
    Box();
    ~Box();
    void setDimensions(float l, float w, float h);
    float calculateVolume();
    float calculateSurfaceArea();
    void display();
};

#endif