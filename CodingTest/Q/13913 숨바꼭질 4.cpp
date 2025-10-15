#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>
#include <stack>

/*
https://www.acmicpc.net/problem/13913
이지하네요
100001 이 아니라 100000 으로 공간 할당해서 실수했지만

개인적으로 next와 destination을 swap 하는 방식 그대로 써도 될거같음
stl에서 swap을 포인터만 교환하는 방식으로 오버로딩 되어 있다.

이거 마음에 안 들면 queue에 넣는 값을 struct나 pair같은걸로 해서
데이터에 횟수를 포함시키면 된다.
*/

vector<int> History(100001, -1);
int Subin, Sist;

void Chase()
{
	stack<int> Road;
	int i = Sist;
	while (i != Subin)
	{
		Road.push(i);
		i = History[i];
	}
	cout << Road.size() << '\n';
	cout << Subin << ' ';
	while (!Road.empty())
	{
		cout << Road.top() << ' ';
		Road.pop();
	}
}

void Solve(ifstream* _pLoadStream)
{
	CIN >> Subin >> Sist;
	if (Subin == Sist)
	{
		Chase();
		return;
	}

	queue<int> Destination;
	queue<int> Next;
	Next.push(Subin);
	History[Subin] = Subin;
	int Curr;
	while (!Next.empty())
	{
		swap(Next, Destination);
		while (!Destination.empty())
		{
			Curr = Destination.front();
			Destination.pop();
			if (Curr == Sist)
			{
				Chase();
				return;
			}

			if (Curr > 0 && -1 == History[Curr - 1])
			{
				History[Curr - 1] = Curr;
				Next.push(Curr - 1);
			}
			if (Curr < 100000 && -1 == History[Curr + 1])
			{
				History[Curr + 1] = Curr;
				Next.push(Curr + 1);
			}
			if (Curr <= 50000 && -1 == History[Curr * 2])
			{
				History[Curr * 2] = Curr;
				Next.push(Curr * 2);
			}
		}
	}
	Chase();
}