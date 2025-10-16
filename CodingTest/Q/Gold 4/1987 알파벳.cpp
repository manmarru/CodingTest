#include "pch.h"
#include "Header.h"
#include <vector>

int Size[2]; // y, x
vector<vector<char>> Tiles;
vector<bool> History(26, false);
int Result(0);

void DFS(int _y, int _x, int _Cnt)
{
	++_Cnt;
	Result = max(Result, _Cnt);
	History[Tiles[_y][_x] - 'A'] = true;
	if (_y > 0 && History[Tiles[_y - 1][_x] - 'A'] == false)
	{
		DFS(_y - 1, _x, _Cnt);
		History[Tiles[_y - 1][_x] - 'A'] = false;
	}
	if (_y < Size[0] - 1 && History[Tiles[_y + 1][_x] - 'A'] == false)
	{
		DFS(_y + 1, _x, _Cnt);
		History[Tiles[_y + 1][_x] - 'A'] = false;
	}
	if (_x > 0 && History[Tiles[_y][_x - 1] - 'A'] == false)
	{
		DFS(_y, _x - 1, _Cnt);
		History[Tiles[_y][_x - 1] - 'A'] = false;
	}
	if (_x < Size[1] - 1 && History[Tiles[_y][_x + 1] - 'A'] == false)
	{
		DFS(_y, _x + 1, _Cnt);
		History[Tiles[_y][_x + 1] - 'A'] = false;
	}
}

void Solve(ifstream* _pLoadStream)
{
	/*
	여태까지 밟았던 알파벳이 적힌 땅을 밟지 않고 최대 몇 번 움직일 수 있는지 출력

	DFS 쓰면 될듯
	*/

	CIN >> Size[0] >> Size[1];
	Tiles.resize(Size[0]);
	char Input;
	for (int y = 0; y < Size[0]; ++y)
	{
		Tiles[y].reserve(Size[1]);
		for (int x = 0; x < Size[1]; ++x)
		{
			CIN >> Input;
			Tiles[y].push_back(Input);
		}
	}
	DFS(0, 0, 0);
	cout << Result;
}