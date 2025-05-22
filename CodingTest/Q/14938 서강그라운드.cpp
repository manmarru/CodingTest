#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>
#define INF 10000000
void Solve(ifstream* _pLoadStream)
{
	/*
	플로이드 워셜임
	EZwwwww
	*/

	int MapSize, SearchRange, LineSize;
	CIN >> MapSize >> SearchRange >> LineSize;
	
	vector<int> Items(MapSize);
	vector<vector<int>> Cost(MapSize, vector<int>(MapSize, INF));

	for (int i = 0; i < MapSize; ++i)
	{
		Cost[i][i] = 0;
		CIN >> Items[i];
	}
	int Input[2];
	for (int i = 0; i < LineSize; ++i)
	{
		CIN >> Input[0] >> Input[1];
		--Input[0];
		--Input[1];
		CIN >> Cost[Input[0]][Input[1]];
		Cost[Input[1]][Input[0]] = Cost[Input[0]][Input[1]];
	}

	for (int Mid = 0; Mid < MapSize; ++Mid)
	{
		for (int Start = 0; Start < MapSize; ++Start)
		{
			for (int End = 0; End < MapSize; ++End)
			{
				Cost[Start][End] = min(Cost[Start][End], Cost[Start][Mid] + Cost[Mid][End]);
			}
		}
	}
	
	int MaxCost{ 0 };
	int CurrCost{ 0 };
	for (int Start = 0; Start < MapSize; ++Start)
	{
		CurrCost = 0;
		for (int End = 0; End < MapSize; ++End)
		{
			if (Cost[Start][End] <= SearchRange)
			{
 				CurrCost += Items[End];
			}
		}
		MaxCost = max(MaxCost, CurrCost);
	}
	cout << MaxCost;
}