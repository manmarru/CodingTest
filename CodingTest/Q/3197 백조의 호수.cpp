#include "pch.h"
#include "Header.h"
#include <queue>
#include <vector>

enum MELT { MELT_L = 0, MELT_R = 1, NONE = 2 };

struct COOR
{
	int y, x;
	MELT Melt = NONE;
};

void Solve(ifstream* _pLoadStream)
{
	int SizeY, SizeX;
	vector<vector<char>> Board(SizeY, vector<char>(SizeX));
	vector<COOR> Bird;

	for (int y = 0; y < SizeY; ++y)
	{
		for (int x = 0; x < SizeX; ++x)
		{
			CIN >> Board[y][x];
			if (Board[y][x] == 'L')
			{
				Bird.push_back({ y, x });
			}
		}
	}
	Bird[0].Melt = MELT_L;
	Bird[1].Melt = MELT_R;


	queue<COOR> Destination;
	queue<COOR> Next;
	Next.push(Bird[0]);
	Next.push(Bird[1]);

	int Turn = 0;
	while (!Next.empty())
	{
		++Turn;
		while (!Destination.empty())
		{

		}
	}


}