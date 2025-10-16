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
	1초 뒤 한칸 걷기 or 바로 *2 순간이동
	가장 빠른 시간 구하기
	히스토리까지 추가하면 쬐끔 빨라지긴 한다.
	https://www.acmicpc.net/source/93093062 진짜 쬐끔 빨라진다.
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