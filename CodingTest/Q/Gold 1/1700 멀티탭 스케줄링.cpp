#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>

/*
https://www.acmicpc.net/problem/1700
그리디의 기준을 잘 알아야 했다.
꼽힌 플러그들 중에
1. 다시 사용할 일이 없다.
2. 플러그들 중 재사용하는 시점이 가장 나중이다.
를 기준으로 뽑을 플러그를 선택해야 했다.

그리고 구현도 졸라 어려움, 그리디 기준을 빨리 떠올려서 코딩 빨리 시작해도 늦을 판임
*/
void Solve(ifstream* _pLoadStream)
{
	int Hole, Size;
	CIN >> Hole >> Size;
	vector<int> Holes(Hole, -1);
	queue<int> Schedule;
	vector<queue<int>> Seq(Size);
	vector<char> History(Size, false);

	int Input;
	for (int i = 0; i < Size; ++i)
	{
		CIN >> Input;
		--Input;
		Schedule.push(Input);
		Seq[Schedule.back()].push(i);
	}
	
	int Check = 0;
	while (!Schedule.empty() && Check < Hole)
	{
		int Curr = Schedule.front();
		Seq[Curr].pop();
		Schedule.pop();
		if (History[Curr] == true)
			continue;
		History[Curr] = true;
		Holes[Check] = Curr;
		++Check;
	}

	//다음 스케줄이 가장 늦은 기기가 꽃힌 플러그를 뺀다.
	int Result{ 0 };
	while(!Schedule.empty())
	{
		int Next = Schedule.front();
		Schedule.pop();

		if (History[Next] == true)
		{
			Seq[Next].pop();
			continue;
		}

		int FarIndex;
		int Far = 0;
		for (int i = 0; i < Hole; ++i)
		{
			if (Seq[Holes[i]].empty())
			{
				FarIndex = i;
				break;
			}

			if (Far < Seq[Holes[i]].front())
			{
				Far = Seq[Holes[i]].front();
				FarIndex = i;
			}
		}

		++Result;
		History[Holes[FarIndex]] = false;
		History[Next] = true;
		Holes[FarIndex] = Next;
		if (Seq[Next].empty())
			continue;
		Seq[Next].pop();
	}

	cout << Result;
}