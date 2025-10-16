#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>
#define MAXSIZE 999999999

struct NODE
{
	vector<pair<int, int>> Links; // �ڽ�Ʈ, ������
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
�ܺ� ���̴� �ڲ� ����� ���°� �� �����ٰ� �Ѵ�.
*/

void Solve(ifstream* _pLoadStream)
{
	/*
	����׷����� �־�����
	���������� �ٸ� ��� ���������� �ִ� �Ÿ��� ���ϴ� ���α׷� �ۼ�

	�ܺ� �޸𸮿� �����ϴ� �� ������ ������!
	*/


	int VertexSize, LinkSize;
	int Start;
	CIN >> VertexSize >> LinkSize >> Start;
	vector<NODE> Nodes(VertexSize + 1); // 0������.
	Nodes[Start].Cost = 0;

	int S, E, C;
	for (int i = 0; i < LinkSize; ++i)
	{
		CIN >> S >> E >> C;
		Nodes[S].Links.push_back({ C, E });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Destination;
	Destination.push({ 0, Start });
	pair<int, int> Curr; // �ڽ�Ʈ, ������
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