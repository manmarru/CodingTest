#include "pch.h"
#include "Header.h"
#include <stack>

void Solve(ifstream* pLoadStream)
{
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