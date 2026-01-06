#include <iostream>
using namespace std;

class Engine
{
public:
    int horsepower;
    string type;
    void startEngine()
    {
        cout << "Engine started!" << endl;
    }
};

class FuelTank
{
public:
    float capacity, fuelLevel;
    void refuel(float liters)
    {
        if (fuelLevel + liters <= capacity)
            fuelLevel += liters;
        else
            fuelLevel = capacity;
    }
    bool consumeFuel(float amount)
    {
        if (fuelLevel >= amount)
        {
            fuelLevel -= amount;
            return true;
        }
        return false;
    }
};

class Car
{
public:
    string model;
    Engine engine;
    FuelTank tank;
    void startCar()
    {
        if (tank.fuelLevel > 0)
            engine.startEngine();
        else
            cout << "Not enough fuel to start car!" << endl;
    }
    void drive(float distance)
    {
        float requiredFuel = distance * 0.1;
        if (tank.consumeFuel(requiredFuel))
        {
            cout << "Driving " << distance << " km…" << endl;
            cout << "Fuel left: " << tank.fuelLevel << "L" << endl;
            float efficiency = distance / requiredFuel;
            cout << "Fuel Efficiency: " << efficiency << " km/L" << endl;
            if (tank.fuelLevel < tank.capacity * 0.1)
                cout << "Warning: Fuel below 10%!" << endl;
        }
        else
            cout << "Insufficient fuel to drive!" << endl;
    }
    void showStatus()
    {
        cout << "Car: " << model << endl;
        cout << "Fuel Level: " << tank.fuelLevel << "L" << endl;
    }
};

int main()
{
    Car c;
    c.model = "Civic 2023";
    c.engine = {180, "Petrol"};
    c.tank = {50, 20};
    c.showStatus();
    c.startCar();
    c.drive(50);
}