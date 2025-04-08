#include "pch.h"
#include "Header.h"
#include <vector>

void Solve(ifstream* _pLoadStream)
{
	/*
	3���� ������ �������� 3���� ����
	2�� ������ �������� 2�� ����
	1�� ����.
	N�� 1�� ���� �� �ִ� ���� �ּڰ� ���

	1���� dp���� �ɵ�?
	*/

	int iTarget;
	CIN >> iTarget;
	vector<int> vecDP;
	vecDP.resize(iTarget + 1);
	if (1 == iTarget)
	{
		cout << 0;
		return;
	}

	vecDP[1] = 0;

	for (int i = 2; i <= iTarget; i++)
	{
		if (i % 6 == 0)
			vecDP[i] = min(min(vecDP[i / 3], vecDP[i / 2]), vecDP[i - 1]) + 1;
		else if (i % 3 == 0)
			vecDP[i] = min(vecDP[i / 3], vecDP[i - 1]) + 1;
		else if (i % 2 == 0)
			vecDP[i] = min(vecDP[i / 2], vecDP[i - 1]) + 1;
		else
			vecDP[i] = vecDP[i - 1] + 1;
	}


	cout << vecDP[iTarget];
}