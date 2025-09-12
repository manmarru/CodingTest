#include "pch.h"
#include "Header.h"

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


/*
https://school.programmers.co.kr/learn/courses/30/lessons/42888
�� Ǯ���µ� stringstream�� ���� ü���� �ٲ�
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
                    answer.push_back(UID[Msg.substr(6, i - 6)] + "���� ���Խ��ϴ�.");
                    break;
                }
            }
            break;
        }
        case 'L':
        {
            answer.push_back(UID[Msg.substr(6)] + "���� �������ϴ�.");
            break;
        }
        case 'C':
            break;
        }
    }

    return answer;
}