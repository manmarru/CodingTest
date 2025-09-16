#include "pch.h"
#include "Header.h"
#include <vector>

using namespace std;

/*
https://school.programmers.co.kr/learn/courses/30/lessons/12949
외적이랑 다른거 알지?

행렬곱의 결과는
<앞행뒤열> 앞의 행렬의 수, 뒤의 행렬의 열 갯수를 따라간다.

size 연산을 계속 Dot 안에서 할 필요는 없을 것 같네.
*/

long long int Dot(vector<vector<int>>& arr1, vector<vector<int>>& arr2, int y, int x)
{
    long long int Result = 0;
    int Size = arr1[0].size();

    for (int i = 0; i < Size; ++i)
    {
        Result += arr1[y][i] * arr2[i][x];
    }
    return Result;
}


vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    int SizeX = arr2[0].size();
    int SizeY = arr1.size();
    vector<vector<int>> answer(SizeY, vector<int>(SizeX, 0));


    for (int y = 0; y < SizeY; ++y)
    {
        for (int x = 0; x < SizeX; ++x)
        {
            answer[y][x] = Dot(arr1, arr2, y, x);
        }
    }

    return answer;
}