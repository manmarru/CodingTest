#include "pch.h"
#include "Header.h"
#include <vector>
#include <algorithm>

int Size;
int PickSize;
vector<int> Nums;
vector<bool> Picked;
vector<int> PickValue;

void DFS(int _PickIndex	, int _Index)
{
/*
_Index ��° �������� _Pickindex��° ���ڸ� �����.
*/

}

void Solve(ifstream* _pLoadStream)
{
	/*
	N���� �ڿ����� ��
	�ߺ� ���� M���� �����ؼ� ����� ������
	������������ ��� ���ϱ�
	*/

	CIN >> Size >> PickSize;
	Picked.resize(Size + 1, false);
	Nums.resize(Size + 1);
	PickValue.resize(PickSize + 1);
	for (int i = 1; i <= Size; i++)
	{
		CIN >> Nums[i];
	}
	Nums.erase(unique(Nums.begin(), Nums.end()), Nums.end());
	sort(Nums.begin(), Nums.end());




	DFS(0, 0);
}