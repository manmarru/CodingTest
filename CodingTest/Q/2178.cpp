#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>
#include <string>

void Solve(ifstream* pLoadStream)
{
	/*
	0,0 에서 반대쪽 끝까지 가는데 걸리는 횟수 구하기
	*/
	
	int iSizeY, iSizeX;
	string szInput;
	CIN >> iSizeY >> iSizeX;

	vector<vector<int>> vecMap;
	vecMap.resize(iSizeY);
	for (int y = 0; y < iSizeY; y++)
	{
		vecMap[y].resize(iSizeX);
		CIN >> szInput;
		for (int x = 0; x < iSizeX; x++)
		{
			vecMap[y][x] = szInput[x] - '0';

		}
	}
//여기까지 입력
	queue<pair<int, int>> stlDestination;
	stlDestination.push({ 0,0 });

	int iX, iY;
	while (1)
	{
		iY = stlDestination.front().first;
		iX = stlDestination.front().second;
		if ((iY == iSizeY - 1) && (iX == iSizeX - 1))
			break;
		stlDestination.pop();

		if ((0 < iY) && (vecMap[iY - 1][iX] == 1))
		{
			stlDestination.push({ iY - 1, iX });
			vecMap[iY - 1][iX] += vecMap[iY][iX];
		}
		if ((iSizeY - 1 > iY) && (vecMap[iY + 1][iX] == 1))
		{
			stlDestination.push({ iY + 1, iX });
			vecMap[iY + 1][iX] += vecMap[iY][iX];
		}
		if ((0 < iX) && (vecMap[iY][iX - 1] == 1))
		{
			stlDestination.push({ iY, iX - 1 });
			vecMap[iY][iX - 1] += vecMap[iY][iX];
		}
		if ((iSizeX - 1 > iX) && (vecMap[iY][iX + 1] == 1))
		{
			stlDestination.push({ iY, iX + 1 });
			vecMap[iY][iX + 1] += vecMap[iY][iX];
		}
	}

	cout << vecMap[iSizeY - 1][iSizeX - 1];
}