#include "pch.h"
#include "Header.h"
#include <vector>
#include <algorithm>
#include <limits>
vector<int> vecLANs;

int CableCut(int _iSize)
{
	int iResult{ 0 };
	for (int i = 0; i < (int)vecLANs.size(); ++i)
	{
		iResult += int(vecLANs[i] / _iSize);
	}

	return iResult;
}

void Solve(ifstream* _pLoadStream)
{
	/*
	랜선들을 잘라서 N개 이상의 선을 만들어야 할 때 가능한 가장 긴 선의 길이
	
	매개변수 탐색 + 이분탐색

	참고로 문제에서 랜선 길이가 21억까지 나와서 iLeft + iRight 하면 42억까지 나와서 int 범위 넘어갈 수도 있음
	그래서 int가 아니라 long long int 써야된다.
	*/

#pragma region 입력

	int iSize{};
	int iNeed{};
	CIN >> iSize >> iNeed;
	vecLANs.resize(iSize);
	for (int i = 0; i < iSize; ++i)
		CIN >> vecLANs[i];
#pragma endregion

	int iTemp;
	int iLeft{ 1 }, iRight{*max_element(vecLANs.begin(), vecLANs.end())};
	int iMid{};
	while (1)
	{
		iMid = (iLeft + iRight) / 2;
		iTemp = CableCut(iMid);

		if (iTemp < iNeed)
		{
			iRight = iMid - 1;
		}
		else if (iTemp >= iNeed)
		{
			iLeft = iMid + 1;
		}
		if (iLeft > iRight)
			break;
	}


	cout << iRight;
}