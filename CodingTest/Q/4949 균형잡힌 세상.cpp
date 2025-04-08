#include "pch.h"
#include "Header.h"
#include <stack>

void Solve(ifstream* _pLoadStream)
{
	/*
	���ڿ����� ��ȣ () [] {} ���� �� �����ִ��� Ȯ���ϱ�
	�Է��� ������ .
	*/

	string szInput{};
	bool endline{ true };
	stack<char> stdBracket;
	while (true)
	{
		getline(*_pLoadStream, szInput);
		for (char szTemp : szInput)
		{

			if (szTemp == '.')
			{
				if (endline)
					return;
				cout << (stdBracket.empty() ? "yes" : "no") << endl;
				endline = true;
				stack<char> stdTemp;
				swap(stdBracket, stdTemp);
				continue;
			}

			endline = false;

			if (')' == szTemp)
			{
				if (stdBracket.empty())
					stdBracket.push(szTemp);
				else if (stdBracket.top() == '(')
					stdBracket.pop();
				else
					stdBracket.push(szTemp);
			}
			else if ('}' == szTemp)
			{
				if (stdBracket.empty())
					stdBracket.push(szTemp);
				else if (stdBracket.top() == '{')
					stdBracket.pop();
				else
					stdBracket.push(szTemp);
			}
			else if (']' == szTemp)
			{
				if (stdBracket.empty())
					stdBracket.push(szTemp);
				else if (stdBracket.top() == '[')
					stdBracket.pop();
				else
					stdBracket.push(szTemp);
			}
			else if ('(' == szTemp || '{' == szTemp || '[' == szTemp)
				stdBracket.push(szTemp);
		}
	}
}