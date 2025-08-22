#include "pch.h"
#include "Header.h"

#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

/*
문제 링크 https://school.programmers.co.kr/learn/courses/30/lessons/154540
매개 변수로 전달하기 귀찮다고 전역 변수를 많이 사용하면
1. 변수의 값 변경 시점을 알기 어렵다. (입출력이 불분명해진다.)
2. 멀티쓰레드 사용할때 동기화 문제로 피곤해질 수 있다. (물론 래퍼런스 접근하면 똑같은 상황이긴 한데)
3. 최신 컴파일러는 전역변수 접근을 포인터 접근으로 판단하기 때문에
    캐싱을 하지 않는 경우가 생겨서 성능이 떨어진다.

pop 할때가 아니라 push 할 때 history 전환해주면 불필요한 push가 줄어든다.
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
        sort(answer.begin(), answer.end()); // 오름차순으로 반환하면 된다.
    return answer;
}