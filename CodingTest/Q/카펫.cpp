#include "pch.h"
#include "Header.h"

#include <vector>

using namespace std;

/*
https://school.programmers.co.kr/learn/courses/30/lessons/42842
5분컷 겁나쉽네
근의 공식을 사용하거나 넓이의 제곱근을 보기도 하던데
종이 깔아놓고 한참 풀 거 아니면 그닥 좋아보이진 않음.
*/

vector<int> solution(int brown, int yellow)
{
    brown -= 4;
    brown /= 2; // 무조건 짝수임

    vector<int> answer;
    for (int i = 1; i < brown; ++i)
    {
        if (i * (brown - i) == yellow)
        {
            answer.push_back(brown - i + 2); // 무조건 큰게 먼저 들어감
            answer.push_back(i + 2);
            break;
        }
    }

    return answer;
}