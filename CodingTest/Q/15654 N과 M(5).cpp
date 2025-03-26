#include "pch.h"
#include "Header.h"
#include <vector>
#include <algorithm>

int Size;
int Pick;
vector<int> Nums;
vector<int> Picked;


/*
0���� �����ҰŴ� �׳� �� ������
*/
void DFS(int _NumIndex, int _PickIndex)
{
	Picked.push_back(_NumIndex);
	if (_PickIndex == Pick - 1)
	{
		for (int i = 1; i <= Pick; i++)
		{
			cout << Nums[Picked[i]] << ' ';
		}
		cout << '\n';
	}
	else
	{
		for (int i = 0; i <  Size; i++)
		{
			if (Picked.end() == find(Picked.begin(), Picked.end(), i))
			{
				DFS(i, _PickIndex + 1);
				Picked.pop_back();
			}
		}
	}
}

void Solve(ifstream* _pLoadStream)
{
	/*
	���õǴ� N���� �ڿ��� �� M ���� ���� �������� ������������ ����
	*/
	CIN >> Size >> Pick;
	Nums.resize(Size);
	Picked.reserve(Size + 1);
	vector<int> Picked;
	for (int i = 0; i < Size; i++)
	{
		CIN >> Nums[i];
	}
	sort(Nums.begin(), Nums.end());
	DFS(-1, -1);
}