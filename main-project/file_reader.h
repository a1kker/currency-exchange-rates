#ifndef FILE_READER_H
#define FILE_READER_H

#include "currency_exchange_rates.h"
#include <vector>
#include <string>

class FileReader {
public:   
    static std::vector<exchangeRate> readFromFile(const std::string& filename);
};

#endif