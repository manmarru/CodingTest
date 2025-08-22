#include "pch.h"
#include "Header.h"

#include <vector>
#include <map>
#include <cmath>

using namespace std;

/*
https://school.programmers.co.kr/learn/courses/30/lessons/12953

��Ŭ���� ȣ����� �� ���� �� �˾Ҵµ� �ƴϴ�.
LCM = 1 �� �����ؼ�
���� �ϳ����� �ּҰ������ ���ϰ�
�� �ּҰ������ ���� ������ �ּҰ������ ���ϱ⸦ �ݺ��ϴ� ����� ����Ѵ�.

���μ����� ����� ����ҰŸ� ��� 2���� ++ �ϴ°� �ƴ϶�
�����佺�� ü�� ����ؼ� �Ҽ��� Ȯ���ϸ� �� ���� �ʾ����� �ϴ� ���� (���� arr ���̰� �ִ� 15�ۿ� �ȵǱ� �ߴ�.)
*/

int solution(vector<int> arr)
{
    map<int, int> Factors;
    int arrSize = arr.size();
    for (int i = 0; i < arrSize; ++i)
    {
        for (int fac = 2; fac <= arr[i]; ++fac)
        {
            int Count = 0;

            while (true)
            {
                if (arr[i] % fac != 0)
                    break;

                arr[i] /= fac;
                ++Count;
            }
            if (Count == 0)
                continue;
            Factors[fac] = max(Count, Factors[fac]);
        }
    }
    int answer = 1;
    for (auto Temp : Factors)
    {
        answer *= pow(Temp.first, Temp.second);
    }

    return answer;
}