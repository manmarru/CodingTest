#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>

struct NODE
{
	vector<pair<int, int>> links; // �ڽ�Ʈ, ������
	int Cost = 999999999; // �����ϴ� �ִܰŸ� �����ڽ�Ʈ
};
vector<NODE> Nodes;

void Search(int _Start, int _End)
{
	queue<int> Destination;
	int Curr;
	Destination.push(_Start);
	Nodes[_Start].Cost = 0;
	while (!Destination.empty())
	{
		Curr = Destination.front();
		Destination.pop();
		if (Curr == _End)
			continue;

		for (auto temp : Nodes[Curr].links)
		{
			if (Nodes[temp.second].Cost > temp.first + Nodes[Curr].Cost)
			{
				Destination.push(temp.second);
				Nodes[temp.second].Cost = temp.first + Nodes[Curr].Cost;
			}
		}
	}
}

void VertexClear()
{
	for (NODE& Temp : Nodes)
	{
		Temp.Cost = 99999999;
	}
}

void Solve(ifstream* _pLoadStream)
{
	/*
	1���� �����ϰ� N���� ����,
	Ư���� �� ���� ������ �ִ� ����� �ڽ�Ʈ ���ϱ�

	���������� ���� ������ ���� �ڽ�Ʈ + ���� ������ ���� ���������� ���� �ڽ�Ʈ
	 + �� ������ �������� ���� �ڽ�Ʈ
	
	######�켱 ���� ť�� ���� ������� �ߺ� �湮�� ���ϰ� �� �ش�.#####
	*/
	int Vertexsize, Linksize;
	CIN >> Vertexsize >> Linksize;
	Nodes.resize(Vertexsize + 1); // 0�� ������
	int before, after, cost;
	for (int i = 0; i < Linksize; ++i)
	{
		CIN >> before >> after >> cost;
		Nodes[before].links.push_back({ cost, after });
		Nodes[after].links.push_back({ cost, before });
	}
	int Via[2]; // ������
	CIN >> Via[0] >> Via[1];

	/*
	before -> 0 + 1 -> after vs before -> 1 + 0 + after
	�� ���غ� ���� �ڽ�Ʈ�� �� ���� ��θ� ����
	������ 0 -> 1 (�Ǵ� �ݴ��)�� �����̴ϱ�!
	*/
	int Result(0);
	int Temp;
	
	int Course[2][2];

	Search(1, Via[0]);
	Course[0][0] = Nodes[Via[0]].Cost;
	VertexClear();
	Search(1, Via[1]);
	Course[0][1] = Nodes[Via[1]].Cost;
	VertexClear();
	Search(Via[0], Vertexsize);
	Course[1][0] = Nodes[Vertexsize].Cost;
	VertexClear();
	Search(Via[1], Vertexsize);
	Course[1][1] = Nodes[Vertexsize].Cost;
	VertexClear();

	Search(Via[0], Via[1]);
	Result += Nodes[Via[1]].Cost;
	Result += min(Course[0][0] + Course[1][1], Course[0][1] + Course[1][0]);
	if (Result >= 99999999)
		cout << -1;
	else
		cout << Result;
	
}