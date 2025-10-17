#include "pch.h"
#include "Header.h"
#include <queue>
#include <vector>

/*
https://www.acmicpc.net/problem/3197
��Ƴ�;;

ó������ ������ ������ ���� ���ÿ� �̵��Ϸ��� �ϴϱ� �������.
�׷��� �ϸ� �� ������ �ִ� ������ �浹�ϴ� ��� ó���� ��û ����
����1, ����2, ���� ���� ������ �浹�ϴϱ� ��������.

Ǯ�̴� ���� ���������� �����̸� �ȴ�. �ݴ��� ������ �ִ� ĭ�� History�� üũ�ϸ� �Ǵϱ�.
Melt�� ���̱⸸ �ϰ� Spread�� ������ ������Ų��. �� ���ۿ� Nextť�� ���� �ξ���.

������ ������ ��ġ�ϱ� History�� ���� �ξ�� �ϴµ�, �׳� Enum���� History�� �ܰ踦 �־���.
*/


struct COOR
{
	int y, x;
};

enum HISTORY { FALSE = 0, NEXT = 1, TRUE = 2 };

int SizeY, SizeX;
vector<vector<char>> Board;
vector<vector<HISTORY>> History;
vector<COOR> Birds;

void Spread(queue<COOR>& _SpreadQ)
{
	COOR Curr;
	int NexY, NexX;
	queue<COOR> ResultQ;

	while (!_SpreadQ.empty())
	{
		Curr = _SpreadQ.front();
		_SpreadQ.pop();
		History[Curr.y][Curr.x] = TRUE;

		bool Temp = false;
		for (COOR D : initializer_list<COOR>{ {-1, 0}, {1, 0}, {0, -1}, {0, 1} })
		{
			NexY = Curr.y + D.y;
			NexX = Curr.x + D.x;

			if (NexY < 0 || NexX < 0 || NexY >= SizeY || NexX >= SizeX)
				continue;

			if (History[NexY][NexX] == TRUE)
				continue;

			if (Board[NexY][NexX] == 'X')
			{
				Temp = true;
			}
			else if (Board[NexY][NexX] == '.')
			{
				_SpreadQ.push({NexY, NexX});
				History[NexY][NexX] = TRUE;
			}
		}

		if (Temp == true)
		{
			ResultQ.push(Curr);
		}
	}
	swap(_SpreadQ, ResultQ);
}

void Melt(queue<COOR>& _MeltQ)
{
	COOR Curr;
	int NexY, NexX;
	int Size = _MeltQ.size();

	for (int i = 0; i < Size; ++i)
	{
		Curr = _MeltQ.front();
		_MeltQ.pop();
		Board[Curr.y][Curr.x] = '.';

		for (COOR D : initializer_list<COOR>{ {-1, 0}, {1, 0}, {0, -1}, {0, 1} })
		{
			NexY = Curr.y + D.y;
			NexX = Curr.x + D.x;

			if (NexY < 0 || NexX < 0 || NexY >= SizeY || NexX >= SizeX)
				continue;

			if (History[NexY][NexX] > FALSE)
				continue;

			if (Board[NexY][NexX] == 'X')
			{
				_MeltQ.push({ NexY, NexX });
				History[NexY][NexX] = NEXT;
			}
		}
	}
}

void Solve(ifstream* _pLoadStream)
{
	CIN >> SizeY >> SizeX;
	Board.resize(SizeY, vector<char> (SizeX));
	History.resize(SizeY, vector<HISTORY>(SizeX, FALSE));

	for (int y = 0; y < SizeY; ++y)
	{
		for (int x = 0; x < SizeX; ++x)
		{
			CIN >> Board[y][x];
			if (Board[y][x] == 'L')
			{
				Board[y][x] = '.';
				Birds.push_back({y, x});
			}
		}
	}

	queue<COOR> SpreadQ;// ���� ������ ���� ��ġ�� ����
	queue<COOR> MeltQ; // ���� ������ ���� ����

	SpreadQ.push(Birds[0]);
	Spread(SpreadQ);

	for (int y = 0; y < SizeY; ++y)
	{
		for (int x = 0; x < SizeX; ++x)
		{
			if (Board[y][x] == 'X')
			{
				for (COOR D : initializer_list<COOR>{ {-1, 0}, {1, 0}, {0, -1}, {0, 1} })
				{
					int NexY = y + D.y;
					int NexX = x + D.x;

					if (NexY < 0 || NexX < 0 || NexY >= SizeY || NexX >= SizeX)
						continue;

					if (Board[NexY][NexX] == '.')
					{
						MeltQ.push({ y, x });
						break;
					}
				}
			}
		}
	}

	int Turn = 0;
	while (History[Birds[1].y][Birds[1].x] < TRUE)
	{
		++Turn;

		Melt(MeltQ);
		Spread(SpreadQ);
	}

	cout << Turn;
}