#include "pch.h"
#include "Header.h"
#include <vector>

void Solve(ifstream* _pLoadStream)
{
	/*
	��� ������ ������ ���̿��� �ڸ���(���غ��� ������ ���߸��°Ű�)
	�������� ���� �ּ� ���س��̸� ���ϱ�
	*/


	int iSize;
	long long int iNeed;
	vector<long long int> vecTrees;
	CIN >> iSize >> iNeed;
	vecTrees.resize(iSize);
	long long int iLR[2]{ 0 };
	for (int i = 0; i < iSize; ++i)
	{
		CIN >> vecTrees[i];
		iLR[1] = max(iLR[1], vecTrees[i]);
	}

	long long int iGet{ 0 };
	long long int iMid{};
	long long int iResult{ 0 };
	while (iLR[0] <= iLR[1])
	{
		iMid = (iLR[0] + iLR[1]) / 2;
		iGet = 0;
		for (int i = 0; i < iSize; ++i)
		{
			iGet += max((long long int)0, vecTrees[i] - iMid);
		}
		if (iGet >= iNeed)
		{
			iLR[0] = iMid + 1;
			iResult = iMid;
		}
		else
			iLR[1] = iMid - 1;
	}
	cout << iResult;
}