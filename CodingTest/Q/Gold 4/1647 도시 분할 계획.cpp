#include "pch.h"
#include "Header.h"
#include <vector>
#include <algorithm>

#include <Windows.h>
//마을 두개로 분할하기
/*
분리된 마을 안의 집들은 연결되어 있어야 함.
분리된 마을간의 연결은 지움
각 마을을 최소 신장 트리로 만듦
*/

//최소신장 트리 만든담에 젤 비싼 길 하나 더 지우면 되는거 아님?
// 크루스칼이 일반적인 상황에선 프림보다 빠르다.

struct LINK
{
	int Start;
	int End;
	int Cost;

	bool operator < (LINK& Temp) const
	{
		return Cost < Temp.Cost;
	}
};

vector<int> Union;
int UnionFind(int _CurrIndex)
{
	int Curr{ _CurrIndex };
	while (!(Union[Curr] == Curr))
	{
		Curr = Union[Curr];
	}

	Union[_CurrIndex] = Curr;
	return Curr;
}

void Solve(ifstream* _pLoadStream)
{
	int HouseSize;
	int RoadSize;
	CIN >> HouseSize >> RoadSize;

	vector<LINK> Roads(RoadSize);
	Union.resize(HouseSize);
	for (int i = 0; i < RoadSize; ++i)
	{
		CIN >> Roads[i].Start >> Roads[i].End >> Roads[i].Cost;
		--Roads[i].Start;
		--Roads[i].End;
	}
	sort(Roads.begin(), Roads.end());

	for (int i = 0; i < HouseSize; ++i)
	{
		Union[i] = i;
	}

	int MaxSelect{ 0 };
	int Result{ 0 };
	for (LINK& Road : Roads)
	{
		int StartRoot{ UnionFind(Road.Start) };
		int EndRoot{ UnionFind(Road.End) };
		if (StartRoot == EndRoot)
			continue;
		Union[EndRoot] = StartRoot;
		Result += Road.Cost;
		MaxSelect = max(MaxSelect, Road.Cost);
	}

	Result -= MaxSelect;

	cout << Result;
}