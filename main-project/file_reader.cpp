#include "file_reader.h"
#include "constants.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

std::vector<exchangeRate> FileReader::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<exchangeRate> rates;

    if (!file.is_open()) {
        std::cerr << " Ошибка открытия файла " << filename << "\n";
        return rates;
    }

    std::string line;
    while (std::getline(file, line) && rates.size() < MAX_FILE_ROWS_COUNT) {
        if (line.length() > MAX_STRING_SIZE) {
            std::cerr << "Ошибка: строка превышает " << MAX_STRING_SIZE << " символов.\n";
            continue;
        }

        std::istringstream iss(line);
        exchangeRate rate;

        iss >> rate.bank_name >> rate.purchase >> rate.sale >> rate.bank_adress.city >> rate.bank_adress.street >> rate.bank_adress.number;
        
        rates.push_back(rate);
    }

    file.close();
    return rates;
}