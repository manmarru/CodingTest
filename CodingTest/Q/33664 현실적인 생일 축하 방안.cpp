#include "pch.h"
#include "Header.h"
#include <unordered_map>
#include <string>

void Solve(ifstream* _pLoadStream)
{
    int MaxMoney;
    int InputSize;
    int BuySize;
    unordered_map<string, int>Items;
    CIN >> MaxMoney >> InputSize >> BuySize;
    for (int i = 0; i < InputSize; ++i)
    {
        string Input;
        CIN >> Input;
        CIN >> Items[Input];
    }
    int Result{ 0 };
    for (int i = 0; i < BuySize; ++i)
    {
        string Input;
        CIN >> Input;
        Result += Items[Input];
    }

    if (Result > MaxMoney)
        cout << "unacceptable";
    else
        cout << "acceptable";
}