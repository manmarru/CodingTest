#include "pch.h"
#include "Header.h"
#include <stack>
#include <queue>

void Solve(ifstream* _pLoadStream)
{
	/*
	1부터 n까지의 수를 스텍에 push 하는데
	도중에 원하는 숫자를 pop 해서 꺼낸 숫자들로
	주어진 수열을 만들 수 있는지
	어떤 순서로 연산해야되는지

	중복원소 없음
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