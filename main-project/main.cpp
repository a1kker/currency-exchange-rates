#include <iostream>
#include <vector>

#include "currency_exchange_rates.h"
#include "file_reader.h"
#include "filter.h"
#include "sort.h"

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
    std::cout << "3. Sort" << std::endl;

    int choice;
    std::cin >> choice;
    
    bool (*check_function)(exchangeRate rate) = NULL;


    switch (choice) {
    case 1:
        check_function = checkSberbank;
        std::cout << "**** Sberbank **** \n\n";
        break;
    case 2:
        check_function = checkBelarusbank; //       
        std::cout << "**** BELARUSBANK ****\n\n";
        break;
    case 3:
        check_function = checkSaleLessThan2_5; //       
        std::cout << "****   sale<2.5   ****\n\n";
        break;

    case 4:
        int sortMethod, sortCriterion;
        std::cout << "1.Bubble Sort" << std::endl;
        std::cout << "2.Merge Sort" << std::endl;
        std::cin >> sortMethod;

        std::cout << "1. By descending difference between sell and buy rates" << std::endl;
        std::cout << "2. By ascending bank name and address" << std::endl;
        std::cin >> sortCriterion;

        sortRates(rates, sortMethod, sortCriterion);
        printRates(rates);

    default:
        std::cout << "Unknown operation";
    }

    if (check_function)
    {
        std::vector<exchangeRate> filtered = filter(rates, rates.size(), check_function);
        printRates(filtered);
    }



    return 0;
}
