#include "pch.h"
#include "Header.h"
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>

set<pair<int, int>> setHistory;
vector<vector<int>> vecMap;
int iSize;

int BFS(int _iStartY, int _iStartX)
{
	queue<pair<int, int>> stlDestination;
	stlDestination.push({ _iStartY, _iStartX });
	setHistory.insert({ _iStartY, _iStartX });
	int iResult{ 1 };

	pair<int, int> iDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
	pair<int, int> iCurr;
	while (!stlDestination.empty())
	{
		iCurr = stlDestination.front();
		stlDestination.pop();
		int iX, iY;
		for (int i = 0; i < 4; ++i)
		{
			iY = iCurr.first + iDir[i].first;
			iX = iCurr.second+ iDir[i].second;
			if (iX < 0 || iX >= iSize || iY < 0 || iY >= iSize)
				continue;
			if (vecMap[iY][iX] == 0)
				continue;
			if (setHistory.end() != setHistory.find({ iY, iX }))
				continue;
			stlDestination.push({ iY, iX });
			setHistory.insert({ iY, iX });
			++iResult;
		}

	}

	return iResult;
}

void Solve(ifstream* pLoadStream)
{
	/*
	단지 묶음의 갯수를 구하고
	각 단지 내 집의 수를 오름차순으로 정렬해서 출력하기
	*/

	string szInput;
	vector<int> vecResult;
	CIN >> iSize;
	vecMap.resize(iSize);
	for (int i = 0; i < iSize; ++i)
	{
		vecMap[i].resize(iSize);
		CIN >> szInput;
		for (int j = 0; j < iSize; ++j)
			vecMap[i][j] = szInput[j] - '0';
	}

	for (int y = 0; y < iSize; y++)
	{
		for (int x = 0; x < iSize; x++)
		{
			if (1 == vecMap[y][x] && setHistory.end() == setHistory.find({ y,x }))
			{
				vecResult.push_back(BFS(y, x));
			}
		}
	}

	sort(vecResult.begin(), vecResult.end());

	cout << vecResult.size() << '\n';
	for (int i : vecResult)
		cout << i << '\n';
}