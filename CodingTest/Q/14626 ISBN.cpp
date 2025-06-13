#include "pch.h"
#include "Header.h"
#include <string>

void Solve(ifstream* _pLoadStream)
{
    string Input;
    CIN >> Input;
    int Result{ 0 };
    int Index;
    const int Weight[2]{ 1, 3 };
    for (int i = 0; i < Input.length(); ++i)
    {
        if ('*' == Input[i])
        {
            Index = i;
            continue;
        }
        Result += (Input[i] - '0') * Weight[i % 2];
    }
    Result %= 10;
    Result = 10 - Result;
    if (Result == 10)
    {
        cout << 0;
        return;
    }
    if (0 == Index % 2)
        cout << Result;
    else
    {
        while (Result % 3 != 0)
            Result += 10;
        /*
        �� ���� ����� �ִ�.
        Result += (3 - Result % 3) % 3;
        3�� ������� ��ŭ ���������� ���°���
        */
        cout << Result / 3;
    }
}