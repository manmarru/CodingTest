#include "pch.h"
#include "Header.h"

#include <vector>
#include <map>
#include <cmath>

using namespace std;

/*
https://school.programmers.co.kr/learn/courses/30/lessons/12953

유클리드 호재법이 더 느릴 줄 알았는데 아니다.
LCM = 1 로 시작해서
숫자 하나와의 최소공배수를 구하고
그 최소공배수와 다음 숫자의 최소공배수를 구하기를 반복하는 방식을 사용한다.

소인수분해 방식을 사용할거면 적어도 2부터 ++ 하는게 아니라
에라도토스의 체를 사용해서 소수만 확인하면 더 좋지 않았을까 하는 생각 (물론 arr 길이가 최대 15밖에 안되긴 했다.)
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