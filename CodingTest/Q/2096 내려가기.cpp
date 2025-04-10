#include "pch.h"
#include "Header.h"
#include <vector>

enum WAY { MIN, MAX, WAY_END };
void Solve(ifstream* _pLoadStream)
{
	/*
	계단밟기랑 똑같은거임
	근데 Nums를 다 저장하지 않고 CIN 하면서 바로바로 처리하면 메모리 절약이 되긴 한다.
	https://www.acmicpc.net/source/92883913

	
	*/
	int Size;
	CIN >> Size;
	vector<int> Nums[3];
	for (int i = 0; i < 3; ++i)
		Nums[i].reserve(Size);

	int Input[3];
	int Before[WAY_END][3];
	int DP[WAY_END][3];
	for (int i = 0; i < Size; ++i)
	{
		CIN >> Input[0] >> Input[1] >> Input[2];
		for (int j = 0; j < 3; ++j)
			Nums[j].push_back(Input[j]);
	}

	for (int i = 0; i < 3; ++i)
	{
		DP[MIN][i] = DP[MAX][i] = Nums[i][0];
	}

 	for (int i = 1; i < Size; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			Before[MIN][j] = DP[MIN][j];
			Before[MAX][j] = DP[MAX][j];
		}
		DP[MIN][0] = Nums[0][i] + min(Before[MIN][0], Before[MIN][1]);
		DP[MAX][0] = Nums[0][i] + max(Before[MAX][0], Before[MAX][1]);

		DP[MIN][1] = Nums[1][i] + min(Before[MIN][1], min(Before[MIN][0], Before[MIN][2]));
		DP[MAX][1] = Nums[1][i] + max(Before[MAX][1], max(Before[MAX][0], Before[MAX][2]));

		DP[MIN][2] = Nums[2][i] + min(Before[MIN][1], Before[MIN][2]);
		DP[MAX][2] = Nums[2][i] + max(Before[MAX][1], Before[MAX][2]);

		cout << DP[MIN][0] << '\t' << DP[MIN][1] << '\t' << DP[MIN][2] << '\t' << '\t';
		cout << DP[MAX][0] << '\t' << DP[MAX][1] << '\t' << DP[MAX][2] << endl;
	}

	cout << max(max(DP[MAX][0], DP[MAX][1]), DP[MAX][2]) << ' '
		<< min(min(DP[MIN][0], DP[MIN][1]), DP[MIN][2]);
}