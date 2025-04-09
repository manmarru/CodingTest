#include "pch.h"
#include "Header.h"
#include <vector>

void Solve(ifstream* _pLoadStream)
{
	/*
	�ﰢ���� Ÿ�� �������鼭 ���Ҹ� ���� �� ���� ū ���� �����	
	*/


	int Size;
	vector<vector<int>> Triangle;
	CIN >> Size;
	Triangle.reserve(Size + 1);
	for (int i = 0; i <= Size; ++i)
	{
		Triangle.emplace_back();
		Triangle[i].reserve(i);
		for (int j = 0; j < i; ++j)
		{
			Triangle[i].emplace_back();
			CIN >> Triangle[i].back();
		}
	}
	
 	for (int i = Size; i > 1; --i)
	{
		for (int j = 0; j < i - 1; ++j)
		{
			Triangle[i - 1][j] += max(Triangle[i][j], Triangle[i][j + 1]);
		}
	}
	cout << Triangle[1][0];
}