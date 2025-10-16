#include "pch.h"
#include "Header.h"
#include <stack>
#include <vector>

/*
https://www.acmicpc.net/problem/17298
ㅇㅋ 이정도면 잘 짠거같음
배열을 두개 두고 스택에는 인덱스를 저장해야 하는거 인지하기
어느 원소를 고쳐야하는지 지정하기 어렵기 때문에 인덱스를 넣어두는거고
순서대로 고치는것도 아니라서 하나의 배열을 사용하기 힘들다.
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