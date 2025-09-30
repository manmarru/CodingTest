#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>

/*
https://www.acmicpc.net/problem/4179
�����ѵ�

�ٸ� Visited�� �� ���� World���� ���������� ������ �ϸ�
�ʱⰪ�� ȸ�յǰ�, ������ Ȯ��Ǹ鼭 ��ȣ�ۿ��� �߰��� ��� �ڵ� �������� ������ �� �ִ�.
*/


struct COOR
{
	int y, x;
};

int dY[4] = { -1, 1, 0, 0 };
int dX[4] = { 0, 0, -1, 1 };

void Solve(ifstream* _pLoadStream)
{
	int SizeY, SizeX;
	CIN >> SizeY >> SizeX;

	queue<COOR> DestinationP;
	queue<COOR> DestinationF;
	vector<vector<char>> World(SizeY, vector<char>(SizeX));
	for (int y = 0; y < SizeY; ++y)
	{
		for (int x = 0; x < SizeX; ++x)
		{
			CIN >> World[y][x];
			if (World[y][x] == 'J')
				DestinationP.push({ y, x });
			else if (World[y][x] == 'F')
				DestinationF.push({ y, x });
		}
	}


	int Result{ 0 };
	COOR Curr, Next;
	while (!DestinationP.empty())
	{
		++Result;
		int Loop = DestinationF.size();
		for (int i = 0; i < Loop; ++i)
		{
			Curr = DestinationF.front();
			DestinationF.pop();

			for (int d = 0; d < 4; ++d)
			{
				Next.y = Curr.y + dY[d];
				Next.x = Curr.x + dX[d];
				if (Next.y < 0 || Next.y == SizeY || Next.x < 0 || Next.x == SizeX)
					continue;
				if (World[Next.y][Next.x] == '#' || World[Next.y][Next.x] == 'F')
					continue;

				DestinationF.push(Next);
				World[Next.y][Next.x] = 'F';
			}
		}

		Loop = DestinationP.size();
		for (int i = 0; i < Loop; ++i)
		{
			Curr = DestinationP.front();
			DestinationP.pop();

			for (int d = 0; d < 4; ++d)
			{
				Next.y = Curr.y + dY[d];
				Next.x = Curr.x + dX[d];
				if (Next.y < 0 || Next.y == SizeY || Next.x < 0 || Next.x == SizeX)
				{
					cout << Result;
					return;
				}
				if (World[Next.y][Next.x] != '.')
					continue;

				DestinationP.push(Next);
				World[Next.y][Next.x] = 'P';
			}
		}
	}

	cout << "IMPOSSIBLE";
}