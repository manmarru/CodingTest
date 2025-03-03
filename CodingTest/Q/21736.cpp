#include "pch.h"
#include "Header.h"
#include <vector>
#include <set>
#include <queue>

void Solve(ifstream* pLoadStream)
{
	/*
	4방향 이동을 통해 만날 수 있는 사람의 수 구하기
	0명이면 TT 출력 ㅠㅠ
	*/

	int iX, iY;
	CIN >> iY >> iX;
	queue<pair<int, int>> strDestination;
	set<pair<int, int>> setHistory;
	int iResult{ 0 };

	vector<vector<char>> vecMap;
	vecMap.resize(iY);
	for (int y = 0; y < iY; y++)
	{
		vecMap[y].resize(iX);
		for (int x = 0; x < iX; x++)
		{
			CIN >> vecMap[y][x];
			if (vecMap[y][x] == 'I')
			{
				strDestination.push({ y,x });
				setHistory.insert({ y,x });
			}
		}
	}
	//여기까지가 입력

	int iCurrX, iCurrY;
	vector<pair<int, int>> vecDir;
	vecDir.push_back({ 1, 0 });
	vecDir.push_back({ -1, 0 });
	vecDir.push_back({ 0, 1 });
	vecDir.push_back({ 0, -1 });
	while (!strDestination.empty())
	{
		iCurrY = strDestination.front().first;
		iCurrX = strDestination.front().second;
		strDestination.pop();

		for (auto dir : vecDir)
		{
			int Y = iCurrY + dir.first;
			int X = iCurrX + dir.second;
			if (0 <= Y && iY > Y && 0 <= X && iX > X)
			{
				if (setHistory.find({ Y, X }) == setHistory.end())
				{
					setHistory.insert({ Y, X });
					if ('O' == vecMap[Y][X])
					{
						strDestination.push({ Y , X });
					}
					else if ('P' == vecMap[Y][X])
					{
						strDestination.push({ Y , X });
						++iResult;
					}
				}
			}
		}

	}



	if (0 == iResult)
		cout << "TT";
	else
		cout << iResult;
 }