#include "pch.h"
#include "Header.h"
#include <stack>

void Solve(ifstream* _pLoadStream)
{
	/*
	K���� ���� �� �ִ� ���� ������ �ּڰ� ���ϱ�

	N K
	N����ŭ ������ ������ ���õ�
	*/
	int iSize{};
	int iTarget{};
	CIN >> iSize >> iTarget;
	stack<int> stlCoins;
	int iInput{};
	int iResult{ 0 };

	for (int i = 0; i < iSize; i++)
	{
		CIN >> iInput;
		stlCoins.push(iInput);
	}

	while (iTarget != 0)
	{

		iResult += (iTarget / stlCoins.top());
		iTarget = iTarget % stlCoins.top();
		stlCoins.pop();
	}
	cout << iResult;
}