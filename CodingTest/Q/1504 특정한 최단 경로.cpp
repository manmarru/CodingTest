#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>

struct NODE
{
	vector<pair<int, int>> links; // 코스트, 연결지
	int Cost = 999999999; // 갱신하는 최단거리 누적코스트
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
	1에서 시작하고 N까지 가며,
	특정한 두 점을 지나는 최단 경로의 코스트 구하기

	시작점에서 지정 점으로 가는 코스트 + 지정 점에서 다음 지정점으로 가는 코스트
	 + 그 점에서 목적지로 가는 코스트
	
	######우선 순위 큐를 쓰면 쓸모없는 중복 방문을 안하게 해 준다.#####
	*/
	int Vertexsize, Linksize;
	CIN >> Vertexsize >> Linksize;
	Nodes.resize(Vertexsize + 1); // 0번 없다잉
	int before, after, cost;
	for (int i = 0; i < Linksize; ++i)
	{
		CIN >> before >> after >> cost;
		Nodes[before].links.push_back({ cost, after });
		Nodes[after].links.push_back({ cost, before });
	}
	int Via[2]; // 경유지
	CIN >> Via[0] >> Via[1];

	/*
	before -> 0 + 1 -> after vs before -> 1 + 0 + after
	다 구해본 다음 코스트가 더 낮은 경로를 선택
	어차피 0 -> 1 (또는 반대로)는 고정이니깐!
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