#include "pch.h"
#include "Header.h"
#include <vector>


vector<vector<int>> Board;
int Size;
int Result(0);
void Install(int _x, int _y)
{
	int minX = _x - min(_x, _y);
	int minY = _y - min(_x, _y);
	do
	{
		++Board[minY][minX];
		++minY;
		++minX;
	} while (minX < Size && minY < Size);

	minX = _x + min(Size - _x - 1, _y);
	minY = _y - min(Size - _x - 1, _y);
	do
	{
		++Board[minY][minX];
		++minY;
		--minX;
	} while (minX >= 0 && minY < Size);

	for (int i = 0; i < Size; ++i)
	{
		++Board[i][_x];
	}
	Board[_y][_x] -= 2;
}

void Cleaning(int _x, int _y)
{
	int minX = _x - min(_x, _y);
	int minY = _y - min(_x, _y);
	do
	{
		--Board[minY][minX];
		++minY;
		++minX;
	} while (minX < Size && minY < Size);
	
	minX = _x + min(Size - _x - 1, _y);
	minY = _y - min(Size - _x - 1, _y);
	do
	{
		--Board[minY][minX];
		++minY;
		--minX;
	} while (minX >= 0 && minY < Size);

	for (int i = 0; i < Size; ++i)
	{
		--Board[i][_x];
	}
	Board[_y][_x] += 2;
}

void DFS(int _y, int _Count)
{
	if (_Count == Size)
	{
		++Result;
		return;
	}

	for (int x = 0; x < Size; ++x)
	{
		if (Board[_y][x] == 0)
		{
			Install(x, _y);
			DFS(_y + 1, _Count + 1);
			Cleaning(x, _y);
		}
	}
}

void Solve(ifstream* _pLoadStream)
{
	/*
	N-Queen : 크기가 N*N인 체스판 위에  퀸 N 개를 서로 공격할 수 없게 놓는 문제
	퀸을 놓는 방법의 수를 출력

	걍 다 해보면 되는거 아님? N < [1, 15] 인데 걍 다 하면 되겠다.

	이렇게까지 다 할 필요는 없었고 좌 대각선, 우 대각선에 퀸이 존재했는지를 각각 기록해서
	이전 행의 공격 가능 자리에 인덱스 + 1 or -1 하면 다음 행에서 공격 가능한 칸들이 나도게 되겠지?
	
	비트마스킹 쓰면 10배 정도 빠르다.
	*/
	CIN >> Size;
	Board.resize(Size);
	for (int i = 0; i < Size; ++i)
		Board[i].resize(Size, 0);

	DFS(0, 0);

	cout << Result;
}