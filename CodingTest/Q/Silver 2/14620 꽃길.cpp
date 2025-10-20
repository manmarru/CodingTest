#include "pch.h"
#include "Header.h"
#include <vector>

/*
https://www.acmicpc.net/problem/14620
½±³×¿ë
*/

int Size;
vector<vector<int>> Board;
vector<vector<char>> History;
int Answer{ 999999 };

struct COOR
{
	int y, x;
};

int Select(int y, int x)
{
	return Board[y - 1][x] + Board[y + 1][x] + Board[y][x - 1] + Board[y][x + 1] + Board[y][x];
}

void DFS(int Selected, int Cost)
{
	if (Selected == 3)
	{
		Answer = min(Cost, Answer);
		return;
	}

	for (int y = 1; y < Size - 1; ++y)
	{
		for (int x = 1; x < Size - 1; ++x)
		{
			if (true == (History[y - 1][x] || History[y + 1][x] || History[y][x - 1] || History[y][x + 1] || History[y][x]))
				continue;
			
			History[y - 1][x] = History[y + 1][x] = History[y][x - 1] = History[y][x + 1] = History[y][x] = true;
			DFS(Selected + 1, Cost + Select(y, x));
			History[y - 1][x] = History[y + 1][x] = History[y][x - 1] = History[y][x + 1] = History[y][x] = false;
		}
	}
}

void Solve(ifstream* _pLoadStream)
{
	CIN >> Size;
	Board.resize(Size, vector<int>(Size));
	History.resize(Size, vector<char>(Size, false));
	
	for (int y = 0; y < Size; ++y)
	{
		for (int x = 0; x < Size; ++x)
		{
			CIN >> Board[y][x];
		}
	}

	DFS(0, 0);
	cout << Answer;
}