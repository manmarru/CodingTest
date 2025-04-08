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
	- 2 곱하기
	- 1을 수의 가장 오른쪽에 추가하기
	이 두가지로 A를 B로 만드는 데 필요한 연산의 최솟값 구하기
	BFS 말고 B에서 A로 역산하는 방법이 있는데
	짝수면 2로 나누기
	홀수면 (2로 못나누니까) 우측의 1 빼기
	이렇게 A로 가는지 확인하는 방법이 있다.
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