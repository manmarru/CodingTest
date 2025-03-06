#include "pch.h"
#include "Header.h"
#include <stack>
#include <cmath>
void Solve(ifstream* pLoadStream)
{
	/*
	��и����� ��� �ɰ���
	0	1
	2	3
	������ ��ȸ�ϴ�
	����� ����� �� x,y�� �� ��° ������ �Ǵ��� ����ϱ�
	*/

	int iSize;
	int iTargetX, iTargetY;
	CIN >> iSize >> iTargetY >> iTargetX; //����� 0,0�� ������

	stack<int> stlDir;
	int iIndex;
	int iCurrPow;
	int iResult{ 0 };
	while (iSize > 0)
	{
		int iCurrPow = pow(2, iSize - 1); //�ִ� 15�±��� �ԷµǴµ� �׷� 32000�ۿ� �ȵȴ�.
		if (iTargetX < iCurrPow && iTargetY < iCurrPow) // 2��и�
		{
			stlDir.push(0);
		}
		else if (iTargetX >= iCurrPow && iTargetY < iCurrPow) // 1��и�
		{
			stlDir.push(1);
		}
		else if (iTargetX < iCurrPow && iTargetY >= iCurrPow) // 3��и�
		{
			stlDir.push(2);
		}
		else if (iTargetX >= iCurrPow && iTargetY >= iCurrPow) // 4��и�
		{
			stlDir.push(3);
		}

		iTargetX %= iCurrPow;
		iTargetY %= iCurrPow;
		--iSize;
	}
	
	iCurrPow = 1;
	while (!stlDir.empty())
	{
		cout << stlDir.top() << endl;
		iResult += stlDir.top() * iCurrPow * iCurrPow;

		stlDir.pop();
		iCurrPow *= 2;
	}
	cout << iResult;
}