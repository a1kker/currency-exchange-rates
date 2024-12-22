#ifndef CURRENCY_EXCHANGE_RATES_H
#define CURRENCY_EXCHANGE_RATES_H

#include <string>

struct adress {
    std::string city;
    std::string street;
    int number;
};

struct exchangeRate {
    std::string bank_name;
    double purchase;
    double sale;
    adress bank_adress;
};

#endif