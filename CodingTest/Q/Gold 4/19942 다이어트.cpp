#include "pch.h"
#include "Header.h"
#include <vector>
#include <array>
#define COST 4

/*
https://www.acmicpc.net/problem/19942
ㅋㅋ 인덱스 잘못 비교해서 틀리고있었네
그리고 답이 없으면 -1 해야 됐다.
*/

int Size;
int Floor[4];
int MinCost{ 9999999 };
vector<int> Selected;
int SelectedFood[5]{0, 0, 0, 0, 0};
vector<array<int, 5>> Foods;
vector<int > Result;

void DFS(int CurrIndex)
{
	if (SelectedFood[COST] >= MinCost)
		return;

	if (SelectedFood[0] >= Floor[0] && SelectedFood[1] >= Floor[1] 
		&& SelectedFood[2] >= Floor[2] && SelectedFood[3] >= Floor[3])
	{
		MinCost = SelectedFood[COST];
		Result = Selected;
		return;
	}

	for (; CurrIndex < Size; ++CurrIndex)
	{
		for (int j = 0; j < 5; ++j)
		{
			SelectedFood[j] += Foods[CurrIndex][j];
		}
		Selected.push_back(CurrIndex);
		DFS(CurrIndex + 1);
		Selected.pop_back();
		for (int j = 0; j < 5; ++j)
		{
			SelectedFood[j] -= Foods[CurrIndex][j];
		}
	}
	return;
}

void Solve(ifstream* _pLoadStream)
{
	CIN >> Size;
	CIN >> Floor[0] >> Floor[1] >> Floor[2] >> Floor[3];
	Foods.resize(Size);

	for (int i = 0; i < Size; ++i)
	{
		CIN >> Foods[i][0] >> Foods[i][1] >> Foods[i][2] >> Foods[i][3] >> Foods[i][4];
	}

	DFS(0);

	if (MinCost == 9999999)
		MinCost = -1;
	cout << MinCost << '\n';
	for (int i : Result)
		cout << i + 1 << ' ';
}