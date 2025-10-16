#include "pch.h"
#include "Header.h"
#include <vector>

vector<vector<bool>> Board;

void STAR(int _Size, int _y, int _x)
{
	if (_Size <= 3)
	{
		Board[_y][_x] = true;
		Board[_y + 1][_x - 1] = true;
		Board[_y + 1][_x + 1] = true;
		for (int i = -2; i < 3; ++i)
		{
			Board[_y + 2][_x + i] = true;
		}
		return;
	}
	else
	{
		STAR(_Size / 2, _y, _x);
		STAR(_Size / 2, _y + _Size / 2, _x - _Size / 2);
		STAR(_Size / 2, _y + _Size / 2, _x + _Size / 2);
	}
}

void Solve(ifstream* _pLoadStream)
{
	/*
	규칙 찾아서 별 찍기
	input이 줄 수구나
	*/
	int INPUT;
	CIN >> INPUT;

	Board.resize(INPUT, vector<bool>(INPUT * 2 ));

	STAR(INPUT, 0, INPUT - 1);

	for (int y = 0; y < INPUT; ++y)
	{
		for (int x = 0; x < INPUT * 2 - 1; ++x)
		{
			cout << (Board[y][x] ? '*' : ' ');
		}
		cout << '!' << endl;
	}


}