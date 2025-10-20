#include "pch.h"
#include "Header.h"
#include <vector>
#include <set>

vector<set<int>> Link;
vector<int> Parent;
void DFS(int _Curr)
{
	for (int i : Link[_Curr])
	{
		Parent[i] = _Curr;
		Link[i].erase(_Curr);
		DFS(i);
	}
}

void Solve(ifstream* _pLoadStream)
{
	/*
	루트 없는 트리가 주어진다. 이때, 트리의 루트를 1이라고 정했을 때,
	각 노드의 부모를 구하는 프로그램을 작성하시오.
	2번 노드부터 n번까지의 부모를 출력
	*/

	int Size;
	int Input[2];

	CIN >> Size;
	Link.resize(Size + 1);
	Parent.resize(Size + 1);
	for (int i = 1; i < Size; i++)
	{
		CIN >> Input[0] >> Input[1];
		Link[Input[0]].insert(Input[1]);
		Link[Input[1]].insert(Input[0]);
	}

	DFS(1);

	for (int i = 2; i <= Size; ++i)
		cout << Parent[i] << endl;
}