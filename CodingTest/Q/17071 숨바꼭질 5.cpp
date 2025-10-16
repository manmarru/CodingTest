#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>
#include <array>


/*
https://www.acmicpc.net/problem/17071
동생이 도착할 땅을 미리 점거하는 개념이고
땅에 가만히 있는건 안되니까 와리가리 친다고 하면
짝수 턴에 도달한 땅은 짝수 턴에서 점거 활성화 된다고 생각하면 됨.
그래서 History가 array<bool, 2> 인거임

https://www.acmicpc.net/source/99310568
이 코드 굉장히 깔끔하다.
initializer_list를 쓰는게 성능에 큰 영향을 주는것도 아니라서 쓸만하다고 생각함
그냥 for 루프 내부 스코프에서 작은 배열 하나 만드는 수준임
*/

#define MAPSIZE 500000
#define HALFSIZE 250000
enum NUM { EVEN = 0, ODD = 1, NONE };

vector<array<bool, 2>> History(MAPSIZE + 1, { false, false });

void Solve(ifstream* _pLoadStream)
{
    int Subin, Sist;

    CIN >> Subin >> Sist;
    if (Subin == Sist)
    {
        cout << 0;
        return;
    }
    queue<int> Destination;
    Destination.push(Subin);
    History[Subin][EVEN] = true;

    int Curr;
    int Turn = 0;
    while (!Destination.empty())
    {
        ++Turn;
        int Size = Destination.size();
        NUM Temp = (NUM)(Turn % 2);
        for (int i = 0; i < Size; ++i)
        {
            Curr = Destination.front();
            Destination.pop();

            if (Curr > 1 && History[Curr - 1][Temp] == false)
            {
                Destination.push(Curr - 1);
                History[Curr - 1][Temp] = true;
            }

            if (Curr < MAPSIZE && History[Curr + 1][Temp] == false)
            {
                Destination.push(Curr + 1);
                History[Curr + 1][Temp] = true;
            }
            
            if (Curr <= HALFSIZE && History[Curr * 2][Temp] == false)
            {
                Destination.push(Curr * 2);
                History[Curr * 2][Temp] = true;
            }
        }
        Sist += Turn;
        if (Sist > MAPSIZE)
        {
            cout << -1;
            return;
        }
        if (History[Sist][Temp] == true)
        {
            cout << Turn;
            return;
        }
    }
}