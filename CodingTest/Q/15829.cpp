#include "pch.h"
#include "Header.h"

void Solve(ifstream* pLoadStream)
{
	/*
	Hashing
	r = 31, m = 1234567891
	���� ������ ������ �������� ���� �и��� �����ϴ�.
	����ȯ �ص�������̴�.
	*/
	unsigned long iR(31), iM(1234567891);
	unsigned long iResult(0);
	unsigned long iLength(0);
	string strInput;
	*pLoadStream >> iLength;
	*pLoadStream >> strInput;


	for (int i = 0; i < iLength; ++i)
	{
		if (i < 8)
			iResult += (strInput[i] - 'a' + 1) * pow(iR, i);
		else
		{
			unsigned long iSum(1);
			for (unsigned long j = 0; j < i; ++j)
			{
				iSum *= iR;
				iSum %= iM;
			}
			iResult += (strInput[i] - 'a' + 1) * iSum;
		}
		iResult %= iM;
	}

	cout << iResult;
}