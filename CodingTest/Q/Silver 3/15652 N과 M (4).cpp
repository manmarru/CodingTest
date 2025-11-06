#include "pch.h"
#include "Header.h"
#include <vector>

int MaxNum;
int Pick;
vector<int> Picked;
void BFS(int _Curr, int _Index)
{
	Picked[_Index] = _Curr;
	if (_Index == Pick)
	{
		for (int i = 1; i <= Pick; i++)
		{
			cout << Picked[i] << ' ';
		}
		cout << '\n';
		return;
	}
	else
	{
		for (int i = _Curr; i <= MaxNum; i++)
		{
			BFS(i, _Index + 1);
		}
	}
}

void Solve(ifstream* _pLoadStream)
{
	CIN >> MaxNum >> Pick;
	Picked.resize(MaxNum + 1);
	BFS(1, 0);
	
}