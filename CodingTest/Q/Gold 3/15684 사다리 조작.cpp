#include "pch.h"
#include "Header.h"
#include <vector>


/*
https://www.acmicpc.net/problem/15684

��Ʈ��ŷ DFS�� Ǯ����.
����ġ�� ���ΰ� �ð� ���⵵�� ������ ���� �ִ� �� ����.
����� �ִ� 3���� ���� �߰��� �� �ִ�. ���� �� �о�� �Ѵ�.
�ܼ��ϰ� 3�� �Ѿ�� ������ �ƴ϶� best�� �Ѿ��� ���� �̸� �����ع����� ������ ���� �پ���.
���� https://www.acmicpc.net/source/99240277
*/
enum Dir
{ 
	DIR_LEFT = -1,
	DIR_MID = 0,
	DIR_RIGHT = 1 
};

vector<vector<int>> Board;
int SizeY, LineSize, SizeX;

bool Test(int Start)
{
	int x = Start;
	int y = 0;
	while (y != SizeY)
	{
		x += Board[y][x];

		++y;
	}

	return Start == x;
}

int DFS(int installed, int StartY, int StartX)
{
	bool Check = true;
	for (int i = 0; i < SizeX; ++i)
	{
		Check &= Test(i);
	}

	if (true == Check)
	{
		return installed;
	}
	if (installed == 3)
		return 5;

	int Result = 5;
	int x = StartX;
	for (int y = StartY; y < SizeY; ++y)
	{
		for (; x < SizeX - 1; ++x)
		{
			if (Board[y][x] != DIR_MID || Board[y][x + 1] != DIR_MID)
				continue;

			Board[y][x] = DIR_RIGHT;
			Board[y][x + 1] = DIR_LEFT;
			Result = min(Result, DFS(installed + 1, y , x));
			Board[y][x] = DIR_MID;
			Board[y][x + 1] = DIR_MID;
		}
		x = 0;
	}

	return Result;
}

void Solve(ifstream* _pLoadStream)
{
	CIN >> SizeX >> LineSize >> SizeY;
	Board.resize(SizeY, vector<int>(SizeX, DIR_MID));
	int Input[2];
	for (int i = 0; i < LineSize; ++i)
	{
		CIN >> Input[0] >> Input[1];
		--Input[0]; --Input[1];
		Board[Input[0]][Input[1]] = DIR_RIGHT;
		Board[Input[0]][Input[1] + 1] = DIR_LEFT;
	}

	int Result = DFS(0, 0, 0);
	if (3 < Result)
		cout << -1 << " : " << Result;
	else
		cout << Result;

	return;
}