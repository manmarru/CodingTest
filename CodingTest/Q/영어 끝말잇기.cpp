#include "pch.h"
#include "Header.h"

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

/*
https://school.programmers.co.kr/learn/courses/30/lessons/12981
라운드 헷갈릴거같으면 암기해버리자구
플레이어 번호: (i % n) + 1
라운드 : (i / n) + 1

*/

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer;
    unordered_set<string> History;
    char Lastword;

    History.insert(words[0]);
    Lastword = words[0][words[0].length() - 1];

    for (int i = 1; i < words.size(); ++i)
    {
        if (words[i][0] != Lastword)
        {
            answer.push_back((i % n) + 1);
            answer.push_back((i / n) + 1);

            return answer;
        }

        if (History.find(words[i]) != History.end())
        {
            answer.push_back((i % n) + 1);
            answer.push_back((i / n) + 1);

            return answer;
        }

        History.insert(words[i]);
        Lastword = words[i][words[i].length() - 1];
    }

    answer.push_back(0);
    answer.push_back(0);
    return answer;
}