#include <iostream>
#include <vector>

#include "currency_exchange_rates.h"
#include "file_reader.h"


int main()
{
    std::cout << "Laboratory work #8. GIT\n";
    std::cout << "Variant #4. Currency exchange rates\n";
    std::cout << "Author: Ilya Eliseev\n";

    try
    {
        std::vector<exchangeRate> rates = FileReader::readFromFile("data.txt");
        for (int i = 0; i < rates.size() - 1; i++)
        {
            std::cout << "Bank........: ";
            std::cout << rates[i].bank_name;
            std::cout << '\n';

            std::cout << "Purchase....: ";
            std::cout << rates[i].purchase;
            std::cout << '\n';

            std::cout << "Sale........: ";
            std::cout << rates[i].sale;
            std::cout << '\n';

            std::cout << "City........: ";
            std::cout << rates[i].bank_adress.city;
            std::cout << '\n';

            std::cout << "Street......: ";
            std::cout << rates[i].bank_adress.street;
            std::cout << '\n';

            std::cout << "House number: ";
            std::cout << rates[i].bank_adress.number;
            std::cout << '\n';
        }
    }
    catch (const char* error)
    {
        std::cout << error << '\n';
    }
    return 0;
}