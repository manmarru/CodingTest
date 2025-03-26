#include "pch.h"
#include "Header.h"
#include <stack>
#include <queue>

void Solve(ifstream* _pLoadStream)
{
	/*
	1���� n������ ���� ���ؿ� push �ϴµ�
	���߿� ���ϴ� ���ڸ� pop �ؼ� ���� ���ڵ��
	�־��� ������ ���� �� �ִ���
	� ������ �����ؾߵǴ���

	�ߺ����� ����
	*/
	int iSize{};
	int iInput{};
	queue<int> stlInput;
	queue<char> szResult;
	
	CIN >> iSize;
	for (int i = 0; i < iSize; i++)
	{
		CIN >> iInput;
		stlInput.push(iInput);
	}

	stack<int> stlCount;
	int iCount{0};
	while (1)
	{
		if (stlCount.empty() || (stlCount.top() < stlInput.front()))
		{
			if (++iCount > stlInput.front())
			{
				cout << "NO";
				return;
			}
			stlCount.push(iCount);
			szResult.push('+');
			continue;
		}
		else if (stlCount.top() > stlInput.front())
		{
			szResult.push('-');
			stlCount.pop();
		}
		else if(stlCount.top() == stlInput.front())
		{
			szResult.push('-');
			stlCount.pop();
			stlInput.pop();
		}

		if (stlInput.empty())
			break;
	}

	while (!szResult.empty())
	{
		cout << szResult.front() << '\n';
		szResult.pop();
	}


}