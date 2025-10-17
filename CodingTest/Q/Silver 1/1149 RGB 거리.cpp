#include "pch.h"
#include "Header.h"
#include <vector>
#include <array>

enum COLOR { R, G, B, COLOR_END };

void Solve(ifstream* _pLoadStream)
{
	/*
	각 집을 집을 R G B 로 색칠했을 때의 코스트가 나옴
	색이 연속되지 않게 가장 싼 비용으로 모든 집을 색칠하기

	DP같긴 하네 예전에 계단 오르기 문제처럼 하는듯
	*/
	vector<int> DP[COLOR_END];
	int Size;
	CIN >> Size;
	for (int i = 0; i < COLOR_END; ++i)
		DP[i].reserve(Size);
	for (int i = 0; i < Size; ++i)
	{
		DP[R].emplace_back();
		DP[G].emplace_back();
		DP[B].emplace_back();
		CIN >> DP[R][i] >> DP[G][i] >> DP[B][i];
	}

	for (int i = 1; i < Size; ++i)
	{
		DP[R][i] += min(DP[G][i - 1], DP[B][i - 1]);
		DP[G][i] += min(DP[R][i - 1], DP[B][i - 1]);
		DP[B][i] += min(DP[R][i - 1], DP[G][i - 1]);
	}
	cout << min(min(DP[R].back(), DP[G].back()), DP[B].back());
}