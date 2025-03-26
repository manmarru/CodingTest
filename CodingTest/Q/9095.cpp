#include "pch.h"
#include "Header.h"
#include <vector>

void Solve(ifstream* _pLoadStream)
{
	/*
	정수를 1,2,3의 합으로 나타내기 (순서가 다르면 다른 경우임)
	dp[n] = dp[n-3] + dp[n-2] + dp[n-1]
	*/

	int iSize{};
	CIN >> iSize;
	int iInput{};
	vector<int> vecDP;
	vecDP.resize(12);
	vecDP[0] = 1;
	vecDP[1] = 1;
	vecDP[2] = 2;
	vecDP[3] = 4;

	int iDPHidstoy{ 3 };
	for (int i = 0; i < iSize; ++i)
	{
		CIN >> iInput;
		for (int j = iDPHidstoy + 1; j <= iInput; ++j)
		{
			vecDP[j] = vecDP[j - 3] + vecDP[j - 2] + vecDP[j - 1];
		}
		cout << vecDP[iInput] << endl;
	}
}