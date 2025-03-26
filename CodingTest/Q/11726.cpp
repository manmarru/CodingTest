#include "pch.h"
#include "Header.h"
#include <vector>

void Solve(ifstream* _pLoadStream)
{
	/*
	2*n 크기의 직사각형을 채우는 방법의 수를 10007로 나눈 나머지를 출력

	가로로 몇개 세로로 몇개 넣는지 세는 문제네, input이 홀수면 세로가 홀수여야 함
	피보나치수열이네!
	*/

	int iInput;
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
	vector<long long int> vecDP;
	vecDP.resize(iInput);
	vecDP[0] = 1;
	vecDP[1] = 2;

	for (int i = 2; i < iInput; ++i)
		vecDP[i] = vecDP[i - 1] + vecDP[i - 2];

	cout << vecDP[iInput - 1] % 10007;
}