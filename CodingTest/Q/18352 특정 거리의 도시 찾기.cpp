#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>
#define MAXCOST 100000000

struct NODE
{
	int Cost = MAXCOST;
	vector<int> Links;
};

void Solve(ifstream* _pLoadStream)
{
	int NodeSize, LinkSize;
	int Objective;
	int StartNode;
	CIN >> NodeSize >> LinkSize >> Objective >> StartNode;

	vector<NODE> Nodes(NodeSize + 1); // 1 based
	Nodes[StartNode].Cost = 0;
	int Start, End;
	for (int i = 0; i < LinkSize; ++i) // 단방향 노드임
	{
		CIN >> Start >> End;
		Nodes[Start].Links.push_back(End);
	}

	priority_queue<int> Destination;

	int Curr;
	int CurrCost;
	Destination.push(StartNode);
	while (!Destination.empty())
	{
		Curr = Destination.top();
		CurrCost = Nodes[Curr].Cost;
		Destination.pop();
		if (CurrCost == Objective)
			continue;
		for (int Next : Nodes[Curr].Links)
		{
			if (CurrCost + 1 >= Nodes[Next].Cost)
				continue;

			Nodes[Next].Cost = CurrCost + 1;
			Destination.push(Next);
		}
	}

	bool Result = false;
	for (int i = 1; i < NodeSize + 1; ++i)
	{
		if (Nodes[i].Cost == Objective)
		{
			cout << i << '\n';
			Result = true;
		}
	}
	if (false == Result)
		cout << -1;
}