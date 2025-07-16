#include "pch.h"
#include "Header.h"
#include <vector>

long long solution(int m, int k, int a, int b, vector<int> timetable);
/*
수업자료 만드는 시간m
수업자료 유효기간은 만든 날부터 k일동안
수업소요시간 b, 수업자료가 있다면 a
timetable에 수업이 있는 날이 주어진다.
수업에 드는 최소시간을 구하여라.
*/


void Solve(ifstream* _pLoadStream)
{
    cout << solution(10, 3, 1, 10, {1, 2, 3, 10, 21, 22, 23});
}

long long solution(int m, int k, int a, int b, vector<int> timetable)
{
    int ClassSize = timetable.size();
    vector<long long> DP(ClassSize + 2, 9999999999); // 0번이랑 마지막 인덱스는 연산용임
    DP[0] = 0;
    //dp가 기록된 시점에 수업은 진행하지 않은 상태 + 유효기간 끝나서 자료 만들 수 있음
    int sum = -b;
    for (int i = 0; i < ClassSize; ++i)
    {
        sum += b;
        DP[i + 1] = sum;
    }

    // 시작 인덱스부터 인덱스를 증가하면서 유효기간 안에 들어있는지 카운팅
    for (int Curr = 0; Curr < ClassSize; ++Curr)
    {
        int Count = 1;
        int Until = timetable[Curr] + k; // 유효날짜
        for (int i = Curr + 1; i < ClassSize; ++i)
        {
            if (timetable[i] > Until)
                break;
            ++Count;
        }

        //시작일부터 count 개의 수업동안 a 시간 소요함
        DP[Curr + Count + 1] = min(DP[Curr + Count], DP[Curr] + a * Count + m);

        cout << Curr + Count + 1 << " : " << "시작 : " << Curr + 1 << " 카운트 : " << Count << " 결과 : " << DP[Curr + Count + 1] << endl;

        cout << endl;
    }

    return DP[ClassSize + 1];
}