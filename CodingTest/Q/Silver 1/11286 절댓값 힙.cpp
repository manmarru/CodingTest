#include "pch.h"
#include "Header.h"
#include <queue>

void Solve(ifstream* _pLoadStream)
{
	/*
	���� �� �����ϱ�
	1. 0�� �ƴ� ���� push
	2. 0�� �Է¹����� ������ ���� ���� ���� ����ϸ鼭 pop
		������ ���밪�� ���ؼ� �� ���� ���� pop

	https://www.acmicpc.net/source/90878200 ������ �������̵��� ���� ����� �ִ�.
	*/
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Temp;
	
	int iSize;
	CIN >> iSize;
	int iInput;
	pair<int, int> pairMin;
	int iDir;
	for (int i = 0; i < iSize; i++)
	{
		CIN >> iInput;
		if (0 == iInput)
		{
			if (Temp.empty())
				cout << 0 << '\n';
			else
			{
				pairMin = Temp.top();
				Temp.pop();
				cout << pairMin.first * pairMin.second << '\n';
			}
		}
		else
		{
			iDir = iInput < 0 ? -1 : 1;
			Temp.push({ iInput * iDir, iDir });
		}
	}
}