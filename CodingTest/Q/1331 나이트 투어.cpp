#include "pch.h"
#include "Header.h"
#include <vector>

enum INPUT { COL, ROW, INPUT_END };

void Invalid()
{
    cout << "Invalid";
}

void Solve(ifstream* _pLoadStream)
{
    bool History[6][6]{ false };
    string Input;
    int PrevInput[INPUT_END];
    int CurrInput[INPUT_END];
    string StartPoint;
    CIN >> Input;
    StartPoint = Input;
    PrevInput[COL] = Input[0] - 'A';
    PrevInput[ROW] = Input[1] - '1';
    History[PrevInput[COL]][PrevInput[ROW]] = true;
    for (int i = 1; i < 36; ++i)
    {
        CIN >> Input;
        CurrInput[COL] = Input[0] - 'A';
        CurrInput[ROW] = Input[1] - '1';
        if (abs(PrevInput[COL] - CurrInput[COL]) == 2
            && abs(PrevInput[ROW] - CurrInput[ROW]) == 1) {
        }
        else if (abs(PrevInput[COL] - CurrInput[COL]) == 1
            && abs(PrevInput[ROW] - CurrInput[ROW]) == 2) {
        }
        else
        {
            Invalid();
            return;
        }

        if (History[CurrInput[COL]][CurrInput[ROW]])
        {
            Invalid();
            return;
        }
        History[CurrInput[COL]][CurrInput[ROW]] = true;
        PrevInput[COL] = CurrInput[COL];
        PrevInput[ROW] = CurrInput[ROW];
    }

    CurrInput[COL] = StartPoint[COL] - 'A';
    CurrInput[ROW] = StartPoint[ROW] - '1';
    if (abs(PrevInput[COL] - CurrInput[COL]) == 2
        && abs(PrevInput[ROW] - CurrInput[ROW]) == 1) {
    }
    else if (abs(PrevInput[COL] - CurrInput[COL]) == 1
        && abs(PrevInput[ROW] - CurrInput[ROW]) == 2) {
    }
    else
    {
        Invalid();
        return;
    }

    cout << "Valid";
    return;
}