#include "pch.h"
#include "Header.h"
#include <vector>
#include <limits.h>
#include <queue>
/*
1,1 에서 n,m 까지 최단경로로 이동하기
벽 하나 부실 수 있다.
*/

struct COOR
{
	int y;
	int x;
	bool Broken = false; // 벽을 부수고 진행된 건지

	void operator()(COOR& _Temp, int _x, int _y)
	{
		this->x = _Temp.x + _x;
		this->y = _Temp.y + _y;
		this->Broken = _Temp.Broken;
	}
};

int dX[4]{ 0, 0, 1, -1 };
int dY[4]{ 1, -1, 0, 0 };

void Solve(ifstream* _pLoadStream)
{
	int Height, Width;
	vector<vector<char>> Map;
	CIN >> Height >> Width;
	Map.resize(Height, vector<char>(Width, ' '));
	vector<vector<int>> Cost[2];
	Cost[0].resize(Height, vector<int>(Width, INT_MAX));
	Cost[1].resize(Height, vector<int>(Width, INT_MAX));

	for (int y = 0; y < Height; ++y)
	{
		for (int x = 0; x < Width; ++x)
		{
			CIN >> Map[y][x];
		}
	}
	queue<COOR> Destination;
	Destination.push({ 0, 0, false });

	Cost[0][0][0] = 1;
	COOR Curr;
	COOR Next;
	while (!Destination.empty())
	{
		Curr = Destination.front();
		Destination.pop();
		for (int i = 0; i < 4; ++i)
		{
			Next(Curr, dX[i], dY[i]);

			if ((dX[i] != 0 && 0 <= Next.x && Next.x < Width)
				|| (dY[i] != 0 && 0 <= Next.y && Next.y < Height))
			{
				if (!Curr.Broken) // 아직 안부심
				{
					if (Map[Next.y][Next.x] == '0' && Cost[0][Next.y][Next.x] == INT_MAX)
					{
						Cost[0][Next.y][Next.x] = Cost[0][Curr.y][Curr.x] + 1;
						Destination.push(Next);
					}
					else if(Map[Next.y][Next.x] == '1' && Cost[0][Curr.y][Curr.x] + 1 < Cost[1][Next.y][Next.x])
					{
						Cost[1][Next.y][Next.x] = Cost[0][Curr.y][Curr.x] + 1;
						Next.Broken = true;
						Destination.push(Next);
					}
				}
				else if(Curr.Broken) // 이미 부심
				{
					if (Map[Next.y][Next.x] == '0'
						&& Cost[1][Curr.y][Curr.x] + 1 < Cost[1][Next.y][Next.x])
					{
						Cost[1][Next.y][Next.x] = Cost[1][Curr.y][Curr.x] + 1;
						Destination.push(Next);
					}
				}
			}
		}
	}
	int Result = min(Cost[0][Height - 1][Width - 1], Cost[1][Height - 1][Width - 1]);
	if (Result == INT_MAX)
		cout << -1;
	else
		cout << Result;
}