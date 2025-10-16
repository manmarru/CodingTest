#include "pch.h"
#include "Header.h"
#include <queue>


/*
https://www.acmicpc.net/problem/14497
ġ�� ���̴� ������ ����ϰ� �ߴ�. ������
�̴ϼȶ����� ����Ʈ ��ôµ� �������� ������? �ͱ�� ��
������ �ѹ� ���ΰű� ������
*/


struct COOR
{
	int y, x;
	bool operator ==(COOR Temp)
	{
		return y == Temp.y && x == Temp.x;
	}
};

void Solve(ifstream* _pLoadStream)
{
	int SizeY, SizeX;
	COOR Jun, Target;

	CIN >> SizeY >> SizeX >> Jun.y >> Jun.x >> Target.y >> Target.x;
	--Jun.y; --Jun.x; --Target.y; --Target.x;
	vector<vector<char>> Board(SizeY, vector<char>(SizeX));
	for (int y = 0; y < SizeY; ++y)
	{
		for (int x = 0; x < SizeX; ++x)
		{
			CIN >> Board[y][x];
		}
	}

	queue<COOR> Destination;
	queue<COOR> NextQ;
	NextQ.push(Jun);
	Board[Jun.y][Jun.x] = '2';

	COOR Curr;
	int Result = 0;
	while (!NextQ.empty())
	{
		++Result;
		swap(NextQ, Destination);
		while (!Destination.empty())
		{
			Curr = Destination.front();
			Destination.pop();

			for (COOR Next : initializer_list<COOR>
				{ { Curr.y - 1, Curr.x + 0 }
				, { Curr.y + 1, Curr.x + 0 }
				, { Curr.y + 0, Curr.x - 1 }
				, { Curr.y + 0, Curr.x + 1 } })
			{
				if (Next.y < 0 || Next.y >= SizeY || Next.x < 0 || Next.x >= SizeX)
					continue;

				if (Board[Next.y][Next.x] == '2')
					continue;
				else if (Board[Next.y][Next.x] == '1')
				{
					NextQ.push(Next);
				}
				else if (Board[Next.y][Next.x] == '0')
				{
					Destination.push(Next);
				}
				else // Ÿ��
				{
					cout << Result;
					return;
				}
				Board[Next.y][Next.x] = '2';
			}
		}
	}
}