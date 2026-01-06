#include <iostream>
using namespace std;

class Drone {
private:
    int droneID;
    double batteryLevel;

public:
    Drone(int id, double battery) {
        droneID = id;
        batteryLevel = battery;
    }

    void setBattery(double b) {
        batteryLevel = b;
    }

    void setDroneID(int id) {
        droneID = id;
    }

    double getBattery() {
        return batteryLevel;
    }

    void displayStatus() {
        cout << "Drone ID: " << droneID << endl;
        cout << "Battery: " << batteryLevel << "%" << endl;
    }

    friend void transferPower(Drone &donor, Drone &receiver, double percent);
};

void transferPower(Drone &donor, Drone &receiver, double percent) {
    if (donor.batteryLevel < percent) {
        cout << "Not enough battery to transfer!" << endl;
        return;
    }
    donor.batteryLevel -= percent;
    receiver.batteryLevel += percent;

    cout << "\nPower transferred successfully!\n";
}

int main() {
    Drone d1(101, 80);
    Drone d2(102, 20);

    cout << "Before transfer:\n";
    d1.displayStatus();
    d2.displayStatus();

    transferPower(d1, d2, 15);

    cout << "\nAfter transfer:\n";
    d1.displayStatus();
    d2.displayStatus();
}