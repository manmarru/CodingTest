#include "pch.h"
#include "Header.h"
#include <vector>
#include <algorithm>

void Solve(ifstream* _pLoadStream)
{
	int Size;
	CIN >> Size;
	vector<pair<int, int>> Board(Size);

	for (int i = 0; i < Size; ++i)
	{
		CIN >> Board[i].first >> Board[i].second;
	}
	sort(Board.begin(), Board.end());

	int CurTime = 0;
	for (pair<int, int>& Temp : Board)
	{
		if (CurTime < Temp.first)
		{
			CurTime = Temp.first;
		}
		CurTime += Temp.second;
	}
	cout << CurTime;
}