#include "pch.h"
#include "Header.h"
#include <vector>

void Solve(ifstream* _pLoadStream)
{
	/*
	문제 읽다 말았고
	1 1 1 2 2 3 4 5 7 9
	n = (n - 2) + (n - 3)
	*/
	int iCase;
	int iTarget;

	CIN >> iCase;

	vector<long long int> vecDP(3);
	int iDPHistory{ 3 };
	vecDP[0] = 1;
	vecDP[1] = 1;
	vecDP[2] = 1;

	for (int Casenum = 0; Casenum < iCase; Casenum++)
	{
		CIN >> iTarget;
		vecDP.resize(max(iTarget, iDPHistory));
		for (int i = iDPHistory; i < iTarget; ++i)
		{
			vecDP[i] = vecDP[i - 2] + vecDP[i - 3];
		}
		cout << vecDP[iTarget - 1] << '\n';
		iDPHistory = max(iTarget, iDPHistory);
	}


}