#include <vector>
#include <string>
#include "currency_exchange_rates.h"
#include "sort.h"

using namespace std;

// ������� ��������� �� �������� ������� ����� ���������� ������� � �������
bool compareBySellBuyDifference(const exchangeRate& a, const exchangeRate& b) {
    double diffA = a.sale - a.purchase;
    double diffB = b.sale - b.purchase;
    return diffA < diffB;
}

// ������� ��������� �� ����������� �������� �����, � ����� �� ������
bool compareByBankAndAddress(const exchangeRate& a, const exchangeRate& b) {
    // ���������� �������� ������
    int BankNameComparison = strcmp(a.bank_name.c_str(), b.bank_name.c_str());
    int CityComparison = strcmp(a.bank_adress.city.c_str(), b.bank_adress.city.c_str());
    int StreetComparison = strcmp(a.bank_adress.street.c_str(), b.bank_adress.street.c_str());

    if (BankNameComparison == 0) {
        if (CityComparison == 0) {
            if (StreetComparison == 0) {
                return a.bank_adress.number > b.bank_adress.number;
            }
            return StreetComparison;
        }
        return CityComparison;
        }
    return BankNameComparison;
    
    }


// ���������� ������� (Bubble Sort)
void bubbleSort(std::vector<exchangeRate>& arr, int size, bool (*compare)(const exchangeRate&, const exchangeRate&)) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (compare(arr[j], arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// ������� ��� ������� ���� �������
void merge(std::vector<exchangeRate>& rates, int left, int mid, int right, bool (*compare)(const exchangeRate&, const exchangeRate&)) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    std::vector<exchangeRate> leftRates(leftSize);
    std::vector<exchangeRate> rightRates(rightSize);

    // �������� ������ � ��������� �������
    for (int i = 0; i < leftSize; i++)
        leftRates[i] = rates[left + i];
    for (int j = 0; j < rightSize; j++)
        rightRates[j] = rates[mid + 1 + j];

    // ������� ��������� �������� ������� � rates[left..right]
    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (compare(leftRates[i], rightRates[j])) {
            rates[k] = leftRates[i];
            i++;
        }
        else { 
            rates[k] = rightRates[j];
            j++;
        }
        k++;
    }

    // �������� ���������� �������� (���� ����)
    while (i < leftSize) {
        rates[k] = leftRates[i];
        i++;
        k++;
    }
    while (j < rightSize) {
        rates[k] = rightRates[j];
        j++;
        k++;
    }
}

// �������� ������� ���������� ��������
void mergeSort(std::vector<exchangeRate>& rates, int left, int right, bool (*compare)(const exchangeRate&, const exchangeRate&)) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // ���������� ��������� ��� ��������
        mergeSort(rates, left, mid, compare);
        mergeSort(rates, mid + 1, right, compare);

        // ������� ��������������� ��������
        merge(rates, left, mid, right, compare);
    }
}


void sortRates(std::vector<exchangeRate>& arr, int sortMethod, int sortCriterion) {
    if (sortMethod == 1 && sortCriterion == 1)
        bubbleSort(arr, arr.size() - 1, compareBySellBuyDifference);
    else if (sortMethod == 1 && sortCriterion == 2)
        bubbleSort(arr, arr.size() - 1, compareByBankAndAddress);
    else if (sortMethod == 2 && sortCriterion == 1)
        mergeSort(arr, 0, arr.size() - 1, compareBySellBuyDifference);
    else if (sortMethod == 2 && sortCriterion == 2)
        mergeSort(arr, 0, arr.size() - 1, compareByBankAndAddress);
}

