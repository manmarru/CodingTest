#include "pch.h"
#include "Header.h"
#include <stack>
#include <string>

void Solve(ifstream* _pLoadStream)
{
	/*
	���ڿ��� VPS���� üũ
	*/

	int iInput{};
	string szInput{};
	stack<char> szBracket;
	bool skip = true;
	*_pLoadStream >> iInput;
	for (int i = 0; i < iInput; ++i)
	{
		*_pLoadStream >> szInput;
		for (char szWord : szInput)
		{
			if ('(' == szWord)
				szBracket.push(szWord);
			else if (')' == szWord)
			{
				if (szBracket.empty())
				{
					szBracket.push(szWord);
					break;
				}
				szBracket.pop();
			}
		}
		if (szBracket.empty())
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';

		stack<char> Temp;
		swap(szBracket, Temp);
	}


}