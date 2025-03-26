#include "pch.h"
#include "Header.h"
#include <queue>

void Solve(ifstream* _pLoadStream)
{
	/*
	�ִ� ��
	1. ����
	2. �ִ밪 ��� + �� ����
	*/
	priority_queue<int> Temp;

	int iSize;
	CIN >> iSize;
	int iInput;
	for (int i = 0; i < iSize; i++)
	{
		CIN >> iInput;
		if (0 == iInput)
		{
			if (Temp.empty())
			{
				cout << 0 << '\n';
				continue;
			}
			cout << Temp.top() << '\n';
			Temp.pop();
		}
		else
		{
			Temp.push(iInput);
		}

	}
}