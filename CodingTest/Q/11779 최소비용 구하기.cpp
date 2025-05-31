#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>
#include <stack>
#define MAXCOST 100000000
/*
A 도시에서 B 도시로 가는 
최소 비용
이동 횟수
이동 경로 출력
비용은 [0, 100,000]
*/

struct LINK
{
	int End;
	int Cost;
};
struct NODE
{
	int Cost = MAXCOST;
	int Before;
	vector<LINK> Busses;
};

void Solve(ifstream* _pLoadStream)
{
	int VillageSize;
	int BusSize;
	int Start, End;
	CIN >> VillageSize >> BusSize;

	vector<NODE> Village(VillageSize + 1);
	LINK BusInput;

	for (int i = 0; i < BusSize; ++i)
	{
		CIN >> Start >> BusInput.End >> BusInput.Cost;
		Village[Start].Busses.push_back(BusInput);
	}

	CIN >> Start >> End;
	Village[Start].Cost = 0;
	queue<int> Destination;
	Destination.push(Start);
	vector<int> History(VillageSize + 1, false);
	while (!Destination.empty())
	{
		int Curr = Destination.front();
		Destination.pop();
		History[Curr] = false;

		for (LINK& Bus : Village[Curr].Busses)
		{
			if (Village[Curr].Cost + Bus.Cost < Village[Bus.End].Cost)
			{
				if (!History[Bus.End])
				{
					Destination.push({ Bus.End });
					History[Bus.End] = true;
				}
				Village[Bus.End].Cost = Village[Curr].Cost + Bus.Cost;
				Village[Bus.End].Before = Curr;
			}
		}
	}

	// 비용 횟수 경로 순으로 출력
	cout << Village[End].Cost << '\n';

	stack<int> RoadToEnd;
	while (End != Start)
	{
		RoadToEnd.push(End);
		End = Village[End].Before;
	}
	RoadToEnd.push(Start);
	cout << RoadToEnd.size() << '\n';

	while (!RoadToEnd.empty())
	{
		cout << RoadToEnd.top() << ' ';
		RoadToEnd.pop();
	}
}