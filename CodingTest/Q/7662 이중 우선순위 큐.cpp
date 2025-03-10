#include "pch.h"
#include "Header.h"
#include <queue>
#include <map>

priority_queue<int, vector<int>, greater<int>> minQ;
priority_queue<int> maxQ;
map<int, int> Cnt;

void insert(int n)
{
	minQ.push(n);
	maxQ.push(n);
	++Cnt[n];
}
void Delete(int i)
{
	if (-1 == i && !minQ.empty())
	{
		Cnt[minQ.top()]--;
		minQ.pop();
	}
	else if (1 == i && !maxQ.empty())
	{
		Cnt[maxQ.top()]--;
		maxQ.pop();
	}
}

void ClearQ()
{
	while (!minQ.empty() && 0 == Cnt[minQ.top()])
		minQ.pop();
	while (!maxQ.empty() && 0 == Cnt[maxQ.top()])
		maxQ.pop();
}

void EmptyQ()
{
	priority_queue<int, vector<int>, greater<int>> Temp;
	priority_queue<int> Src;
	swap(minQ, Temp);
	swap(maxQ, Src);
}

void Solve(ifstream* pLoadStream)
{
	/*
	���� �켱���� ť ����
	D 1 : �ִ� ����
	D -1 : �ּڰ� ����
	D �ε� ��������� ����
	I n : n ����
	�����ִ� �ִ񰪰� �ּڰ� ����ϱ� (��������� EMPTY)

	multiset �� ���� ��û ���� Ǯ���� �Ѵ�. �׳� �ְ� ����⿡�� ���� �ǰŵ�..
	*/

	int Case;
	int Size;
	int iInput;
	char szInput;
	CIN >> Case;
	for (int i = 0; i < Case; i++)
	{
		EmptyQ();
		Cnt.clear();
		CIN >> Size;
		for (int j = 0; j < Size; j++)
		{
			CIN >> szInput >> iInput;
			if ('I' == szInput)
				insert(iInput);
			else if ('D' == szInput)
			{
				Delete(iInput);
				ClearQ();
			}
		}
		ClearQ();
		if (maxQ.empty() || minQ.empty())
			cout << "EMPTY\n";
		else
			cout << maxQ.top() << ' ' << minQ.top() << '\n';
	}
}