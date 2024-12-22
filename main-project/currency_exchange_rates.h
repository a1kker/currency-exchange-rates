#ifndef CURRENCY_EXCHANGE_RATES_H
#define CURRENCY_EXCHANGE_RATES_H

#include <string>

struct adress {
    std::string street;
    int number;
};

struct exchangeRate {
    std::string bank_name;
    int purchase;
    int sale;
    adress bank_adress;
};

#endif