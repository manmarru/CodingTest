#include "pch.h"
#include "Header.h"
#include <string>

using namespace std;

/*
https://school.programmers.co.kr/learn/courses/30/lessons/17687

char number[18] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                   'A', 'B', 'C', 'D', 'E', 'F'};
�̰� ���̵�� ����. ��������δ� �� ������.
algorithm.h �� reverse(iter::begin, iter::end); �Լ��� �ִ� �͸� �˾Ƶ���.

�� ����ȭ �ϰ� �ʹٸ� �ڸ����� ī��Ʈ�ϴٰ� ���ϴ� Ÿ�ֿ̹� ���� �̾Ƴ��� ����� �ֱ� �ϴ�.
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

    return Result; // �Ųٷ� ��ȯ�ȴ�.
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