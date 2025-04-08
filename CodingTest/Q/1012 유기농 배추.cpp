#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>

vector<vector<bool>> vecHistory;//[����][����]
queue<pair<int, int>> stlDestination;

void WaySeek(int _ix, int _iy)
{
	vecHistory[_ix][_iy] = true;
	if (_ix > 0 && !vecHistory[_ix - 1][_iy])
	{
		stlDestination.push({ _ix - 1, _iy });
		vecHistory[_ix - 1][_iy] = true;
	}
	if (_ix < vecHistory.size() - 1 && !vecHistory[_ix + 1][_iy])
	{
		stlDestination.push({ _ix + 1, _iy });
		vecHistory[_ix + 1][_iy] = true;
	}
	if (_iy > 0 && !vecHistory[_ix][_iy - 1])
	{
		stlDestination.push({ _ix, _iy - 1 });
		vecHistory[_ix][_iy - 1] = true;
	}
	if (_iy < vecHistory[0].size() - 1 && !vecHistory[_ix][_iy + 1])
	{
		stlDestination.push({ _ix, _iy + 1 });
		vecHistory[_ix][_iy + 1] = true;
	}
}

void Solve(ifstream* _pLoadStream)
{
	/*
	���߰���
	*/

	int iCase;
	CIN >> iCase;
	int iWidth;
	int iHeight;
	int iSize;
	int iInput[2];
	int iResult{ 0 };
	
	for (int iCasenum = 0; iCasenum < iCase; ++iCasenum)
	{
		iResult = 0;
		CIN >> iWidth >> iHeight >> iSize;
		queue<pair<int, int>> SwapBuffer;
		swap(SwapBuffer, stlDestination);
		vecHistory.resize(iWidth);
		for (auto& vec : vecHistory)
			vec.resize(iHeight);
		for (int x = 0; x < iWidth; ++x)
		{
			fill(vecHistory[x].begin(), vecHistory[x].end(), true); // ���߰� ���� ���� ���ô� ������ ����
		}
		for (int i = 0; i < iSize; i++)
		{
			CIN >> iInput[0] >> iInput[1];
			vecHistory[iInput[0]][iInput[1]] = false;
		}


		for (int x = 0; x < iWidth; ++x)
		{
			for (int y = 0; y < iHeight; ++y)
			{
				if (!vecHistory[x][y])
				{
					WaySeek(x, y);

					while (!stlDestination.empty())
					{
						int iX = stlDestination.front().first;
						int iY = stlDestination.front().second;
						stlDestination.pop();

						WaySeek(iX, iY);
					}
					++iResult;
				}
			}
		}
		
		cout << iResult << '\n';
	}
}