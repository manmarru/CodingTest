#include "pch.h"
#include "Header.h"
#include <vector>

/*
https://www.acmicpc.net/problem/12869
DFS로 하면 안된다. 같은 체력 상황에 대해 가능한 가짓수가 너무 많다.

*/

const int Att[3]{ 9, 3, 1 };
vector<vector<int>> Mem;

void Solve(ifstream* _pLoadStream)
{
	int Size;
	CIN >> Size;
	Mem.resize(Size, vector<int>(Size));

	for (int i = 0; i < Size; ++i)
	{
		
	}


}