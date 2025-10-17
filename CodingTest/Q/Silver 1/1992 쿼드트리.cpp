#include "pch.h"
#include "Header.h"
#include <vector>

/*
https://www.acmicpc.net/problem/1992

+연산으로 string을 합치면 ""에다가 두 string을 합치는거라 시간복잡도 고려해야 한다.
+= 연산은 왼쪽꺼에 append하는거라 쫌 더 빠르다.
stringstream의 >> 연산을 하면 메모리 관리를 쪼끔 더 효율적이게 해주긴 한다.
ostringstream을 사용하는 것도 고려해야 한다.
*/


vector<vector<char>> Tiles;
string Quad(int StartY, int StartX, int Size)
{
	if (Size == 1)
	{
		return { Tiles[StartY][StartX] };
	}

	string Targets[4] = {
		Quad(StartY, StartX, Size / 2)
		, Quad(StartY, StartX + Size / 2, Size / 2)
		, Quad(StartY + Size / 2, StartX, Size / 2)
		, Quad(StartY + Size / 2, StartX + Size / 2, Size / 2) };
	
	if (Targets[0].length() == 1
		&& Targets[0] == Targets[1] && Targets[0] == Targets[2] && Targets[0] == Targets[3])
	{
		return Targets[0];
	}

	string Temp = "";
	for (int i = 0; i < 4; ++i)
	{
		if (Targets[i].length() != 1)
		{
			Temp += '(';
			Temp += Targets[i];
			Temp += ')';
		}
		else
			Temp += Targets[i];
	}
	return Temp;
}

void Solve(ifstream* _pLoadStream)
{
	int Size;
	CIN >> Size;
	Tiles.resize(Size, vector<char>(Size));

	for (int y = 0; y < Size; ++y)
	{
		for (int x = 0; x < Size; ++x)
		{
			CIN >> Tiles[y][x];
		}
	}
	
	string Answer = Quad(0, 0, Size);
	if (Answer.length() == 1)
		cout << Answer;
	else
		cout << '(' <<  Answer << ')';
}