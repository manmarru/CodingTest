#include "pch.h"
#include "Header.h"
#include <vector>

struct NODE
{
	int Cost;
	vector<int> Link;
	bool History = false;
};

vector<NODE> Nodes;

int BackTrack(int NodeIndex)
{
	if (Nodes[NodeIndex].History) // 이미 연산 기록이 있다면
	{
		return Nodes[NodeIndex].Cost;
	}

	int MaxTime{ 0 };

	for (int Prev : Nodes[NodeIndex].Link)
	{
		MaxTime = max(MaxTime, BackTrack(Prev));
	}

	Nodes[NodeIndex].Cost += MaxTime;
	Nodes[NodeIndex].History = true;

	return Nodes[NodeIndex].Cost;
}

void Solve(ifstream* _pLoadStream)
{
	int QuerySize;
	int NodeSize;
	int LinkSize;
	CIN >> QuerySize;

	int Start, End;
	for (int Query = 0; Query < QuerySize; ++Query)
	{
		CIN >> NodeSize >> LinkSize;
		vector<NODE> Temp;
		swap(Temp, Nodes);
		Nodes.resize(NodeSize);
		for (int i = 0; i < NodeSize; ++i)
		{
			CIN >> Nodes[i].Cost;
		}

		for (int i = 0; i < LinkSize; ++i)
		{
			CIN >> Start >> End;
			Nodes[--End].Link.push_back(--Start);
		}
		CIN >> End;

		cout << BackTrack(--End) << endl;
	}
}