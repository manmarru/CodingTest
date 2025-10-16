#include "pch.h"
#include "Header.h"
#include <vector>
#include <list>

enum STEP { NONE, RESERVING, SKIP, HISTORY_END };

/*
+- 1
* 2
로 이동해서 Me에서 You까지 이동하는 최단 연산횟수를 출력하고
최단 연산횟수로 도착할 수 있는 경우의 수 출력하기

0 +1 +1 = 2
0 +1 *2 = 2
같은 횟수로 같은 칸에 도달하는 방법이 한가지가 아니다.

https://www.acmicpc.net/source/94498999
이거 걍 동일 타이밍에서는 히스토리 체크 안하고 계속 추가해버리면 풀리는데?? 뭐임????
*/
void Solve(ifstream* _pLoadStream)
{
	
	int Me, Target;
	CIN >> Me >> Target;
	if (Target <= Me)
	{
		cout << Me - Target << '\n' << 1;
		return;
	}
	int answer{ 0 };
	vector<STEP> History(100001, NONE);
	vector<int> Cnt(100001, 0);
	list<int> CurrDestination;
	list<int> NextDestination;
	CurrDestination.push_back(Me);
	History[Me] = SKIP;
	Cnt[Me] = 1;

	while (!History[Target])
	{
		answer += 1;
		while (!CurrDestination.empty())
		{
			int Curr = CurrDestination.front();
			CurrDestination.pop_front();
			if (Curr + 1 < 100001 && (History[Curr + 1] != SKIP))
			{
				Cnt[Curr + 1] += Cnt[Curr];
				if (NONE == History[Curr + 1])
				{
					NextDestination.push_back(Curr + 1);
					History[Curr + 1] = RESERVING;
				}
			}
			if (Curr - 1 >= 0 && (History[Curr - 1] != SKIP))
			{
				Cnt[Curr - 1] += Cnt[Curr];
				if (NONE == History[Curr - 1])
				{
					NextDestination.push_back(Curr - 1);
					History[Curr - 1] = RESERVING;
				}
			}
			if (Curr * 2 < 100001 && (History[Curr * 2] != SKIP))
			{
				Cnt[Curr * 2] += Cnt[Curr];
				if (NONE == History[Curr * 2])
				{
					NextDestination.push_back(Curr * 2);
					History[Curr * 2] = RESERVING;
				}
			}
		}
		for (int& i : NextDestination)
			History[i] = SKIP;

		swap(CurrDestination, NextDestination);
	}
	cout << answer << '\n' << Cnt[Target];
}