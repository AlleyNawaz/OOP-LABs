#include "currency_converter.h"
#include <iostream>
using namespace std;

CurrencyConverter::CurrencyConverter(float usd, float eur, float gbp) {
    usdRate = usd;
    eurRate = eur;
    gbpRate = gbp;
}

void CurrencyConverter::setRates(float usd, float eur, float gbp) {
    usdRate = usd;
    eurRate = eur;
    gbpRate = gbp;
}

float CurrencyConverter::convertToUSD(float pkr) {
    return pkr / usdRate;
}

float CurrencyConverter::convertToEUR(float pkr) {
    return pkr / eurRate;
}

float CurrencyConverter::convertToGBP(float pkr) {
    return pkr / gbpRate;
}

void CurrencyConverter::displayRates() {
    cout << "Current Rates:" << endl;
    cout << "1 USD = " << usdRate << " PKR" << endl;
    cout << "1 EUR = " << eurRate << " PKR" << endl;
    cout << "1 GBP = " << gbpRate << " PKR" << endl;
}