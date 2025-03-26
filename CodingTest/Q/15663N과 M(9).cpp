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
_Index 번째 선택으로 _Pickindex번째 숫자를 골랐다.
*/

}

void Solve(ifstream* _pLoadStream)
{
	/*
	N개의 자연수들 중
	중복 없이 M개를 선택해서 만드는 수열을
	오름차순으로 모두 구하기
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