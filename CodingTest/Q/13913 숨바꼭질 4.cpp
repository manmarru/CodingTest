#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>
#include <stack>

/*
https://www.acmicpc.net/problem/13913
�����ϳ׿�
100001 �� �ƴ϶� 100000 ���� ���� �Ҵ��ؼ� �Ǽ�������

���������� next�� destination�� swap �ϴ� ��� �״�� �ᵵ �ɰŰ���
stl���� swap�� �����͸� ��ȯ�ϴ� ������� �����ε� �Ǿ� �ִ�.

�̰� ������ �� ��� queue�� �ִ� ���� struct�� pair�����ɷ� �ؼ�
�����Ϳ� Ƚ���� ���Խ�Ű�� �ȴ�.
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