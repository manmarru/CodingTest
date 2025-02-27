#include "pch.h"
#include "Header.h"
#include <vector>

void Solve(ifstream* pLoadStream)
{
	int iInput{};
	CIN >> iInput;

	if (1 == iInput)
		cout << 1;
	else if (2 == iInput)
		cout << 3;
	vector<int> vecDP(iInput);
	vecDP[0] = 1;
	vecDP[1] = 3;

	for (int i = 2; i < iInput; ++i)
	{
		vecDP[i] = (vecDP[i - 1] + vecDP[i - 2] * 2) % 10007;
	}

	cout << vecDP[iInput - 1];
}