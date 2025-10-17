#include "pch.h"
#include "Header.h"
#include <queue>
#include <vector>

/*
https://www.acmicpc.net/problem/3197
어렵네;;

처음에는 양쪽의 백조가 각자 동시에 이동하려고 하니까 힘들었다.
그렇게 하면 각 백조가 있는 영역이 충돌하는 경우 처리가 엄청 힘듦
백조1, 백조2, 백조 없는 영역이 충돌하니까 어지럽다.

풀이는 한쪽 백조에서만 움직이면 된다. 반대쪽 백조가 있는 칸의 History를 체크하면 되니깐.
Melt는 녹이기만 하고 Spread는 백조를 전염시킨다. 각 동작에 Next큐를 따로 두었다.

각각의 동작이 겹치니까 History를 따로 두어야 하는데, 그냥 Enum으로 History에 단계를 주었다.
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

	queue<COOR> SpreadQ;// 벽을 만나면 현재 위치를 저장
	queue<COOR> MeltQ; // 벽을 만나면 벽을 저장

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