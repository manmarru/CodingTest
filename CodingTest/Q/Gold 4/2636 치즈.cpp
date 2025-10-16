#include "pch.h"
#include "Header.h"
#include <queue>
#include <vector>

//ġ���
/*
https://www.acmicpc.net/problem/2636
vector<char>�� ����ϸ鼭 cin���� ������ �޾Ҵµ�
1�� �Է¹����� ����1�� �ƴ϶� '1' �� �ԷµǴ°� ���� ����!
�̰� ������ �ްڴٰ� vector<signed char>�� ����ص� �޶����°� ����.
*/
struct COOR
{
	int y, x;
};

int dy[4]{ -1, 1, 0, 0 };
int dx[4]{ 0, 0, -1, 1 };

void Solve(ifstream* _pLoadStream)
{	
	vector<vector<char>> History;
	vector<vector<char>> Board;
	int SizeY, SizeX;

	CIN >> SizeY >> SizeX;
	Board.resize(SizeY, vector<char>(SizeX));
	History.resize(SizeY, vector<char>(SizeX));

	for (int y = 0; y < SizeY; ++y)
	{
		for (int x = 0; x < SizeX; ++x)
		{
			CIN >> Board[y][x];
		}
	}

	queue<COOR> Destination;
	queue<COOR> Melting;
	COOR Curr;
	COOR Next;
	int Count = 0;
	Destination.push({ 0, 0 });
	History[0][0] = true;
	int Answer;
	while (++Count)
	{
		while (!Destination.empty())
		{
			Curr = Destination.front();
			Destination.pop();
			
			for (int i = 0; i < 4; ++i)
			{
				Next = { Curr.y + dy[i], Curr.x + dx[i] };
				if (Next.y < 0 || Next.y == SizeY || Next.x < 0 || Next.x == SizeX)
					continue;

				if (true == History[Next.y][Next.x])
					continue;
				History[Next.y][Next.x] = true;

				if ('1' == Board[Next.y][Next.x])
				{
					Melting.push(Next);
					continue;
				}
				Destination.push(Next);
			}
		}

		if (true == Melting.empty())
		{
			cout << Count - 1 << '\n' << Answer;
			return;
		}
		Answer = Melting.size();
		while (!Melting.empty())
		{
			Curr = Melting.front();
			Melting.pop();
			History[Curr.y][Curr.x] = true;
			Destination.push(Curr);
			Board[Curr.y][Curr.x] = 0;
		}
	}
}