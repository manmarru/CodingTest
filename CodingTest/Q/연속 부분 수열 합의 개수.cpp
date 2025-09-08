#include "pch.h"
#include "Header.h"

#include <vector>
#include <unordered_set>

using namespace std;

/*
https://school.programmers.co.kr/learn/courses/30/lessons/131701
반복문 두번이면 되더라. 어차피 거쳐가야 하니까 거치는 김에 다 넣고 가네
*/

int solution(vector<int> elements)
{
    int ElementSize = elements.size();
    unordered_set<int> Result;

    for (int SumSize = 1; SumSize < ElementSize; ++SumSize)
    {
        int Sum = 0;
        for (int Start = 0; Start < ElementSize; ++Start)
        {

            for (int i = 0; i < SumSize; ++i)
            {
                Sum += elements[(Start + i) % ElementSize];
                Result.insert(Sum);
            }
        }
    }

    return Result.size() + 1;
}


/* 이렇게 하면 반복문을 한번 줄일 수 있다.*/
int solution2(vector<int> elements)
{
    int ElementSize = elements.size();
    unordered_set<int> Result;

    for (int Start = 0; Start < ElementSize; ++Start)
    {
        int Sum = 0;
        for (int SumSize = Start; SumSize < ElementSize + Start; ++SumSize)
        {
            Sum += elements[SumSize % ElementSize];
            Result.insert(Sum);
        }
    }

    return Result.size();
}