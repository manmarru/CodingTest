#include "pch.h"
#include "Header.h"
#include <stack>
#include <string>

/*
후위 표기식
- 숫자는 바로 출력
- 연산자는 조건에 따라 스택에 올림
	- 더 낮은 우선순위 연산자가 위에 올 때까지 스택을 하나씩 비운다.
- 여는 괄호는 그냥 스택에 추가
- 닫는 괄호는 여는 괄호가 나올때까지 스택을 pop한다. 괄호는 버린다.
*/

void Solve(ifstream* _pLoadStream)
{
	stack<char> Oper;
	string Input;
	CIN >> Input;

	for (char Temp : Input)
	{
		switch (Temp)
		{
		case '(':
			Oper.push(Temp);
			break;
		case ')':
			while (Oper.top() != '(')
			{
				cout << Oper.top();
				Oper.pop();
			}
			Oper.pop();
			break;
		case '+': case '-':
			while (!Oper.empty() && Oper.top() != '(')
			{
				cout << Oper.top();
				Oper.pop();
			}
			Oper.push(Temp);
			break;
		case '*': case '/':
			while (!Oper.empty() && (Oper.top() == '*' || Oper.top() == '/'))
			{
				cout << Oper.top();
				Oper.pop();
			}
			Oper.push(Temp);
			break;
		default:
			cout << Temp;
			break;
		}
	}
	
	//마지막으로 남은거 비우기
	while (!Oper.empty())
	{
		cout << Oper.top();
		Oper.pop();
	}
}