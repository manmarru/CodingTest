#include "pch.h"
#include "Header.h"
#include <stack>

void Solve(ifstream* _pLoadStream)
{
	/*
	숫자를 입력받아서 입력값들의 합을 구함
	0이 입력되면 최근 입력값 제거
	*/
	unsigned long long iResult{ 0 };
	stack<int> stdNums;
	int iSize{};
	int iInput{};
	CIN >> iSize;
	for (int i = 0; i < iSize; i++)
	{
		CIN >> iInput;
		if (0 == iInput)
			stdNums.pop();
		else
			stdNums.push(iInput);
	}

	while (!stdNums.empty())
	{
		iResult += stdNums.top();
		stdNums.pop();
	}
	cout << iResult;
}