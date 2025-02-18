#include "pch.h"
#include "Header.h"

void Solve(ifstream* pLoadStream)
{
	/*
	이항계수
	n! / k!(n-k)!
	*/
	int iN, iK;
	(*pLoadStream) >> iN >> iK;

	int iResult = 1;
	for (int i = iN; i > iK; --i)
	{
		iResult *= i;
	}
	for (int i = 1; i <= (iN - iK); i++)
	{
		iResult /= i;
	}

	cout << iResult << endl;
}