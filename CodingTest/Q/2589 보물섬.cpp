#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>

/*
https://www.acmicpc.net/problem/2589
플로이드로 하면 안돼? ㅇㅇ 시간복잡도 N^3임

BFS 여러 번 돌릴 필요 없이 섬 아무데서나 한번 돌리고 그담에 젤 멀게 나온데서 한번 더 하면 최장거리 나온다.
이걸 섬마다 한번씩만 하면 되니까 History값에 디테일을 주면 되겠지?

Post랑 Destination을 사용한건 좋은데 가독성 측면에서는 COOR 자료형에 거리 누적값을 넣어두는게 더 좋다.
*/

const int dY[4]{ -1, 1, 0, 0 };
const int dX[4]{ 0, 0, -1, 1 };
int SizeY, SizeX;
vector<vector<char>> Island;

struct COOR
{
	int y, x;
};

int BFS(COOR Start)
{
	vector<vector<char>> History(SizeY, vector<char>(SizeX, false));

	queue<COOR> Destination;
	queue<COOR> Post;
	Post.push(Start);
	History[Start.y][Start.x] = true;

	COOR Curr;
	COOR Next;
	int Result{ -1 };
	while (!Post.empty())
	{
		++Result;
		swap(Post, Destination);
		while (!Destination.empty())
		{
			Curr = Destination.front();
			Destination.pop();

			for (int i = 0; i < 4; ++i)
			{
				Next.y = Curr.y + dY[i];
				Next.x = Curr.x + dX[i];

				if (Next.y < 0 || Next.y == SizeY || Next.x < 0 || Next.x == SizeX)
					continue;

				if (true == History[Next.y][Next.x])
					continue;

				if ('W' == Island[Next.y][Next.x])
					continue;
				History[Next.y][Next.x] = true;
				Post.push(Next);
			}
		}
	}

	return Result;
}

void Solve(ifstream* _pLoadStream)
{
	CIN >> SizeY >> SizeX;

	Island.resize(SizeY, vector<char>(SizeX));
	for (int y = 0; y < SizeY; ++y)
	{
		for (int x = 0; x < SizeX; ++x)
		{
			CIN >> Island[y][x];
		}
	}

	int Result{ 0 };
	for (int y = 0; y < SizeY; ++y)
	{
		for (int x = 0; x < SizeX; ++x)
		{
			if ('W' == Island[y][x])
				continue;

			Result = max(Result, BFS({ y, x }));
		}
	}
	cout << Result;
}