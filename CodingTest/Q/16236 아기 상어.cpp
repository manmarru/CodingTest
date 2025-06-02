#include "pch.h"
#include "Header.h"
#include <vector>
#include <list>
#include <queue>


/*
정사각형 공간
상어크기 = 2
1 <= 물고기크기 <= 6;
자기보다 작은 물고기만 먹을 수 있음
자기 크기만큼의 마릿수 물고기를 먹으면 크기 1 증가
상하좌우 이동은 1초, 가장 가까운 물고기부터 먹음(거리가 같으면 위쪽 > 왼쪽)
자기보다 큰 물고기가 있는 곳은 지나갈 수 없음.
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


const int dY[4]{ -1, 1, 0, 0 }; // 위 먼저
const int dX[4]{ 0, 0, -1, 1 }; // 왼쪽 먼저


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

			if (0 != CatchingFish.size()) // 물고기들이 잡힙
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
				//cout << 라인 << SharkSize << endl;
				//system("pause");