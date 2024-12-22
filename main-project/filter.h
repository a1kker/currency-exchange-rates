#ifndef FILTER_H
#define FILTER_H

#include <vector>

#include "currency_exchange_rates.h"

std::vector<exchangeRate> filter(std::vector<exchangeRate>& array, int size, bool (*check)(exchangeRate rate));

bool checkSaleLessThan2_5(exchangeRate rate);

bool checkBelarusbank(exchangeRate rate);

#endif
