#include "pch.h"
#include "Header.h"
#include <vector>
#include <list>
#include <string>

// ����ũ üũ���� �� �� ������ �������ٵ� 90�ۿ��� �ƴ��Ѱ� �� �ƽ���

void Render();
struct TILE
{
	int Num;
};

vector<vector<TILE>> Board(9, vector<TILE>(9));
bool Col[9][10]{ false }; // ���ڰ� ������ true
bool Row[9][10]{ false };
bool Box[3][3][10]{ false };

pair<int, int> FindNext(int StartY, int StartX)
{
	int x = StartX + 1;
	for (int y = StartY; y < 9; ++y)
	{
		for (; x < 9; ++x)
		{
			if (0 == Board[y][x].Num)
				return { y, x };
		}
		x = 0;
	}
	return { -1, -1 };
}

bool DFS(int StartY, int StartX)
{
	TILE& Curr = Board[StartY][StartX];
	for (int i = 1; i < 10; ++i)
	{
		if (true == (Col[StartX][i] || Row[StartY][i] || Box[StartY / 3][StartX / 3][i]))
			continue;
		Curr.Num = i;
		Col[StartX][i] = true;
		Row[StartY][i] = true;
		Box[StartY / 3][StartX / 3][i] = true;

		pair<int, int> Next = FindNext(StartY, StartX);
		if (-1 == Next.first)
			return true;
		if (DFS(Next.first, Next.second))
			return true;
		Curr.Num = 0;
		Col[StartX][i] = false;
		Row[StartY][i] = false;
		Box[StartY / 3][StartX / 3][i] = false;
	}

	return false;
}

void Solve(ifstream* _pLoadStream)
{
	for (int y = 0; y < 9; ++y)
	{
		string Input;
		CIN >> Input;
		for (int x = 0; x < 9; ++x)
		{
			int Temp = Input[x] - '0';
			Board[y][x].Num = Temp;
			Col[x][Temp] = true;
			Row[y][Temp] = true;
			Box[y / 3][x / 3][Temp] = true;
		}
	}

	for (int y = 0; y < 9; ++y)
	{
		for (int x = 0; x < 9; ++x)
		{
			if (0 == Board[y][x].Num)
			{
				DFS(y, x);
				Render();
				return;
			}
		}
	}
}

void Render()
{
	for (int y = 0; y < 9; ++y)
	{
		for (int x = 0; x < 9; ++x)
		{
			cout << Board[y][x].Num << ' ';
		}
		cout << '\n';
	}
}
