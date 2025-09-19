#include "pch.h"
#include "Header.h"
#include <vector>
#include <algorithm>

void Solve(ifstream* _pLoadStream)
{
    vector<int> Input(9);
    int Total{ 0 };
    for (int i = 0; i < 9; ++i)
    {
        CIN >> Input[i];
        Total += Input[i];
    }

    sort(Input.begin(), Input.end());

    for (int First = 0; First < 8; ++First)
    {
        for (int Second = First + 1; Second < 9; ++Second)
        {
            Total -= Input[First] + Input[Second];
            if (Total == 100)
            {
                for (int i = 0; i < 9; ++i)
                {
                    if (i == First || i == Second)
                        continue;
                    cout << Input[i] << endl;
                }
                return;
            }
            Total += Input[First] + Input[Second];
        }
    }

    cout << "Error!" << endl;
}