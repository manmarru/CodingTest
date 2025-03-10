#include "pch.h"
#include "Header.h"
#include <queue>
#include <string>

int D(int _Input)
{
	return (_Input * 2) % 10000;
}
int S(int _Input)
{
	return _Input == 0 ? 9999 : _Input - 1;
}
int L(int _Input)
{
	return (_Input % 1000) * 10 +_Input / 1000;
}
int R(int _Input)
{
	return _Input / 10 + (_Input % 10) * 1000;
}

bool History[10001];
void Solve(ifstream* pLoadStream)
{
	/*
	명령에 따른 연산이 있다.
	D : * 2 % 10000
	S : -1 (0 - 1 = 9999)
	L : 각 자릿수를 왼편으로 회전시킴( abcd -> bcda)
	R : 오른편으로 회전 (abcd = dabc)

	이 연산을 통해 A를 B로 바꾸는 데 들어가는 최소 연산 횟수의 연산과정을 출력하기
	답이 여러개이면 중복정답
	*/
	int Input;
	int Target;
	int Size;
	CIN >> Size;
	int Curr{};
	int Next{};
	int(*Act[4])(int _Input);
	Act[0] = D;
	Act[1] = S;
	Act[2] = L;
	Act[3] = R;
	char Name[4]{ 'D', 'S', 'L', 'R' };
	bool End;
	for (int i = 0; i < Size; i++)
	{
		End = false;
		CIN >> Input >> Target;
		string Result{};
		fill(History, History + 10000, false);
		queue<pair<int, string>> Destination;
		Destination.push({ Input , "" });

		while (!Destination.empty())
		{
			Curr = Destination.front().first;
			for (int i = 0; i < 4; ++i)
			{
				Next = Act[i](Curr);
				if (Target == Next)
				{
					Result = Destination.front().second + Name[i];
					End = true;
					break;
				}
				else if (!History[Next])
				{
					History[Next] = true;
					Destination.push({ Next , Destination.front().second + Name[i] });
				}
			}
			if (End)
				break;
			Destination.pop();
		}
		for (char c : Result)
		{
			cout << c;
		}
		cout << '\n';
	}

}