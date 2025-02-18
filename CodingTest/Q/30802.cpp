#include "pch.h"
#include "Header.h"
#include <limits>

void Solve(ifstream* pLoadStream)
{
	//T �� �� ���� ��� �ϴ���
	//P �ڷ羿 �ִ� �� ���� �� �� �ִ���, �׶� ���ڷ羿 � �ֹ��ϴ���

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