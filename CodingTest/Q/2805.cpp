#include "pch.h"
#include "Header.h"
#include <vector>

void Solve(ifstream* _pLoadStream)
{
	/*
	모든 나무를 동일한 높이에서 자른다(기준보다 낮으면 안잘리는거고)
	부족하지 않은 최소 기준높이를 구하기
	*/


	int iSize;
	long long int iNeed;
	vector<long long int> vecTrees;
	CIN >> iSize >> iNeed;
	vecTrees.resize(iSize);
	long long int iLR[2]{ 0 };
	for (int i = 0; i < iSize; ++i)
	{
		CIN >> vecTrees[i];
		iLR[1] = max(iLR[1], vecTrees[i]);
	}

	long long int iGet{ 0 };
	long long int iMid{};
	long long int iResult{ 0 };
	while (iLR[0] <= iLR[1])
	{
		iMid = (iLR[0] + iLR[1]) / 2;
		iGet = 0;
		for (int i = 0; i < iSize; ++i)
		{
			iGet += max((long long int)0, vecTrees[i] - iMid);
		}
		if (iGet >= iNeed)
		{
			iLR[0] = iMid + 1;
			iResult = iMid;
		}
		else
			iLR[1] = iMid - 1;
	}
	cout << iResult;
}