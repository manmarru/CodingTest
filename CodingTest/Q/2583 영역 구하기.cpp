#include "pch.h"
#include "Header.h"

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
https://www.acmicpc.net/problem/2583
*/

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
vector<vector<char>> History;
int SizeX, SizeY;
int BFS(int y, int x)
{
    int Result{ 0 };
    queue<pair<int, int>> Destination;
    Destination.push({ y, x });
    History[y][x] = true;
    pair<int, int> Curr;
    pair<int, int> Next;
    while (!Destination.empty())
    {
        ++Result;
        Curr = Destination.front();
        Destination.pop();
        for (int i = 0; i < 4; ++i)
        {
            Next = { Curr.first + dy[i], Curr.second + dx[i] };
            if (Next.first < 0 || Next.first >= SizeY || Next.second < 0 || Next.second >= SizeX)
                continue;
            if (true == History[Next.first][Next.second])
                continue;
            History[Next.first][Next.second] = true;

            Destination.push(Next);
        }
    }
    return Result;
}

void Solve(ifstream* _pLoadStream)
{
    int Count;
    CIN >> SizeY >> SizeX >> Count;

    History.resize(SizeY, vector<char>(SizeX, false));
    int Lx, Ly, Rx, Ry;
    for (int i = 0; i < Count; ++i)
    {
        CIN >> Lx >> Ly >> Rx >> Ry;

        for (int y = Ly; y < Ry; ++y)
        {
            for (int x = Lx; x < Rx; ++x)
            {
                History[y][x] = true;
            }
        }
    }
    int Result{ 0 };
    vector<int> vecResult;
    for (int y = 0; y < SizeY; ++y)
    {
        for (int x = 0; x < SizeX; ++x)
        {
            if (true == History[y][x])
                continue;

            vecResult.push_back(BFS(y, x));
            ++Result;
        }
    }
    cout << Result << endl;
    sort(vecResult.begin(), vecResult.end());
    for (int i : vecResult)
        cout << i << ' ';

    return ;
}