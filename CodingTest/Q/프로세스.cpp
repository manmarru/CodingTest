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
        CurrIndex = (CurrIndex + 1) % IndexSize; // �ε��� ����

        if (priorities[CurrIndex] != CurrRank) // �켱���� üũ
            continue;

        if (CurrIndex == location) // ���� ������ ���
            return answer + 1;

        iter->second -= 1;
        ++answer;

        if (iter->second == 0)
        {
            --iter;
            CurrRank = iter->first;
            //iter �� begin ������ �׳� ���� ��Ǭ����
        }
    }

    return answer;
}