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
	��Ʈ ���� Ʈ���� �־�����. �̶�, Ʈ���� ��Ʈ�� 1�̶�� ������ ��,
	�� ����� �θ� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
	2�� ������ n�������� �θ� ���
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