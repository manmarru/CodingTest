#include "pch.h"
#include "Header.h"
#include <vector>
#define	MAXCOST 200000000

// 0-1 knapsack 배냥 문제구만
// DP 쓰자.

struct CITY
{
	int Cost;
	int TakePeople;
};

void Solve(ifstream* _pLoadStream)
{
	int GoalPeople;
	int CitySize;
	CIN >> GoalPeople >> CitySize;

	vector<CITY> Cities(CitySize);
	vector<int> DP(GoalPeople + 1, MAXCOST);
	DP[0] = 0;

	for (int i = 0; i < CitySize; ++i) // 각 도시마다 코스트, 사람 순서로 입력
	{
		CIN >> Cities[i].Cost >> Cities[i].TakePeople;
	}


	int NextIndex;
	for (int i = 0; i < GoalPeople; ++i)
	{
		for (CITY Temp : Cities)
		{
			NextIndex = min(GoalPeople, i + Temp.TakePeople);
			DP[NextIndex] = min(DP[NextIndex], DP[i] + Temp.Cost);
		}
	}

	cout << DP[GoalPeople];
}