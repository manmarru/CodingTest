#include "pch.h"
#include "Header.h"

#include <vector>
#include <map>

using namespace std;

int solution(vector<int> priorities, int location)
{
    map<int, int> Topology;
    int answer = 0;
    int CurrIndex = -1;
    int IndexSize = priorities.size();

    for (int i : priorities)
    {
        ++Topology[i];
    }

    auto iter = --Topology.end();
    int CurrRank = iter->first;
    while (true)
    {
        CurrIndex = (CurrIndex + 1) % IndexSize; // 인덱스 증가

        if (priorities[CurrIndex] != CurrRank) // 우선순위 체크
            continue;

        if (CurrIndex == location) // 답이 나왔을 경우
            return answer + 1;

        iter->second -= 1;
        ++answer;

        if (iter->second == 0)
        {
            --iter;
            CurrRank = iter->first;
            //iter 가 begin 뚫으면 그냥 문제 못푼거임
        }
    }

    return answer;
}