#include "pch.h"
#include "Header.h"
#include <vector>
#include <string>

void Solve(ifstream* _pLoadStream)
{
	/*
	최장 공통 부분 수열들 중 가장 긴 걸 구하기
	*/

	vector<int>DP;
	string Input[2];
	CIN >> Input[0] >> Input[1];
	int Size{ Input[0].size() };

	DP.reserve(Size + 1);
	for (int i = 0; i <= Size; ++i)
	{
		DP[i] = ;


	}
}