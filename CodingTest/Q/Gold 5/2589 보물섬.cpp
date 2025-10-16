#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>

/*
https://www.acmicpc.net/problem/2589
�÷��̵�� �ϸ� �ȵ�? ���� �ð����⵵ N^3��

BFS ���� �� ���� �ʿ� ���� �� �ƹ������� �ѹ� ������ �״㿡 �� �ְ� ���µ��� �ѹ� �� �ϸ� ����Ÿ� ���´�.
�̰� ������ �ѹ����� �ϸ� �Ǵϱ� History���� �������� �ָ� �ǰ���?

Post�� Destination�� ����Ѱ� ������ ������ ���鿡���� COOR �ڷ����� �Ÿ� �������� �־�δ°� �� ����.
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