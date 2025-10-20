#include "pch.h"
#include "Header.h"
#include <vector>
#include <algorithm>

int Size;
int PickSize;

vector<int> Curr;
vector<int> Nums;

void DFS(int Remain, int PreIndex)
{
	if (0 == Remain)
	{
		for (int i : Curr)
			cout << i << ' ';
		cout << '\n';
		return;
	}

	for (int i = PreIndex; i < Size; ++i)
	{
		Curr.push_back(Nums[i]);
		DFS(Remain - 1, i);
		Curr.pop_back();
	}
}

void Solve(ifstream* _pLoadStream)
{
	/*
	N���� �ڿ��� �� M���� �� ���� ������������ ���
	�ߺ����� ���
	*/
	CIN >> Size >> PickSize;
	Nums.reserve(Size);
	for (int i = 0; i < Size; ++i)
	{
		Nums.emplace_back();
		CIN >> Nums.back();
	}
	sort(Nums.begin(), Nums.end(), less<int>());
	Nums.erase(unique(Nums.begin(), Nums.end()), Nums.end());
	Size = Nums.size();

	DFS(PickSize, 0);
}