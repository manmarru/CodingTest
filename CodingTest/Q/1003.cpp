#include "pch.h"
#include "Header.h"
#include <vector>

void Solve(ifstream* _pLoadStream)
{
	int iSize{};
	CIN >> iSize;

	long long int iResult[2]{ 0,0 };
	int iInput{};
	vector<pair<int, int>> vecFibonacci;
	vecFibonacci.resize(41);
	vecFibonacci[0] = { 1,0 };
	vecFibonacci[1] = { 0,1 };
	for (int j = 0; j < iSize; ++j)
	{
		CIN >> iInput;
		if (0 == iInput)
		{
			cout << 1 << ' ' << 0 << '\n';
			continue;
		}
		else if (1 == iInput)
		{
			cout << 0 << ' ' << 1 << '\n';
			continue;
		}

		for (int i = 2; i <= iInput; ++i)
		{
			vecFibonacci[i].first = vecFibonacci[i - 1].first + vecFibonacci[i - 2].first;
			vecFibonacci[i].second = vecFibonacci[i - 1].second + vecFibonacci[i - 2].second;
		}

		cout << vecFibonacci[iInput].first << ' ' << vecFibonacci[iInput].second << '\n';
	}
}