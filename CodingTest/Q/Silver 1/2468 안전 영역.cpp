#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>

/*
https://www.acmicpc.net/problem/2468

*/

struct COOR
{
    int y;
    int x;
};
const int dy[4]{ -1, 1, 0, 0 };
const int dx[4]{ 0, 0, -1, 1 };

vector<vector<int>> Tiles;
vector<vector<char>> History;
int Size;
void BFS(COOR Start, int Level)
{
    queue<COOR> Destination;
    Destination.push(Start);
    History[Start.y][Start.x] = true;
    while (!Destination.empty())
    {
        COOR Curr = Destination.front();
        Destination.pop();

        for (int i = 0; i < 4; ++i)
        {
            COOR Next{ Curr.y + dy[i], Curr.x + dx[i] };
            if (Next.x < 0
                || Next.x >= Size
                || Next.y < 0
                || Next.y >= Size)
            {
                continue;
            }
            if (Level >= Tiles[Next.y][Next.x] || true == History[Next.y][Next.x])
                continue;

            History[Next.y][Next.x] = true;
            Destination.push(Next);
        }
    }
}


void Solve(ifstream* _pLoadStream)
{
    int Level{ 0 };
    int Result = 1;
    CIN >> Size;
    Tiles.resize(Size, vector<int>(Size));
    for (int y = 0; y < Size; ++y)
    {
        for (int x = 0; x < Size; ++x)
        {
            CIN >> Tiles[y][x];
        }
    }

    while (true)
    {
        ++Level;
        int Sector = 0;
        History = vector<vector<char>>(Size, vector<char>(Size, false));
        for (int y = 0; y < Size; ++y)
        {
            for (int x = 0; x < Size; ++x)
            {
                if (Level >= Tiles[y][x] || true == History[y][x])
                    continue;

				++Sector;
				BFS({ y, x }, Level);
            }
        }

        Result = max(Result, Sector);
        if (Sector == 0)
        {
            cout << Result;
            return;
        }
    }

    cout << 1 << endl;
    return;
}