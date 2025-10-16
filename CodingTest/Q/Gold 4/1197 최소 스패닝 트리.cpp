#include "pch.h"
#include "Header.h"
#include <vector>
#include <algorithm>

struct LINK
{
	int Start;
	int End;
	int Cost;
	bool operator < (LINK Temp)
	{
		return Cost < Temp.Cost;
	}
};

//최소 신장 트리 만들기, 프림 말고 크루스칼 알고리즘 써보자
//코스트는 음수일 수도 있다.
vector<int> Union;

int UnionFind(int NodeIndex)
{
	int Curr = NodeIndex;
	while (!(Union[Curr] == Curr))
	{
		Curr = Union[Curr];
	}
	//경유하는 애들의 부모도 갱신해주면 좋겠다.
	Union[NodeIndex] = Curr;
	return Curr;
}

void Solve(ifstream* _pLoadStream)
{
	int NodeSize;
	int LinkSize;
	CIN >> NodeSize >> LinkSize;
	Union.resize(NodeSize);
	vector<LINK> Links(LinkSize);

	for (int i = 0; i < NodeSize; ++i)
	{
		Union[i] = i;
	}

	for (int i = 0; i < LinkSize; ++i)
	{
		CIN >> Links[i].Start >> Links[i].End >> Links[i].Cost;
		--Links[i].Start;
		--Links[i].End;
	}
	sort(Links.begin(), Links.end());
	

	int Result{ 0 };
	int StartParent;
	int EndParent;
	for (LINK& link : Links)
	{
		StartParent = UnionFind(link.Start);
		EndParent = UnionFind(link.End);
		if (StartParent == EndParent)
			continue;

		Union[EndParent] = StartParent;
		Union[link.End] = Union[link.Start]; // 이건 굳이 필요없다.

		Result += link.Cost;
	}

	cout << Result;
}