#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>

enum TILE { TILE_INNER, TILE_CHEESE, TILE_DANGER, TILE_MELTING, TILE_AIR, TILE_END };

/*
�� �� �̻� ���⿡ ������ �ѽð� �� ����
ġ�� ���ο� ����� ���Ⱑ �ƴ�
�� ��µ� �ɸ��� �ð� ���ϱ�
�����ڸ����� ġ� ����.
*/

int dX[4] = { 0, 0, 1, -1 };
int dY[4] = { 1, -1, 0, 0 };

vector<vector<TILE>> Refrigerator;
int Height, Width;
queue<pair<int, int>> NextMelting;

void SpreadAir(int _y, int _x) // �Լ� �и������� �������� �� ������ �ʹ� ���� ���� �Ѵ�.
{
	queue<pair<int, int>> Destination;
	pair<int, int> Curr, Next;
	Destination.push({ _y, _x });
	Refrigerator[_y][_x] = TILE_AIR;

	while (!Destination.empty())
	{
		Curr = Destination.front();
		Destination.pop();
		Refrigerator[Curr.first][Curr.second] = TILE_AIR;
		for (int i = 0; i < 4; ++i)
		{
			Next = { Curr.first + dY[i], Curr.second + dX[i] };
			if (0 > Next.first || 0 > Next.second
				|| Width <= Next.second || Height <= Next.first)
				continue;

			TILE& Temp = Refrigerator[Next.first][Next.second];

			if (Temp == TILE_INNER)
			{
				Temp = TILE_AIR;
				Destination.push(Next);
			}
			else if (Temp == TILE_CHEESE)
			{
				Temp = TILE_DANGER;
			}
			else if (Temp == TILE_DANGER)
			{
				Temp = TILE_MELTING;
				NextMelting.push(Next);
			}
		}
	}
}

void Solve(ifstream* _pLoadStream)
{
	CIN >> Height >> Width;
	Refrigerator.resize(Height, vector<TILE>(Width, TILE_AIR));
	int Input;
	for (int y = 0; y < Height; ++y)
	{
		for (int x = 0; x < Width; ++x)
		{
			CIN >> Input;
			Refrigerator[y][x] = (TILE)Input;
		}
	}

	SpreadAir(0, 0);
	pair<int, int> Curr, Next;

	int Result{ 0 };
	queue<pair<int, int>> Melting;

	while (!NextMelting.empty()) // ġ�� ���̱�
	{
		swap(Melting, NextMelting);
		Result += 1;
		while (!Melting.empty())
		{
			Curr = Melting.front();
			Melting.pop();
			Refrigerator[Curr.first][Curr.second] = TILE_AIR;

			for (int i = 0; i < 4; ++i)
			{
				Next = { Curr.first + dY[i],Curr.second + dX[i] };
				if (0 > Next.first || 0 > Next.second
					|| Width <= Next.second || Height <= Next.first)
					continue;

				TILE& Temp = Refrigerator[Next.first][Next.second];
				if (Temp == TILE_CHEESE)
				{
					Temp = TILE_DANGER;
				}
				else if (Temp == TILE_DANGER)
				{
					Temp = TILE_MELTING;
					NextMelting.push({ Next });
				}
				else if (Temp == TILE_INNER)
				{
					SpreadAir(Next.first, Next.second);
				}
			}
		}
	}

	cout << Result;
}