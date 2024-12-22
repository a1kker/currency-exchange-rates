#include <iostream>
#include <vector>

#include "currency_exchange_rates.h"
#include "file_reader.h"

using namespace std;

int main()
{
    cout << "Laboratory work #8. GIT\n";
    cout << "Variant #4. Currency exchange rates\n";
    cout << "Author: Ilya Eliseev\n";

    try
    {
        std::vector<exchangeRate> rates = FileReader::readFromFile("data.txt");
        for (int i = 0; i < rates.size() - 1; i++)
        {
            cout << rates[i].bank_name << ' ';
            cout << rates[i].purchase << ' ';
            cout << rates[i].sale << ' ';
            cout << rates[i].bank_adress.city << ' ';
            cout << rates[i].bank_adress.street << ' ';
            cout << rates[i].bank_adress.number;
            cout << '\n';
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}