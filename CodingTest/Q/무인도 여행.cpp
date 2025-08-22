#include "pch.h"
#include "Header.h"

#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

/*
���� ��ũ https://school.programmers.co.kr/learn/courses/30/lessons/154540
�Ű� ������ �����ϱ� �����ٰ� ���� ������ ���� ����ϸ�
1. ������ �� ���� ������ �˱� ��ƴ�. (������� �Һи�������.)
2. ��Ƽ������ ����Ҷ� ����ȭ ������ �ǰ����� �� �ִ�. (���� ���۷��� �����ϸ� �Ȱ��� ��Ȳ�̱� �ѵ�)
3. �ֽ� �����Ϸ��� �������� ������ ������ �������� �Ǵ��ϱ� ������
    ĳ���� ���� �ʴ� ��찡 ���ܼ� ������ ��������.

pop �Ҷ��� �ƴ϶� push �� �� history ��ȯ���ָ� ���ʿ��� push�� �پ���.
*/
struct COOR
{
    int y;
    int x;
};
vector<vector<int>> Board;
vector<vector<char>> History;
int SizeX;
int SizeY;
const int WAY[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int BFS(COOR Start)
{
    int Result = 0;
    queue<COOR> Destination;
    Destination.push(Start);

    while (!Destination.empty())
    {
        COOR Curr = Destination.front();
        Destination.pop();

        if (true == History[Curr.y][Curr.x])
            continue;

        Result += Board[Curr.y][Curr.x];
        History[Curr.y][Curr.x] = true;

        int y, x;
        for (int i = 0; i < 4; ++i)
        {
            y = Curr.y + WAY[i][0];
            x = Curr.x + WAY[i][1];

            if (y < 0 || y >= SizeY || x < 0 || x >= SizeX)
                continue;

            if (true == History[y][x])
                continue;

            Destination.push({ y, x });
        }
    }

    return Result;
}

vector<int> solution(vector<string> maps)
{
    SizeY = maps.size();
    SizeX = maps[0].size();
    Board.resize(SizeY, vector<int>(SizeX, 0));
    History.resize(SizeY, vector<char>(SizeX, false));

    for (int y = 0; y < SizeY; ++y)
    {
        for (int x = 0; x < SizeX; ++x)
        {
            if (maps[y][x] == 'X')
            {
                History[y][x] = true;
                continue;
            }

            Board[y][x] = maps[y][x] - '0';
        }
    }

    vector<int> answer;
    for (int y = 0; y < SizeY; ++y)
    {
        for (int x = 0; x < SizeX; ++x)
        {
            if (true == History[y][x])
                continue;

            answer.push_back(BFS({ y, x }));
        }
    }

    if (answer.empty())
        answer.push_back(-1);
    else
        sort(answer.begin(), answer.end()); // ������������ ��ȯ�ϸ� �ȴ�.
    return answer;
}