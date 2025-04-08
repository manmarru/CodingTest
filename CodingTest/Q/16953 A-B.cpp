#include "pch.h"
#include "Header.h"
#include <map>
#include <queue>

long long int Rightpush(int Num)
{
	return Num * 10 + 1;
}

void Solve(ifstream* _pLoadStream)
{
	/*
	- 2 ���ϱ�
	- 1�� ���� ���� �����ʿ� �߰��ϱ�
	�� �ΰ����� A�� B�� ����� �� �ʿ��� ������ �ּڰ� ���ϱ�
	BFS ���� B���� A�� �����ϴ� ����� �ִµ�
	¦���� 2�� ������
	Ȧ���� (2�� �������ϱ�) ������ 1 ����
	�̷��� A�� ������ Ȯ���ϴ� ����� �ִ�.
	https://www.acmicpc.net/source/92799540
	*/
	map<long long int, int> history;
	queue<long long int> Destination;

	int A, B;
	CIN >> A >> B;
	history[A] = 1;
	if (A > B)
	{
		cout << -1;
		return;
	}
	else if (A == B)
	{
		cout << 1;
		return;
	}

	Destination.push(A);
	int Curr;
	while (!Destination.empty())
	{
		Curr = Destination.front();
		Destination.pop();
		if (Curr > B)
		{
			continue;
		}
		else if (Curr == B)
		{
			break;
		}
		else
		{
			long long int Next = Rightpush(Curr);
			if (!history[Curr * 2])
			{
				Destination.push(Curr * 2);
				history[Curr * 2] = history[Curr] + 1;
			}
			if (!history[Next])
			{
				Destination.push(Next);
				history[Next] = history[Curr] + 1;
			}
		}
	}
	if (history[B] == 0)
		cout << -1;
	else
		cout << history[B];

}