#include <iostream>
using namespace std;

class Coordinate
{
public:
    float latitude, longitude;
    void showCoordinate()
    {
        cout << "(" << latitude << ", " << longitude << ")";
    }
};

class Location
{
public:
    string name;
    Coordinate coord;
    void showLocation()
    {
        cout << "  Location: " << name << " ";
        coord.showCoordinate();
        cout << endl;
    }
};

class MapFeature
{
public:
    string featureType;
    Location loc[3];
    void showFeature()
    {
        cout << " Feature: " << featureType << endl;
        for (int i = 0; i < 3; i++)
            loc[i].showLocation();
    }
};

class Map
{
public:
    string mapName;
    MapFeature feature[2];
    void displayMap()
    {
        cout << "Map: " << mapName << endl;
        for (int i = 0; i < 2; i++)
            feature[i].showFeature();
    }
};

int main()
{
    Map m;
    m.mapName = "Islamabad City Map";
    m.feature[0].featureType = "Educational Institutes";
    m.feature[0].loc[0] = {"NUST", {33.643, 72.991}};
    m.feature[0].loc[1] = {"COMSATS", {33.736, 73.093}};
    m.feature[0].loc[2] = {"Air University", {33.718, 73.049}};
    m.feature[1].featureType = "Hospitals";
    m.feature[1].loc[0] = {"PIMS", {33.716, 73.066}};
    m.feature[1].loc[1] = {"Shifa", {33.694, 73.035}};
    m.feature[1].loc[2] = {"CDA Hospital", {33.684, 73.048}};
    m.displayMap();
}