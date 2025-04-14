#include "pch.h"
#include "Header.h"
#include <queue>
#include <vector>


vector<int> Cost(100001, 100000);
struct Comp
{
	bool operator()(int Temp, int Src) const
	{
		return Cost[Temp] > Cost[Src];
	}
};

void Solve(ifstream* _pLoadStream)
{
	/*
	1�� �� ��ĭ �ȱ� or �ٷ� *2 �����̵�
	���� ���� �ð� ���ϱ�
	�����丮���� �߰��ϸ� �ز� �������� �Ѵ�.
	https://www.acmicpc.net/source/93093062 ��¥ �ز� ��������.
	*/

	int Me, You;

	CIN >> Me >> You;

	priority_queue<int, vector<int>, Comp> Destination;
	Cost[Me] = 0;
	Destination.push(Me);

	int Curr;
	while (!Destination.empty())
	{
		Curr = Destination.top();
		Destination.pop();
		if (Curr == You)
			break;

		if (Curr + 1 <= 100000 && Cost[Curr + 1] > Cost[Curr] + 1)
		{
			Destination.push(Curr + 1);
			Cost[Curr + 1] = Cost[Curr] + 1;
		}
		if (Curr - 1 >= 0 && Cost[Curr - 1] > Cost[Curr] + 1)
		{
			Destination.push(Curr - 1);
			Cost[Curr - 1] = Cost[Curr] + 1;
		}
		if (Curr * 2 <= 100000 && Cost[Curr * 2] > Cost[Curr])
		{
			Destination.push(Curr * 2);
			Cost[Curr * 2] = Cost[Curr];
		}
	}

	cout << Cost[You];
}