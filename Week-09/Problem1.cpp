#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class Inventory {
private:
    int quant;
    int reorder;
    double price;
    char* descrip;

public:
    Inventory(int q, int r, double p, const char* d)
        : quant(q), reorder(r), price(p) {
        descrip = new char[strlen(d) + 1];
        strcpy(descrip, d);
    }

    ~Inventory() {
        delete[] descrip;
    }

    void print() {
        cout << "Description: " << descrip << endl;
        cout << "Quantity: " << quant << endl;
        cout << "Reorder Quantity: " << reorder << endl;
        cout << "Price per Unit: $" << fixed << setprecision(2) << price << endl;
    }

    int get_quant() { return quant; }
    int get_reorder() { return reorder; }
    double get_price() { return price; }
};

class Auto : public Inventory {
    char* manufacturer;

public:
    Auto(int q, int r, double p, const char* d, const char* man)
        : Inventory(q, r, p, d) {
        manufacturer = new char[strlen(man) + 1];
        strcpy(manufacturer, man);
    }

    ~Auto() {
        delete[] manufacturer;
    }

    void print() {
        cout << "\nAuto Details " << endl;
        Inventory::print();
        cout << "Manufacturer: " << manufacturer << endl;
    }
};

class Transmission : public Inventory {
    char* vendor;

public:
    Transmission(int q, int r, double p, const char* d, const char* ven)
        : Inventory(q, r, p, d) {
        vendor = new char[strlen(ven) + 1];
        strcpy(vendor, ven);
    }

    ~Transmission() {
        delete[] vendor;
    }

    void print() {
        cout << "\n Transmission Details" << endl;
        Inventory::print(); 
        cout << "Vendor: " << vendor << endl;
    }
};

int main() {
    Auto Car(5, 2, 15.545, "Four-wheel drive truck", "GM");
    Car.print();

    Transmission Transmissions(25, 10, 1789.98, "Automatic Gear Transmission", "Aztec Inc.");
    Transmissions.print();

    return 0;
}