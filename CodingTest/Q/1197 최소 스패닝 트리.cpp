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

//�ּ� ���� Ʈ�� �����, ���� ���� ũ�罺Į �˰��� �Ẹ��
//�ڽ�Ʈ�� ������ ���� �ִ�.
vector<int> Union;

int UnionFind(int NodeIndex)
{
	int Curr = NodeIndex;
	while (!(Union[Curr] == Curr))
	{
		Curr = Union[Curr];
	}
	//�����ϴ� �ֵ��� �θ� �������ָ� ���ڴ�.
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
		Union[link.End] = Union[link.Start]; // �̰� ���� �ʿ����.

		Result += link.Cost;
	}

	cout << Result;
}