#include "pch.h"
#include "Header.h"
#include <vector>
#include <list>

enum STEP { NONE, RESERVING, SKIP, HISTORY_END };

/*
+- 1
* 2
�� �̵��ؼ� Me���� You���� �̵��ϴ� �ִ� ����Ƚ���� ����ϰ�
�ִ� ����Ƚ���� ������ �� �ִ� ����� �� ����ϱ�

0 +1 +1 = 2
0 +1 *2 = 2
���� Ƚ���� ���� ĭ�� �����ϴ� ����� �Ѱ����� �ƴϴ�.

https://www.acmicpc.net/source/94498999
�̰� �� ���� Ÿ�ֿ̹����� �����丮 üũ ���ϰ� ��� �߰��ع����� Ǯ���µ�?? ����????
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