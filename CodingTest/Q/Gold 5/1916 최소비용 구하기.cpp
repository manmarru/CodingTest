#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>
#define BIG 100000000

struct BUS
{
	int Start;
	int End;
	int Cost;
};

struct CITY
{
	vector<BUS> Bus;
	int Cost = BIG;
};

void Solve(ifstream* _pLoadStream)
{
	int Size, BusSize;
	CIN >> Size >> BusSize;
	vector<CITY> City(Size);
	for (int i = 0; i < BusSize; ++i)
	{
		BUS Temp;
		CIN >> Temp.Start >> Temp.End >> Temp.Cost;
		--Temp.Start; --Temp.End;
		City[Temp.Start].Bus.push_back(Temp);
	}

	int Start, End;
	CIN >> Start >> End;
	--Start; --End;
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> Destination;
	Destination.push({0, Start});
	City[Start].Cost = 0;
	while (!Destination.empty())
	{
		pair<int, int> Curr = Destination.top();
		Destination.pop();

		if (Curr.second == End)
			continue;

		if (City[Curr.second].Cost < Curr.first) // 큐에 넣은 뒤 코스트가 갱신되는 경우도 있으니까
			continue;

		for (BUS buss : City[Curr.second].Bus)
		{
			if (City[buss.End].Cost > City[Curr.second].Cost + buss.Cost)
			{
				City[buss.End].Cost = City[Curr.second].Cost + buss.Cost;
				Destination.push({ City[buss.End].Cost, buss.End });
			}
		}
	}
	cout << City[End].Cost;
}