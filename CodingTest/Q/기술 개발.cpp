#include "pch.h"
#include "Header.h"

#include <vector>

using namespace std;

/*
https://school.programmers.co.kr/learn/courses/30/lessons/42586
�̰� ������ �۾��� �ʿ��� �ð��� �̸� ����� �ΰ�
���� �� ���� ������ ������ ����
*/


vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;

    int ProgSize = progresses.size();
    int TotalFlow = 0;

    int Currjob = 0;
    while (Currjob < ProgSize)
    {
        while (progresses[Currjob] >= 100)
        {
            ++answer.back();
            ++Currjob;

            if (Currjob == ProgSize)
                return answer;

            progresses[Currjob] += speeds[Currjob] * TotalFlow;
        }
        answer.push_back(0);

        while (progresses[Currjob] < 100)
        {
            ++TotalFlow;
            progresses[Currjob] += speeds[Currjob];
        }
    }

    return answer;
}