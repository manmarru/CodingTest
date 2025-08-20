#include "pch.h"
#include "Header.h"

#include <vector>

using namespace std;

struct FLOOR
{
    int Head = 0;
    int Tail;
    vector<int> Data;

    void Push_Front(int _Data)
    {
        Data[Head] = _Data;
        ++Head;
    }

    void Push_Back(int _Data)
    {
        Data[Tail] = _Data;
        --Tail;
    }
};

vector<int> solution(int n) //n = 최대층수 (1부터 시작)
{
    vector<int> answer;
    vector<FLOOR> Square;
    Square.resize(n);

    for (int i = 0; i < n; ++i)
    {
        Square[i].Data.resize(i + 1);
        Square[i].Tail = i;
    }

    int Way[4][2] = { {1, 1}, {0, 1}, {-1, -1} }; // y, x
    int WayIndex = 0;
    int CurrFloor = -1;
    int CurrNum = 1;


    for (int i = n; i > 0; --i)
    {
        for (int j = i; j > 0; --j)
        {
            CurrFloor += Way[WayIndex][0];

            if (Way[WayIndex][1] == 1)
            {
                Square[CurrFloor].Push_Front(CurrNum);
                ++CurrNum;
            }
            else
            {
                Square[CurrFloor].Push_Back(CurrNum);
                ++CurrNum;
            }
        }

        WayIndex = (WayIndex + 1) % 3;
    }

    for (int i = 0; i < n; ++i)
    {
        vector<int>& Temp = Square[i].Data;
        for (int j = 0; j < i + 1; ++j)
        {
            answer.push_back(Temp[j]);
        }
    }

    return answer;
}