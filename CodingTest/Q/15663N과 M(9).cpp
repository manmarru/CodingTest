#include "pch.h"
#include "Header.h"
#include <vector>
#include <algorithm>
#include <set>

int Size;
int PickSize;
vector<int> Nums;
vector<bool> Picked;
vector<int> Curr;

struct Compare
{
	bool operator() (const vector<int>& Temp, const vector<int>& Src) const
	{
		return Temp < Src;
	}
};
set<vector<int>, Compare> Result;

void DFS(int Remain) // � �� ���ߵǴ���
{
	if (Remain == 0)
	{
		Result.insert(Curr);
		return;
	}
	else
	{
		for (int i = 0; i < Size; ++i)
		{
			if (!Picked[i])
			{
				Picked[i] = true;
				Curr.push_back(Nums[i]);
				DFS(Remain - 1);
				Curr.pop_back();
				Picked[i] = false;
			}
		}
	}
}

void Solve(ifstream* _pLoadStream)
{
	/*
	N���� �ڿ����� ��
	�ߺ� ���� M���� �����ؼ� ����� ������
	������������ ��� ���ϱ�
	https://www.acmicpc.net/source/92745880 ������
	>> ���� �������� �ߺ��� ���ڸ� �� �ǵ�� ���� ���� ���� prew�� �Ҵ�
	*/
	CIN >> Size >> PickSize;
	Nums.resize(Size);
	Picked.resize(Size);
	for (int i = 0; i < Size; ++i)
		CIN >> Nums[i];
	sort(Nums.begin(), Nums.end());

	DFS(PickSize);


	for (auto& vec : Result)
	{
		for (int Temp : vec)
		{
			cout << Temp << ' ';
		}
		cout << '\n';
	}

}