#include "filter.h"
#include <cstring>
#include <iostream>

std::vector<exchangeRate> filter(std::vector<exchangeRate>& array, int size, bool (*check)(exchangeRate rate))
{
	std::vector<exchangeRate> result;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result.push_back(array[i]);
		}
	}
	return result;
}

bool checkSaleLessThan2_5(exchangeRate rate)
{
	return rate.sale < 2.5;
}

bool checkBelarusbank(exchangeRate rate)
{
	return strcmp(rate.bank_name.c_str(), "Belarusbank") == 0;
}

