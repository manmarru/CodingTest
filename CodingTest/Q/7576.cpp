#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>

void Solve(ifstream* pLoadStream)
{
	/*
	익은 토마토는 인접한 토마토를 익힌다.
	전부 익을 떄까지 걸리는 시간 출력
	*/

	int iSizeX, iSizeY;
	CIN >> iSizeX >> iSizeY;
	vector<vector<int>> vecBox(iSizeY);
	queue<pair<int, int>> stlDestination;
	for (int y = 0; y < iSizeY; y++)
	{
		vecBox[y].resize(iSizeX);
		for (int x = 0; x < iSizeX; x++)
		{
			CIN >> vecBox[y][x];
			if (1 == vecBox[y][x])
				stlDestination.push({ y,x });
		}
	}

	int dirX[4]{ 1, -1, 0, 0 };
	int dirY[4]{ 0, 0, 1, -1 };
	int iCurr[2], iNext[2];

	while (!stlDestination.empty())
	{
		iCurr[0] = stlDestination.front().first;
		iCurr[1] = stlDestination.front().second;
		stlDestination.pop();
		for (int i = 0; i < 4; ++i)
		{
			iNext[0] = iCurr[0] + dirY[i];
			iNext[1] = iCurr[1] + dirX[i];
			if (iNext[0] < 0 || iNext[0] >= iSizeY || iNext[1] < 0 || iNext[1] >= iSizeX)
				continue;
			if (0 == vecBox[iNext[0]][iNext[1]])
			{
				stlDestination.push({ iNext[0], iNext[1] });
				vecBox[iNext[0]][iNext[1]] = vecBox[iCurr[0]][iCurr[1]] + 1;
			}
		}
	}

	int iResult{ 0 };
	for (int y = 0; y < iSizeY; y++)
	{
		for (int x = 0; x < iSizeX; x++)
		{
			if (0 == vecBox[y][x])
			{
				cout << -1;
				return;
			}
			if (vecBox[y][x] > iResult)
				iResult = vecBox[y][x];
		}
	}
	cout << iResult - 1;
}