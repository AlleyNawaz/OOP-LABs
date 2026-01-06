/*
Classes:
Device (Base Class): Represents a generic smart device.
Attributes: device id, device name, state (ON/OFF).




*/

#include <iostream>
using namespace std;

class Device {
protected:
    int device_id;
    string device_name;
    bool state;   // ON = true, OFF = false


public:
    Device(int id, string name)
        : device_id(id), device_name(name), state(false) {}

    int getId() const {
        return device_id;
    }

    void turnOn() {
        state = true;
        cout << device_name << " is ON" << endl;
    }

    void turnOff() {
        state = false;
        cout << device_name << " is OFF" << endl;
    }

    virtual void triggerEvent(string eventType) = 0;

    virtual void showStatus() {
        cout << device_name << " status: "
             << (state ? "ON" : "OFF") << endl;
    }

    virtual ~Device() {}
};


Alarm (Derived Class):
Attributes: alarm time.
Overrides triggerEvent to set or reset the alarm.

class Light : public Device {
    int brightness;

public:
    Light(int id)
        : Device(id, "Light"), brightness(50) {}

    void triggerEvent(string eventType) override {
        if (eventType == "ON") turnOn();
        else if (eventType == "OFF") turnOff();
        else if (eventType == "BRIGHTNESS") {
            brightness += 10;
            cout << "Light brightness: " << brightness << endl;
        }
    }
};

Fan (Derived Class):
Attributes: speed level.
Overrides triggerEvento to adjust speed or toggle ON/OFF.
class Fan : public Device {
    int speed;

public:
    Fan(int id)
        : Device(id, "Fan"), speed(1) {}

    void triggerEvent(string eventType) override {
        if (eventType == "ON") turnOn();
        else if (eventType == "OFF") turnOff();
        else if (eventType == "SPEED") {
            speed++;
            cout << "Fan speed: " << speed << endl;
        }
    }
};

class Alarm : public Device {
    string alarmTime;

public:
    Alarm(int id)
        : Device(id, "Alarm"), alarmTime("Not Set") {}

    void triggerEvent(string eventType) override {
        if (eventType == "SET") {
            alarmTime = "7:00 AM";
            cout << "Alarm set at " << alarmTime << endl;
        }
        else if (eventType == "RESET") {
            alarmTime = "Not Set";
            cout << "Alarm reset" << endl;
        }
    }
};
Event Handling:
Implement an EventManager class:
Attributes: vector<Device*> devices to store all devices.
Methods:
gisterDevice to add devices to the system.
ndleEvent(device id, event type) to process events for specific devices.
Dynamic Binding:
Use virtual methods to achieve polymorphism for handling device-specific actions dynamically.
User Interaction:
Provide a menu-driven interface for:
Registering devices.
Triggering events for a specific device.
Viewing the status of all devices.
class EventManager {
    Device* devices[5];   // simple array
    int count;

public:
    EventManager() : count(0) {}

    void registerDevice(Device* d) {
        devices[count++] = d;
    }

    void handleEvent(int id, string eventType) {
        for (int i = 0; i < count; i++) {
            if (devices[i]->getId() == id) {
                devices[i]->triggerEvent(eventType);
                return;
            }
        }
        cout << "Device not found!" << endl;
    }

    void showAllStatus() {
        for (int i = 0; i < count; i++) {
            devices[i]->showStatus();
        }
    }
};

int main() {
    EventManager manager;

    Device* d1 = new Light(1);
    Device* d2 = new Fan(2);
    Device* d3 = new Alarm(3);

    manager.registerDevice(d1);
    manager.registerDevice(d2);
    manager.registerDevice(d3);

    manager.handleEvent(1, "ON");
    manager.handleEvent(1, "BRIGHTNESS");

    manager.handleEvent(2, "ON");
    manager.handleEvent(2, "SPEED");

    manager.handleEvent(3, "SET");

    cout << "\n--- Device Status ---" << endl;
    manager.showAllStatus();

    delete d1;
    delete d2;
    delete d3;

    return 0;
}