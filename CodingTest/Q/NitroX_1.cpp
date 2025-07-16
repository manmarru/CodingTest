#include "pch.h"
#include "Header.h"
#include <vector>

long long solution(int m, int k, int a, int b, vector<int> timetable);
/*
�����ڷ� ����� �ð�m
�����ڷ� ��ȿ�Ⱓ�� ���� ������ k�ϵ���
�����ҿ�ð� b, �����ڷᰡ �ִٸ� a
timetable�� ������ �ִ� ���� �־�����.
������ ��� �ּҽð��� ���Ͽ���.
*/


void Solve(ifstream* _pLoadStream)
{
    cout << solution(10, 3, 1, 10, {1, 2, 3, 10, 21, 22, 23});
}

long long solution(int m, int k, int a, int b, vector<int> timetable)
{
    int ClassSize = timetable.size();
    vector<long long> DP(ClassSize + 2, 9999999999); // 0���̶� ������ �ε����� �������
    DP[0] = 0;
    //dp�� ��ϵ� ������ ������ �������� ���� ���� + ��ȿ�Ⱓ ������ �ڷ� ���� �� ����
    int sum = -b;
    for (int i = 0; i < ClassSize; ++i)
    {
        sum += b;
        DP[i + 1] = sum;
    }

    // ���� �ε������� �ε����� �����ϸ鼭 ��ȿ�Ⱓ �ȿ� ����ִ��� ī����
    for (int Curr = 0; Curr < ClassSize; ++Curr)
    {
        int Count = 1;
        int Until = timetable[Curr] + k; // ��ȿ��¥
        for (int i = Curr + 1; i < ClassSize; ++i)
        {
            if (timetable[i] > Until)
                break;
            ++Count;
        }

        //�����Ϻ��� count ���� �������� a �ð� �ҿ���
        DP[Curr + Count + 1] = min(DP[Curr + Count], DP[Curr] + a * Count + m);

        cout << Curr + Count + 1 << " : " << "���� : " << Curr + 1 << " ī��Ʈ : " << Count << " ��� : " << DP[Curr + Count + 1] << endl;

        cout << endl;
    }

    return DP[ClassSize + 1];
}