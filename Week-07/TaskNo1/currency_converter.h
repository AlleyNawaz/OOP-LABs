#ifndef CURRENCY_CONVERTER_H
#define CURRENCY_CONVERTER_H

class CurrencyConverter {
private:
    float usdRate;
    float eurRate;
    float gbpRate;

public:
    CurrencyConverter(float usd = 280, float eur = 300, float gbp = 350);
    void setRates(float usd, float eur, float gbp);
    float convertToUSD(float pkr);
    float convertToEUR(float pkr);
    float convertToGBP(float pkr);
    void displayRates();
};

#endif