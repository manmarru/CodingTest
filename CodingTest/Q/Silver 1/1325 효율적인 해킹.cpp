#include "pch.h"
#include "Header.h"
#include <vector>
#include <algorithm>

/*
https://www.acmicpc.net/problem/1325
DP를 쓰면 더 빠르다고는 하는데 내꺼보다 빠른 예시가 없다.
DFS에 DP 넣어봤는데 결국 중복방문 안 하려면 history 똑같이 써야되서 안 빨라짐
*/


vector<vector<int>> Nodes;
vector<char> History;
int DFS(int Start)
{
	int Result = 1;
	for (int i : Nodes[Start])
	{
		if (History[i] == 1)
			continue;
		History[i] = 1;
		Result += DFS(i);
	}
	return Result;
}


void Solve(ifstream* _pLoadStream)
{
	int Linksize, Nodesize;
	CIN >> Nodesize >> Linksize;

	Nodes.resize(Nodesize + 1);
	History.resize(Nodesize + 1);
	int Start, End;
	for (int i = 0; i < Linksize; ++i)
	{
		CIN >> End >> Start;
		Nodes[Start].push_back(End);
	}

	vector<int> Result;
	int Max = 0;
	for (int i = 1; i <= Nodesize; ++i)
	{
		fill(History.begin(), History.end(), 0);
		History[i] = 1;
		int Temp = DFS(i);
		if (Temp == Max)
			Result.push_back(i);
		else if (Temp > Max)
		{
			Result = vector<int>(1, i);
			Max = Temp;
		}
	}
	sort(Result.begin(), Result.end());
	for (int i : Result)
		cout << i << ' ';
}