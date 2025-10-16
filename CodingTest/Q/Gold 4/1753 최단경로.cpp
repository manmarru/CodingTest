#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>
#define MAXSIZE 999999999

struct NODE
{
	vector<pair<int, int>> Links; // 코스트, 목적지
	int Cost = MAXSIZE;
};

/*
struct Comp
{
	bool operator()(int Temp, int Src)
	{
		return Nodes[Temp].Cost < Nodes[Src].Cost;
	}
};
외부 데이더 자꾸 끌어다 쓰는게 좀 느리다고 한다.
*/

void Solve(ifstream* _pLoadStream)
{
	/*
	방향그래프가 주어지면
	시작점에서 다른 모든 정점으로의 최단 거리를 구하는 프로그램 작성

	외부 메모리에 접근하는 비교 연산은 느리다!
	*/


	int VertexSize, LinkSize;
	int Start;
	CIN >> VertexSize >> LinkSize >> Start;
	vector<NODE> Nodes(VertexSize + 1); // 0번없다.
	Nodes[Start].Cost = 0;

	int S, E, C;
	for (int i = 0; i < LinkSize; ++i)
	{
		CIN >> S >> E >> C;
		Nodes[S].Links.push_back({ C, E });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Destination;
	Destination.push({ 0, Start });
	pair<int, int> Curr; // 코스트, 목적지
	while (!Destination.empty())
	{
		Curr = Destination.top();
		Destination.pop();
		if (Curr.first > Nodes[Curr.second].Cost)
			continue;

		for (auto temp : Nodes[Curr.second].Links)
		{
			int Waycost = Nodes[Curr.second].Cost + temp.first;
			if (Nodes[temp.second].Cost > Waycost)
			{
				Destination.push({ Waycost, temp.second });
				Nodes[temp.second].Cost = Waycost;
			}
		}
	}

	++VertexSize;
	for (int i = 1; i < VertexSize; ++i)
	{
		if (Nodes[i].Cost == MAXSIZE)
			cout << "INF";
		else
		{
			cout << Nodes[i].Cost;
		}
		cout << '\n';
	}
}