#include "pch.h"
#include "Header.h"
#include <stack>
#include <string>

/*
���� ǥ���
- ���ڴ� �ٷ� ���
- �����ڴ� ���ǿ� ���� ���ÿ� �ø�
	- �� ���� �켱���� �����ڰ� ���� �� ������ ������ �ϳ��� ����.
- ���� ��ȣ�� �׳� ���ÿ� �߰�
- �ݴ� ��ȣ�� ���� ��ȣ�� ���ö����� ������ pop�Ѵ�. ��ȣ�� ������.
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
	
	//���������� ������ ����
	while (!Oper.empty())
	{
		cout << Oper.top();
		Oper.pop();
	}
}