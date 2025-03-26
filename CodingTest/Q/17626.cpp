#include "pch.h"
#include "Header.h"
#include <vector>

int pow2(int _input)
{
	return _input * _input;
}

void Solve(ifstream* _pLoadStream)
{
	/*
	¶ó±×¶ûÁÖ ³× Á¦°ö¼ö
	*/
	int iInput{};
	vector<int> vecDP;
	CIN >> iInput;
	if (1 == iInput)
	{
		cout << 1;
		return;
	}
	else if (2 == iInput)
	{
		cout << 2;
		return;
	}

	vecDP.resize(iInput + 1);
	fill(vecDP.begin(), vecDP.end(), 4);
	vecDP[0] = 0;
	vecDP[1] = 1;
	
	for (int i = 2; i <= iInput; ++i)
	{
		for (int j = 1; j * j <= i; ++j)
		{
			vecDP[i] = min(vecDP[i], vecDP[i - pow2(j)] + 1);
		}
	}

	cout << vecDP[iInput];
}