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

void DFS(int Remain) // 몇개 더 골라야되는지
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
	N개의 자연수들 중
	중복 없이 M개를 선택해서 만드는 수열을
	오름차순으로 모두 구하기
	https://www.acmicpc.net/source/92745880 모범답안
	>> 같은 레벨에서 중복된 숫자를 안 건들기 위해 이전 값을 prew에 할당
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