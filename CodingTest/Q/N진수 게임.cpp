#include "pch.h"
#include "Header.h"
#include <string>

using namespace std;

/*
https://school.programmers.co.kr/learn/courses/30/lessons/17687

char number[18] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                   'A', 'B', 'C', 'D', 'E', 'F'};
이거 아이디어 좋네. 통상적으로는 못 쓰지만.
algorithm.h 에 reverse(iter::begin, iter::end); 함수가 있는 것만 알아두자.

더 최적화 하고 싶다면 자릿수만 카운트하다가 원하는 타이밍에 숫자 뽑아내는 방법이 있긴 하다.
*/

string TransNum(int Num, int Rank)
{
    string Result;
    int Next;
    while (Num > 0)
    {
        Next = Num % Rank;
        if (Next > 9)
        {
            Result += char('A' + Next - 10);
        }
        else
        {
            Result += char('0' + (Num % Rank));
        }
        Num /= Rank;
    }

    return Result; // 거꾸로 반환된다.
}

string solution(int n, int t, int m, int p)
{
    const int Total = p + m * (t - 1) + 1;
    int CurrNum = 0;
    int CurrIndex = 1;
    int WordIndex = 0;

    string Target = "0";
    string answer = "";
    string Result = "";

    while (CurrIndex != Total)
    {
        if (WordIndex == -1)
        {
            Target = TransNum(++CurrNum, n);
            WordIndex = Target.length() - 1;
        }
        Result += Target[WordIndex];

        --WordIndex;
        ++CurrIndex;
    }

    for (int i = 0; i < t; ++i)
    {
        answer += Result[p + i * m - 1];
    }

    return answer;
}