#include "pch.h"
#include "Header.h"
#include <vector>


void Solve(ifstream* pLoadStream)
{
	/*
	+1 or +2
	연속 3개 밟기금지 (시작점 제외
	마지막은 반드시 밟아야 함

	n번째 계단 = DP(n - 2) + n
	or
	DP(n - 3) + n - 1 + n
	*/

	int iSize{};
	int iInput{};
	vector<int> vecScore;
	vector<int> vecDP;
	CIN >> iSize;
	vecScore.resize(iSize);
	vecDP.resize(iSize);
	for (int i = 0; i < iSize; ++i)
	{
		CIN >> iInput;
		vecScore[i] = iInput;
	}

	if (1 == iSize)
	{
		cout << vecScore[0];
		return;
	}
	else if (2 == iSize)
	{
		cout << vecScore[0] + vecScore[1];
		return;
	}
	else if (3 == iSize)
	{
		cout << max(vecScore[1], vecScore[0]) + vecScore[2];
		return;
	}

	vecDP[0] = vecScore[0];
	vecDP[1] = vecScore[1] + vecScore[0];
	vecDP[2] = max(vecScore[1], vecScore[0]) + vecScore[2];
	for (int i = 3; i < iSize; ++i)
	{
		vecDP[i] = max(vecDP[i - 2], vecScore[i - 1] + vecDP[i - 3]) + vecScore[i];
	}

	
	cout << vecDP[iSize - 1];
}