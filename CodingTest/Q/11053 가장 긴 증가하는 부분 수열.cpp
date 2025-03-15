#include "pch.h"
#include "Header.h"
#include <vector>

void Solve(ifstream* pLoadStream)
{
	/*
	�������� ���� �� �����ϴ� �κ� ������ ���ϱ�
	
	LTS, �̺�Ž�� �����ϱ�(�̺�Ž���� ����?)
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