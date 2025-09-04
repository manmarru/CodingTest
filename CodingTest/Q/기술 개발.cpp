#include "pch.h"
#include "Header.h"

#include <vector>

using namespace std;

/*
https://school.programmers.co.kr/learn/courses/30/lessons/42586
이거 각각의 작업에 필요한 시간을 미리 계산해 두고
루프 슥 돌면 끝난다 레전드 ㅋㅋ
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