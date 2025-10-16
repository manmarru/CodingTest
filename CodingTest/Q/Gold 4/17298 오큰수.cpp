#include "pch.h"
#include "Header.h"
#include <stack>
#include <vector>

/*
https://www.acmicpc.net/problem/17298
���� �������� �� §�Ű���
�迭�� �ΰ� �ΰ� ���ÿ��� �ε����� �����ؾ� �ϴ°� �����ϱ�
��� ���Ҹ� ���ľ��ϴ��� �����ϱ� ��Ʊ� ������ �ε����� �־�δ°Ű�
������� ��ġ�°͵� �ƴ϶� �ϳ��� �迭�� ����ϱ� �����.
*/


void Solve(ifstream* _pLoadStream)
{
	int Inputsize;
	CIN >> Inputsize;

	vector<int> Input(Inputsize);
	vector<int> Result(Inputsize, -1);
	stack<int> Postpone;
	for (int i = 0; i < Inputsize; ++i)
	{
		CIN >> Input[i];
	}

	int Target;
	for (int i = 0; i < Inputsize; ++i)
	{
		Target = Input[i];
		while (!Postpone.empty() && Input[Postpone.top()] < Target)
		{
			Result[Postpone.top()] = Target;
			Postpone.pop();
		}
		Postpone.push(i);
	}

	for (int i : Result)
	{
		cout << i << ' ';
	}
}