#include "pch.h"
#include "Header.h"

#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
https://school.programmers.co.kr/learn/courses/30/lessons/43163
ī���� �ϴ� bfs�϶� ť �ΰ� ���°� �׻� �ƽ��� ������ �ֱ� �ϴ� ������...
*/

int solution(string begin, string target, vector<string> words)
{
    int wordsSize = words.size();
    int wordSize = words[0].size();
    vector<char> History(wordsSize + 1, false);
    queue<int> Destination;
    queue<int> next;
    int Curr;
    int ErrCount;
    int answer = 0;
    words.push_back(begin);
    next.push(wordsSize);

    while (!next.empty())
    {
        swap(next, Destination);
        ++answer;
        while (!Destination.empty())
        {
            Curr = Destination.front();
            Destination.pop();
            if (words[Curr] == target)
            {
                return answer - 1;
            }

            for (int i = 0; i < wordsSize; ++i)
            {
                if (i == Curr || true == History[i])
                    continue;

                ErrCount = 0;
                for (int word = 0; word < wordSize; ++word)
                {
                    if (words[Curr][word] != words[i][word])
                    {
                        ++ErrCount;
                        if (ErrCount > 1)
                            break;
                    }
                }
                if (ErrCount == 1)
                {
                    next.push(i);
                    History[i] = true;
                }
            }
        }
    }

    return 0;
}