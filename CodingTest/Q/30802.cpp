#include "pch.h"
#include "Header.h"
#include <limits>

void Solve(ifstream* pLoadStream)
{
	//T 씩 몇 묶음 사야 하는지
	//P 자루씩 최대 몇 묶음 살 수 있는지, 그때 한자루씩 몇개 주문하는지

	int iN(0);
	int iSize[6] = { 0, 0, 0, 0, 0, 0 };
	int iT(0), iP(0);
	int iShirtAnswer(0);
	(*pLoadStream) >> iN;

	for (size_t i = 0; i < 6; i++)
	{
		(*pLoadStream) >> iSize[i];
	}

	(*pLoadStream) >> iT >> iP;
	for (size_t i = 0; i < 6; i++)
	{
		iShirtAnswer += (iSize[i] / iT);
		if (0 != iSize[i] % iT)
			iShirtAnswer += 1;
	}

	cout << iShirtAnswer << '\n' << (iN / iP) << ' ' << iN % iP << endl;


}