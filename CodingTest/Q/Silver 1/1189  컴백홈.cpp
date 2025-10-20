#include "pch.h"
#include "Header.h"
#include <vector>

/*
https://www.acmicpc.net/problem/1189
예 깔끔하네요
*/

// 시작점이랑 도착점 포함해서 카운트하는거임

int TargetCost;
int SizeY, SizeX;
int Result{ 0 };
vector<vector<char>> Board;
vector<vector<char>> History;

void DFS(int _y, int _x, int _Cost)
{
	if (_Cost > TargetCost)
		return;
	if (TargetCost == _Cost && _y == 0 && _x == SizeX - 1)
	{
		++Result;
		return;
	}
	
	for (pair<int, int> Temp : initializer_list<pair<int, int>>{ {-1, 0}, {1, 0}, {0, -1}, {0, 1} })
	{
		int y = _y + Temp.first;
		int x = _x + Temp.second;

		if (y < 0 || x < 0 || y >= SizeY || x >= SizeX)
			continue;

		if (true == History[y][x])
			continue;
		History[y][x] = true;
		DFS(y, x, _Cost + 1);
		History[y][x] = false;
	}
}


void Solve(ifstream* _pLoadStream)
{
	CIN >> SizeY >> SizeX >> TargetCost;
	Board.resize(SizeY, vector<char>(SizeX));
	History.resize(SizeY, vector<char>(SizeX));

	for (int y = 0; y < SizeY; ++y)
	{
		for (int x = 0; x < SizeX; ++x)
		{
			CIN >> Board[y][x];
			if (Board[y][x] == 'T')
				History[y][x] = true;
		}
	}

	History[SizeY - 1][0] = true;
	DFS(SizeY - 1, 0, 1);
	cout << Result;
}