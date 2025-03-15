#include "pch.h"
#include "Header.h"
#include <vector>

void Solve(ifstream* pLoadStream)
{
	/*
	수열에서 가장 긴 증가하는 부분 수열을 구하기
	
	LTS, 이분탐색 공부하기(이분탐색은 알지?)
	https://www.acmicpc.net/source/91413109
	*/

	int Size;
	vector<int> Nums;
	vector<int> DP;

	CIN >> Size;
	Nums.resize(Size + 1);
	DP.resize(Size + 1, 1);
	DP[0] = 0;
	int Result{ 0 };
	for (int i = 1; i <= Size; i++)
	{
		CIN >> Nums[i];

		for (int j = 1; j < i; ++j)
		{
			if (Nums[j] < Nums[i] && DP[i] <= DP[j])
			{
				DP[i] = DP[j] + 1;
			}
		}
		Result = max(Result, DP[i]);
	}

	cout << Result;
}