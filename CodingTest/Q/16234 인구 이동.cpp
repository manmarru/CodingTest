#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>
#include <algorithm>
/*
https://www.acmicpc.net/problem/16234

왼쪽이나 아래로만 파생하면 히스토리 체크도 필요 없다.
*/

const int dY[4]{ -1, 1, 0, 0 };
const int dX[4]{ 0, 0, -1, 1 };
struct COOR
{
	int y, x;
};

int Size;
int L, R;
vector<vector<int>> World;
vector<vector<char>> History;

bool BFS(COOR Start)
{
	int Delta;
	int Sum{ 0 };
	vector<COOR> Result;

	queue<COOR> Destination;
	Destination.push(Start);
	Result.push_back(Start);

	COOR Curr, Next;
	while (!Destination.empty())
	{
		Curr = Destination.front();
		Destination.pop();
		Sum += World[Curr.y][Curr.x];
		History[Curr.y][Curr.x] = true;

		for (int i = 0; i < 4; ++i)
		{
			Next.y = Curr.y + dY[i];
			Next.x = Curr.x + dX[i];
			if (Next.y == Size || Next.y < 0 || Next.x == Size || Next.x < 0)
				continue;
			if (true == History[Next.y][Next.x])
				continue;

			Delta = abs(World[Curr.y][Curr.x] - World[Next.y][Next.x]);
			if (Delta < L || Delta > R)
				continue;

			History[Next.y][Next.x] = true;
			Destination.push(Next);
			Result.push_back(Next);
		}
	}
	
	if (1 == Result.size())
		return  false;

	Sum /= Result.size();
	for (COOR& C : Result)
	{
		World[C.y][C.x] = Sum;
	}

	return true;
}

void Solve(ifstream* _pLoadStream)
{
	CIN >> Size >> L >> R;
	World.resize(Size, vector<int>(Size));
	History.resize(Size, vector<char>(Size));

	for (int y = 0; y < Size; ++y)
	{
		for (int x = 0; x < Size; ++x)
		{
			CIN >> World[y][x];
		}
	}

	bool Check = true;
	int Result{ -1 };
	while(Check)
	{
		for(int i = 0; i < Size; ++i)
			fill(History[i].begin(), History[i].end(), false);
		++Result;
		Check = false;
		for (int y = 0; y < Size; ++y)
		{
			for (int x = 0; x < Size; ++x)
			{
				if (true == History[y][x])
					continue;

				Check |= BFS({ y, x });
			}
		}
	}

	cout << Result;
}