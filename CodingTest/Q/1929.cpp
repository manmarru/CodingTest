#include "pch.h"
#include "Header.h"
#include <vector>
#include <algorithm>
#include <math.h>

void Solve(ifstream* pLoadStream)
{
	/*
	15% 절사평군(반올림값 사용)으로 난이도값 결정
	표본이 없으면 난이도는 0
	*/
	int iSize{};
	int iInput{};
	CIN >> iSize;
	if (0 == iSize)
	{
		cout << 0;
		return;
	}
	vector<int> vecNums;
	for (int i = 0; i < iSize; i++)
	{
		CIN >> iInput;
		vecNums.push_back(iInput);
	}
	sort(vecNums.begin(), vecNums.end());

	int iCut = floor((float)vecNums.size() * 0.15f + 0.5f);
	int avg{0};
	for (int i = iCut; i < iSize - iCut; i++)
	{
		avg += vecNums[i];
	}
	if (avg == 0)
	{
		cout << 0;
		return;
	}
	cout << floor((float)avg / (float)(vecNums.size() - (iCut * 2)) + 0.5f);
}