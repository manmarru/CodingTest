#include "pch.h"
#include "Header.h"
#include <queue>
#include <vector>

void Solve(ifstream* _pLoadStream)
{
	/*
	�κ������� �Ǻ��ϱ�
	�̰� �����غ��ϱ� ����������� ����ϴϱ�
	������ �ʿ��� �켱���� ť�� �ʿ����.
	�׳� �� ������ �Ǵ°ſ��� ����
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