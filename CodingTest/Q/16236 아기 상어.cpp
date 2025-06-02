#include "pch.h"
#include "Header.h"
#include <vector>
#include <list>
#include <queue>


/*
���簢�� ����
���ũ�� = 2
1 <= �����ũ�� <= 6;
�ڱ⺸�� ���� ����⸸ ���� �� ����
�ڱ� ũ�⸸ŭ�� ������ ����⸦ ������ ũ�� 1 ����
�����¿� �̵��� 1��, ���� ����� �������� ����(�Ÿ��� ������ ���� > ����)
�ڱ⺸�� ū ����Ⱑ �ִ� ���� ������ �� ����.
*/

struct COOR
{
	int y;
	int x;
	bool operator <(COOR& Temp)
	{
		if (y == Temp.y)
			return x < Temp.x;
		return y < Temp.y;
	}
};


const int dY[4]{ -1, 1, 0, 0 }; // �� ����
const int dX[4]{ 0, 0, -1, 1 }; // ���� ����


void Solve(ifstream* _pLoadStream)
{
	int TileSize;
	CIN >> TileSize;

	vector<vector<int>> Tile(TileSize, vector<int>(TileSize, 0));
	COOR Shark;
	for (int y = 0; y < TileSize; ++y)
	{
		for (int x = 0; x < TileSize; ++x)
		{
			CIN >> Tile[y][x];
			if (Tile[y][x] == 9)
			{
				Shark = { y, x };
				Tile[y][x] = 0;
			}
		}
	}

	int SharkSize{ 2 };
	int SharkEat{ 0 };
	int Result{ 0 };
	bool Eaten{ true };
	while (1)
	{
		if (!Eaten)
			break;

		Eaten = false;

		int MoveTime{ 0 };
		queue<COOR> Destination;
		queue<COOR> NextDestination;
		COOR Curr, Next;
		vector<vector<bool>> History(TileSize, vector<bool>(TileSize, false));

		NextDestination.push(Shark);
		History[Shark.y][Shark.x] = true;
		while (!NextDestination.empty())
		{
			list<COOR> CatchingFish;
			swap(Destination, NextDestination);
			++MoveTime;
			while (!Destination.empty())
			{
				Curr = Destination.front();
				Destination.pop();
				if (0 != Tile[Curr.y][Curr.x] && Tile[Curr.y][Curr.x] < SharkSize)
				{
					CatchingFish.push_back(Curr);
				}

				for (int dir = 0; dir < 4; ++dir)
				{
					Next = { Curr.y + dY[dir], Curr.x + dX[dir] };
					if (Next.y < 0 || TileSize <= Next.y || Next.x < 0 || TileSize <= Next.x)
						continue;

					if (History[Next.y][Next.x])
						continue;

					if (Tile[Next.y][Next.x] > SharkSize)
						continue;

					NextDestination.push(Next);
					History[Next.y][Next.x] = true;
				}
			}

			if (0 != CatchingFish.size()) // �������� ����
			{
				Eaten = true;
				CatchingFish.sort();
				COOR Fish = CatchingFish.front();
				Shark = Fish;
				Tile[Fish.y][Fish.x] = 0;
				++SharkEat;
				Result += MoveTime - 1;
				if (SharkEat == SharkSize)
				{
					++SharkSize;
					SharkEat = 0;
				}

				break;
			}
		}
	}



	cout << Result;
}



				//for (int y = 0; y < TileSize; ++y)
				//{
				//	for (int x = 0; x < TileSize; ++x)
				//	{
				//		cout << Tile[y][x] << ' ';
				//	}
				//	cout << endl;
				//}
				//cout << ���� << SharkSize << endl;
				//system("pause");