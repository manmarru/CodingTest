#include "pch.h"
#include "Header.h"
#include <vector>
#include <list>

vector<int> Nodes; // 자식 갯수만 알면 되겠는데?
vector<list<int>> Link;
int BFS(int Parent, int CurNode)
{
	int Curr{ 1 };
	for (int i : Link[CurNode])
	{
		if (i == Parent)
			continue;
		Curr += BFS(CurNode, i);
	}

	Nodes[CurNode] = Curr;
	return Curr;
}

void Solve(ifstream* _pLoadStream)
{
	int NodeSize;
	CIN >> NodeSize;
	Nodes.resize(NodeSize);
	int RootNum;
	int CaseSize;
	CIN >> RootNum >> CaseSize;
	--RootNum;
	Link.resize(NodeSize);
	int Start, End;
	for (int i = 0; i < NodeSize - 1; ++i)
	{
		CIN >> Start >> End;
		Link[Start - 1].push_back(End - 1);
		Link[End - 1].push_back(Start - 1);
	}

	BFS(-1, RootNum);
	
	int Input;
	for (int i = 0; i < CaseSize; ++i)
	{
		CIN >> Input;
		cout << Nodes[Input - 1] << '\n';
	}
}