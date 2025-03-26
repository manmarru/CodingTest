#include "pch.h"
#include "Header.h"
#include <stack>

void Solve(ifstream* _pLoadStream)
{
	/*
	K원을 만들 수 있는 동전 갯수의 최솟값 구하기

	N K
	N개만큼 동전의 종류가 제시됨
	*/
	int iSize{};
	int iTarget{};
	CIN >> iSize >> iTarget;
	stack<int> stlCoins;
	int iInput{};
	int iResult{ 0 };

	for (int i = 0; i < iSize; i++)
	{
		CIN >> iInput;
		stlCoins.push(iInput);
	}

	while (iTarget != 0)
	{

		iResult += (iTarget / stlCoins.top());
		iTarget = iTarget % stlCoins.top();
		stlCoins.pop();
	}
	cout << iResult;
}