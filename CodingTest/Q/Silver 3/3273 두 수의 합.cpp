#include "pch.h"
#include "Header.h"
#include <vector>
#include <algorithm>

/*
https://www.acmicpc.net/problem/3273
ez
정렬하고서 투포인터
*/

enum MEMO { DATA = 0, INDEX = 1 };
void Solve(ifstream* _pLoadStream)
{
	int Size;
	int Target;
	CIN >> Size;

	vector<pair<int ,int>> Nums(Size);
	for (int i = 0; i < Size; ++i)
	{
		CIN >> Nums[i].first;
		Nums[i].second = i + 1;
	}
	CIN >> Target;
	sort(Nums.begin(), Nums.end());

	int Left{ 0 }, Right{ Size - 1 };
	int Result{ 0 };
	while (Left < Right)
	{
		int Sum = Nums[Left].first + Nums[Right].first;
		if (Sum == Target)
		{
			++Result;
			++Left;
			--Right;
		}
		else if (Sum < Target)
			++Left;
		else
			--Right;
	}
	cout << Result;
}