#include <iostream>
#include "currency_converter.h"
using namespace std;

int main() {
    CurrencyConverter converter;
    converter.displayRates();

    float pkr;
    cout << "\nEnter amount in PKR: ";
    cin >> pkr;

    cout << "Equivalent in USD: " << converter.convertToUSD(pkr) << endl;
    cout << "Equivalent in EUR: " << converter.convertToEUR(pkr) << endl;
    cout << "Equivalent in GBP: " << converter.convertToGBP(pkr) << endl;

    char choice;
    cout << "\nDo you want to update rates? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        float usd, eur, gbp;
        cout << "Enter new rates (USD, EUR, GBP): ";
        cin >> usd >> eur >> gbp;
        converter.setRates(usd, eur, gbp);
        cout << "Rates updated successfully!\n";
        converter.displayRates();
    }

    return 0;
}