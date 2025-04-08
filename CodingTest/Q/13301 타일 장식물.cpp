#include "pch.h"
#include "Header.h"
#include <vector>

void Solve(ifstream* _pLoadStream)
{
	/*
	피보나치 수열의 변을 가지는 정사각형을 나선으로 이어 붙임
	구조물의 둘레의 길이를 구하기
	가장 큰놈 세번
	그다음 두번
	그다음 두번
	그다음 한번
	더하면 되겠다
	dp[n] = dp[n - 1] + dp[n - 2]
	4
	6
	10
	16 = 9 + 4 + 2 + 1
	26 = 15 + 6 + 4 + 1
	*/
	vector<long long int> DP;
	int Input;
	CIN >> Input;
	if (Input == 1)
	{
		cout << 4;
		return;
	}
	else if (Input == 2)
	{
		cout << 6;
		return;
	}

	DP.resize(Input);
	DP[0] = 4;
	DP[1] = 6;
	for (int i = 2; i < Input; ++i)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
	}

	cout << DP[Input - 1];
}