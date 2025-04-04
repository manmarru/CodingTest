#include "pch.h"
#include "Header.h"
#include <queue>
#include <vector>

void Solve(ifstream* _pLoadStream)
{
	/*
	부분합인지 판별하기
	이거 생각해보니까 작은순서대로 계산하니까
	정렬이 필요없어서 우선순위 큐도 필요없다.
	그냥 잘 넣으면 되는거였음 ㅋㅋ
	*/
	int Input;
	int Curr;
	int Result;
	priority_queue<int, vector<int>, greater<int>> Divide;

	while (1)
	{
		priority_queue<int, vector<int>, greater<int>> Temp;
		Temp.swap(Divide);
		CIN >> Input;
		if (-1 == Input)
			return;
		Result = 0;
		Curr = 1;

		while (Input != Curr)
		{
			if (Input % Curr == 0)
			{
				Divide.push(Curr);
				Result += Curr;
			}
			++Curr;
		}
		if (Result != Input)
		{
			cout << Input << " is NOT perfect.\n";
			continue;
		}

		cout << Input << " = " << Divide.top();
		Divide.pop();

		while (!Divide.empty())
		{
			Curr = Divide.top();
			Divide.pop();
			cout << " + " << Curr;
		}
		cout << '\n';
	}
}