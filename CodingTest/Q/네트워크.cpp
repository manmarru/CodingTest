#include "pch.h"
#include "Header.h"
#include <vector>
#include <unordered_set>

using namespace std;

/*
https://school.programmers.co.kr/learn/courses/30/lessons/43162
union_find를 재귀함수로 구현한건 좋았던거같음
*/


vector<int> Union;

int Find(int n)
{
    if (n == Union[n])
        return n;
    Union[n] = Find(Union[n]);

    return Union[n];
}

void Solve(ifstream* _pLoadStream)
{
    int n = 3;
    vector<vector<int>> computers{ {1, 1, 0}, {1, 1, 0}, {0, 0, 1} };

    Union.resize(n);
    for (int i = 0; i < n; ++i)
    {
        Union[i] = i;
    }

    for (int Curr = 0; Curr < n; ++Curr)
    {
        for (int Target = Curr + 1; Target < n; ++Target)
        {
            if (computers[Curr][Target] == 0)
                continue;

            int Temp = Find(Target);
            int Src = Find(Curr);
            if (Temp != Src)
                Union[Temp] = Src;
        }
    }

    //for (int i : Union)
    //    cout << i << ' ';

    unordered_set<int> Result;
    for (int i = 0; i < n; ++i)
    {
        Result.insert(Find(i));
    }

    cout << Result.size();
}