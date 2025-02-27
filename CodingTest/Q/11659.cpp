#include "pch.h"
#include "Header.h"
#include <vector>

void Solve(ifstream* pLoadStream)
{
	/*
	주어진 숫자들의 i 부터 j 번째 숫자까지의 합 구하기
	누적합
	*/


	int iSize[2];
	vector<int> vecNums;
	vector<int> vecSum;
	CIN >> iSize[0] >> iSize[1];
	vecNums.resize(iSize[0]);
	vecSum.resize(iSize[0]);
	for (int i = 0; i < iSize[0]; ++i)
	{
		CIN >> vecNums[i];
	}
	vecSum[0] = vecNums[0];
	for (int i = 1; i < iSize[0]; ++i)
	{
		vecSum[i] = vecSum[i - 1] + vecNums[i];
	}

	int iInput[2];
	int iResult;
	for (int i = 0; i < iSize[1]; ++i)
	{
		CIN >> iInput[0] >> iInput[1];
		iResult = vecSum[iInput[1] - 1] - vecSum[iInput[0] - 1] + vecNums[iInput[0] - 1 ];

		cout << iResult << '\n';
	}

}