#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>

void Solve(ifstream* pLoadStream)
{
	/*
	모든 지점에 대해서 목표지점까지의 거리 구하기
	목표지점은 2, 장해물은 0으로 표시되며
	장해물이 있는 곳은 0으로 출력하면 됨.
	*/

	int iSizeY, iSizeX;
	CIN >> iSizeY >> iSizeX;
	vector<vector<int>> vecMap;
	vector<vector<int>> vecResult;
	int iTarget[2];
	vecMap.resize(iSizeY);
	vecResult.resize(iSizeY);
	for (int i = 0; i < iSizeY; ++i)
	{
		vecMap[i].resize(iSizeX);
		vecResult[i].resize(iSizeX, {0});
		for (int j = 0; j < iSizeX; j++)
		{
			CIN >> vecMap[i][j];
			if (vecMap[i][j] == 2)
			{
				iTarget[0] = i;
				iTarget[1] = j;
			}
		}
	}

	queue<pair<int, int>> stlDestination;
	stlDestination.push({ iTarget[0], iTarget[1] });
	pair<int, int> iDir[4]{ { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
	int iCurr[2], iNext[2];
	while (!stlDestination.empty())
	{
		iCurr[0] = stlDestination.front().first;
		iCurr[1] = stlDestination.front().second;
		stlDestination.pop();
		for (pair<int, int> Dir : iDir)
		{
			iNext[0] = iCurr[0] + Dir.first;
			iNext[1] = iCurr[1] + Dir.second;
			if (0 > iNext[0] || iNext[0] >= iSizeY || 0 > iNext[1] || iNext[1] >= iSizeX)
				continue;
			if (0 == vecMap[iNext[0]][iNext[1]])
				continue;
			if (0 != vecResult[iNext[0]][iNext[1]])
				continue;
			vecResult[iNext[0]][iNext[1]] += vecResult[iCurr[0]][iCurr[1]] + 1;
			stlDestination.push({ iNext[0], iNext[1] });
		}
	}
	vecResult[iTarget[0]][iTarget[1]] = 0; //시작점이 2가 되거든



	for (int i = 0; i < iSizeY; ++i)
	{
		for (int j = 0; j < iSizeX; j++)
		{
			if (0 == vecResult[i][j] && 1 == vecMap[i][j])
				cout << -1 << ' ';
			else
				cout << vecResult[i][j] << ' ';
		}
		cout << '\n';
	}

}