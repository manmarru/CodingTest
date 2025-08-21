#include "pch.h"
#include "Header.h"

#include <vector>

using namespace std;

/* 
이동량은 n으로 시작해서 방향을 꺾을 때마다 1씩 줄어든다. 삼각형 모양으로 움직인다.

각 층에서 앞에 원소를 넣을지, 뒤에 원소를 넣을지 결정하는 함수를 오버라이딩 했다.
삼각형 모양으로 이동하는 매커니즘은 잘 짰다.
삼각 이동 그대로 써서 그냥 좌표만 바꿔주면서 원소 대입해도 된다. (지금도 상관없긴 한데)
*/

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