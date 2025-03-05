#include "pch.h"
#include "Header.h"
#include <vector>

void Solve(ifstream* pLoadStream)
{
	/*
	그래프에서 한번에 이동 가능한(단방향) 노드 표를 보고 갈 수 있는 모든 노드를 표시하기
	갠적으로 잘푼거같음.
	*/
	int iSize;
	vector<vector<int>> vecLink;
	CIN >> iSize;
	vecLink.resize(iSize);
	for (int i = 0; i < iSize; ++i)
	{
		vecLink[i].resize(iSize);
		for (int j = 0; j < iSize; j++)
		{
			CIN >> vecLink[i][j];
		}
	}
	
	for (int iTarget = 0; iTarget < iSize; iTarget++)
	{
		for (int iLink = 0; iLink < iSize; iLink++)
		{
			if (vecLink[iLink][iTarget] == 1)
			{
				for (int i = 0; i < iSize; ++i)
				{
					vecLink[iLink][i] |= vecLink[iTarget][i];
				}
			}
		}
	}


	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < iSize; ++j)
		{
			cout << vecLink[i][j] << ' ';
		}
		cout << '\n';
	}
}