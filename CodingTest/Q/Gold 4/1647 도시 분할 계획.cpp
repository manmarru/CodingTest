#include "pch.h"
#include "Header.h"
#include <vector>
#include <algorithm>

#include <Windows.h>
//���� �ΰ��� �����ϱ�
/*
�и��� ���� ���� ������ ����Ǿ� �־�� ��.
�и��� �������� ������ ����
�� ������ �ּ� ���� Ʈ���� ����
*/

//�ּҽ��� Ʈ�� ����㿡 �� ��� �� �ϳ� �� ����� �Ǵ°� �ƴ�?
// ũ�罺Į�� �Ϲ����� ��Ȳ���� �������� ������.

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