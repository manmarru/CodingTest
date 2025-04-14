#include "pch.h"
#include "Header.h"
#include <vector>
#include <string>

void Solve(ifstream* _pLoadStream)
{
	/*
	최장 공통 부분 수열들 중 가장 긴 걸 구하기
	A[i] == B[j] 이면
	DP[i][j] = DP[i - 1][j - 1] + 1;
	아니면 DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
	*/

	vector<vector<int>>DP;
	string Input[2];
	CIN >> Input[0] >> Input[1];
	int Size[2]{ (int)Input[0].length(), (int)Input[1].length() };

	cout << Input[0] << '\n' << Input[1] << endl;

	DP.resize(Size[0] + 1);
	for (int i = 0; i <= Size[0]; ++i)
	{
		DP[i].resize(Size[1] + 1);
	}


	for (int i = 0; i < Size[0]; ++i)
	{
		for (int j = 0; j < Size[1]; ++j)
		{
			if (Input[0][i] == Input[1][j])
			{
				DP[i + 1][j + 1] = DP[i][j] + 1;
			}
			else
			{
				DP[i + 1][j + 1] = max(DP[i][j + 1], DP[i + 1][j]);
			}
		}
	}
	cout << DP[Size[0]][Size[1]];
}