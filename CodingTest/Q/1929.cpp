#include "pch.h"
#include "Header.h"
#include <vector>

void Solve(ifstream* pLoadStream)
{
	/*
	M 이상 N 이하의 소수들 구하기
	*/

	int iMin{}, iMax{};
	vector<bool> vecPrimes;
	CIN >> iMin >> iMax;

	vecPrimes.resize(iMax + 1);
	for (int i = 1; i < iMax + 1; ++i)
	{
		vecPrimes[i] = true;
	}
	
	vecPrimes[1] = false;
	for (int i = 2; i < iMax + 1; ++i)
	{
		if (vecPrimes[i])
		{
			for (int j = i * 2; j < iMax + 1; j += i)
			{
				vecPrimes[j] = false;
			}
		}
	}

	for (int i = iMin; i < iMax + 1; ++i)
	{
		if (vecPrimes[i])
			cout << i << endl;
	}
}