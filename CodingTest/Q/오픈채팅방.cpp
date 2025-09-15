#include "pch.h"
#include "Header.h"

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


/*
https://school.programmers.co.kr/learn/courses/30/lessons/42888
잘 풀었는데 stringstream을 보고 체질이 바뀜

map은 노드를 내려갈 때마다 > 비교 연산을 한다.
string의 경우 노드를 타고 내려갈 때마다 각 노드에서 string을 순회하게 될 수도 있다는 것.
따라서 unordered_map을 사용한 판단은 좋다.
*/

vector<string> solution(vector<string> record)
{
    unordered_map<string, string> UID;

    for (string Temp : record)
    {
        if (Temp[0] == 'L')
            continue;

        int TempSize = Temp.size();
        int Start = (Temp[0] == 'E' ? 6 : 7);
        for (int i = Start; i < TempSize; ++i)
        {
            if (Temp[i] == ' ')
            {
                UID[Temp.substr(Start, i - Start)] = Temp.substr(i + 1);
                break;
            }
        }
    }

    vector<string> answer;

    for (string Msg : record)
    {
        switch (Msg[0])
        {
        case 'E':
        {
            for (int i = 6; i < Msg.size(); ++i)
            {
                if (Msg[i] == ' ')
                {
                    answer.push_back(UID[Msg.substr(6, i - 6)] + "님이 들어왔습니다.");
                    break;
                }
            }
            break;
        }
        case 'L':
        {
            answer.push_back(UID[Msg.substr(6)] + "님이 나갔습니다.");
            break;
        }
        case 'C':
            break;
        }
    }

    return answer;
}