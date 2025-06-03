#include "pch.h"
#include "Header.h"
#include <vector>
#include <list>
#include <queue>

// Ʈ���� ������ ���ϴ°� ���ͽ�Ʈ�� �ι��̸� �����ٴ� ���!
// 1. ������ ������ ���� �� �� ���ϱ�
// 2. �ռ� ���� ������ ���� �� �� ���ϱ�

struct LINK
{
	int End;
	int Cost;
};

void BFS(int _Start, int NodeSize, vector<vector<LINK>>& _Nodes, int* Index, int* Cost)
{
	//�ڽ�Ʈ, �ε���
	queue<pair<int, int>> Destination;
	vector<int> History(NodeSize, 0);

	Destination.push({ 0, _Start });
	History[_Start] = 1;

	pair<int, int> Curr;
	while (!Destination.empty())
	{
		Curr = Destination.front();
		Destination.pop();
		for (LINK& link : _Nodes[Curr.second])
		{
			if (0 == History[link.End])
			{
				History[link.End] = link.Cost + Curr.first;
				Destination.push({ link.Cost + Curr.first, link.End });
				
			}
		}
	}
	
	*Cost = 0;
	for (int i = 0; i < NodeSize; ++i)
	{
		if (*Cost < History[i])
		{
			*Cost = History[i];
			*Index = i;
		}
	}
}

void Solve(ifstream* _pLoadStream)
{
	int NodeSize;
	CIN >> NodeSize;
	vector<vector<LINK>> Nodes(NodeSize, vector<LINK>());
	int Start;
	int End, Cost;
	for (int i = 0; i < NodeSize; ++i)
	{
		CIN >> Start;
		--Start;
		while (1)
		{
			CIN >> End;
			if (-1 == End)
				break;
			--End;
			CIN >> Cost;
			Nodes[Start].push_back({ End, Cost });
		}
	}

	int* NextIndex = new int(0);
	int * Src = new int(0);
	BFS(0, NodeSize, Nodes, NextIndex, Src);
	BFS(*NextIndex, NodeSize, Nodes, NextIndex, Src);
	cout << *Src;
}