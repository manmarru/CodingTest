#include "pch.h"
#include "Header.h"
#include <vector>


/*
https://www.acmicpc.net/problem/15684

백트래킹 DFS로 풀었다.
가지치기 여부가 시간 복잡도에 영향을 많이 주는 것 같다.
참고로 최대 3개의 선을 추가할 수 있다. 문제 잘 읽어야 한다.
단순하게 3을 넘어서면 리턴이 아니라 best를 넘었을 때도 미리 제거해버리면 가지가 많이 줄어든다.
예시 https://www.acmicpc.net/source/99240277
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