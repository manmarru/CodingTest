//파일명에는 ? 를 못넣음~ 원제는 팰린드롬? 이다.
#include "pch.h"
#include "Header.h"
#include <vector>

void Solve(ifstream* _pLoadStream)
{
	int Case;
	CIN >> Case;
	vector<int> Nums(Case);
	vector<vector<bool>> DP(Case, vector<bool>(Case, false));

	for (int i = 0; i < Case; ++i)
	{
		CIN >> Nums[i];
		DP[i][i] = true;
	}

	int Start, End;
	for (int i = 0; i < Case; ++i)
	{
		Start = i - 1;
		End = i + 1;
		while (Start >= 0 && End < Case && Nums[Start] == Nums[End])
		{
			DP[Start][End] = true;
			--Start;
			++End;
		}

		Start = i;
		End = i + 1;
		while (Start >= 0 && End < Case && Nums[Start] == Nums[End])
		{
			DP[Start][End] = true;
			--Start;
			++End;
		}
	}

	CIN >> Case;
	for (int i = 0; i < Case; ++i)
	{
		CIN >> Start >> End;
		cout << (DP[--Start][--End] ? 1 : 0) << '\n';
	}
}