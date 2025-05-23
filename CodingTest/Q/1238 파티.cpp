#include "pch.h"
#include "Header.h"
#include <vector>
#define MAXCOST 50000

/*
파티마을에서 가장 먼 마을 구하기
다익스트라로 풀면 훨씬 빠르긴 하다. 근데 ㅋㅋ;
*/
void Solve(ifstream* _pLoadStream)
{
	int TownSize, LinkSize, PartyTown;
	CIN >> TownSize >> LinkSize >> PartyTown;
	vector<vector<int>> Floid(TownSize, vector<int>(TownSize, MAXCOST));

	int Start, End;
	for (int i = 0; i < LinkSize; ++i)
	{
		CIN >> Start >> End;
		CIN >> Floid[Start - 1][End - 1];
	}

	for (int i = 0; i < TownSize; ++i)
		Floid[i][i] = 0;

	for (int Mid = 0; Mid < TownSize; ++Mid)
	{
		for (int Start = 0; Start < TownSize; ++Start)
		{
			for (int End = 0; End < TownSize; ++End)
			{
				Floid[Start][End] = min(Floid[Start][End], Floid[Start][Mid] + Floid[Mid][End]);
			}
		}
	}

	int Result{ 0 };
	for (int i = 0; i < TownSize; ++i)
	{
		Result = max(Result, Floid[PartyTown - 1][i] + Floid[i][PartyTown - 1]);
	}
	cout << Result;
}