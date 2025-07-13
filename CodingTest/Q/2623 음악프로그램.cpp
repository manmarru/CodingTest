#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>
#include <unordered_set>

// 사이클 체크하는 위상 정렬 알고리즘 중에 칸 알고리즘이라고 있는데 알아두면 좋을 것 같다.

vector<unordered_set<int>> People;
vector<bool> History;
queue<int> Result;
unordered_set<int> CycleCheck;

bool DFS(int _Curr)
{
	if (true == CycleCheck.count(_Curr))
		return false;

	if (History[_Curr])
		return true;

	History[_Curr] = true;
	CycleCheck.insert(_Curr);

	for (int i : People[_Curr])
	{
		if (!DFS(i))
			return false;
	}

	Result.push(_Curr);

	return true;
}

void Solve(ifstream* _pLoadStream)
{
	int PeopleSize;
	int Query;
	int InputSize;

	CIN >> PeopleSize >> Query;
	People.resize(PeopleSize + 1);
	History.resize(PeopleSize + 1);

	int Next;
	int Prev;
	for (int i = 0; i < Query; ++i)
	{
		CIN >> InputSize;
		CIN >> Next;
		for (int j = 1; j < InputSize; ++j)
		{
			CIN >> Prev;
			People[Prev].insert(Next);
			Next = Prev;
		}
	}
	

	for (int i = 1; i <= PeopleSize; ++i)
	{
		CycleCheck.clear();
		if (false == DFS(i))
		{
			cout << 0;
			return;
		}
	}

	while (!Result.empty())
	{
		cout << Result.front() << '\n';
		Result.pop();
	}
}