#include "pch.h"
#include "Header.h"
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges)
{
    // 각 사다리꼴의 넒이를 구한 뒤 합치기?
    vector<double> Collatz;
    Collatz.push_back(k);
    while (k != 1)
    {
        if (k % 2 == 0)
        {
            k /= 2;
        }
        else
        {
            k = k * 3 + 1;
        }

        Collatz.push_back(k);
    }
    int CollatzSize = Collatz.size();

    for (int i = 0; i < CollatzSize - 1; ++i)
    {
        Collatz[i] = (Collatz[i] + Collatz[i + 1]) / 2;
    }

    vector<double> answer;
    for (vector<int>& Range : ranges)
    {
        answer.push_back(0);
        if (Range[0] >= CollatzSize + Range[1])
        {
            answer.back() = -1;
            continue;
        }

        for (int i = Range[0]; i < CollatzSize + Range[1] - 1; ++i)
        {
            answer.back() += Collatz[i];
        }
    }

    return answer;
}