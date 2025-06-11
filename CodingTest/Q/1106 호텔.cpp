#include "pch.h"
#include "Header.h"
#include <vector>
#define	MAXCOST 200000000

// 0-1 knapsack ��� ��������
// DP ����.

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

	for (int i = 0; i < CitySize; ++i) // �� ���ø��� �ڽ�Ʈ, ��� ������ �Է�
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