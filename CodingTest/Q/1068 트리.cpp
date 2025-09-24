#include "pch.h"
#include "Header.h"
#include <vector>

/*
https://www.acmicpc.net/problem/1068
실수를 잔뜩 해서 많이 틀렸는데 가독성이 문제인거같기도 하고..
*/
struct NODE
{
	vector<int> Child;
};

vector<NODE> Nodes;
int Cut;
int DFS(int Curr)
{
	if (Curr == Cut)
		return 0;

	if (Nodes[Curr].Child.empty())
		return 1;

	if (Nodes[Curr].Child.size() == 1 && Nodes[Curr].Child[0] == Cut)
		return 1;

	int Answer = 0;
	for (int i : Nodes[Curr].Child)
	{
		Answer += DFS(i);
	}
	return Answer;
}

void Solve(ifstream* _pLoadStream)
{
	int Size;
	CIN >> Size;
	Nodes.resize(Size);
	
	int Input;
	int Root;
	for (int i = 0; i < Size; ++i)
	{
		CIN >> Input;
		if (Input == -1)
		{
			Root = i;
			continue;
		}
		Nodes[Input].Child.push_back(i);
	}
	CIN >> Cut;

	if (Cut == Root)
	{
		cout << 0;
		return;
	}

	cout << DFS(Root);
	return;
}