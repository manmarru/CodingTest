#include "pch.h"
#include "Header.h"
#include <vector>

using namespace std;

/*
https://school.programmers.co.kr/learn/courses/30/lessons/12949
�����̶� �ٸ��� ����?

��İ��� �����
<����ڿ�> ���� ����� ��, ���� ����� �� ������ ���󰣴�.

size ������ ��� Dot �ȿ��� �� �ʿ�� ���� �� ����.
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