#include <iostream>
#include <vector>

#include "currency_exchange_rates.h"
#include "file_reader.h"
#include "filter.h"

void printRates(std::vector<exchangeRate>& rates) {
    for (int i = 0; i < rates.size(); i++)
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


int main()
{
    std::cout << "Laboratory work #8. GIT\n";
    std::cout << "Variant #4. Currency exchange rates\n";
    std::cout << "Author: Ilya Eliseev\n";
    std::cout << "Group: 24PIng_1D\n";

    std::vector<exchangeRate> rates = FileReader::readFromFile("data.txt");

    std::cout << "1. Filter by bank name(Belarusbank)" << std::endl;
    std::cout << "2. Filter by sale(<2.5)" << std::endl;

    int choice;
    std::cin >> choice;
    
    bool (*check_function)(exchangeRate rate) = NULL;


    switch (choice) {
    case 1:
        check_function = checkBelarusbank; //       
        std::cout << "**** BELARUSBANK ****\n\n";
        break;
    case 2:
        check_function = checkSaleLessThan2_5; //       
        std::cout << "****   sale<2.5   ****\n\n";
        break;

    default:
        std::cout << "Unknown operation";
        break;
    }

    if (check_function)
    {
        std::vector<exchangeRate> filtered = filter(rates, rates.size() - 1, check_function);
        printRates(filtered);
    }



    return 0;
}
