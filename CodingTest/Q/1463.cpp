#include "pch.h"
#include "Header.h"
#include <vector>

void Solve(ifstream* _pLoadStream)
{
	/*
	3으로 나누어 떨어지면 3으로 나눔
	2로 나누어 떨어지면 2로 나눔
	1을 뺀다.
	N을 1로 만들 수 있는 연산 최솟값 출력

	1부터 dp쓰면 될듯?
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