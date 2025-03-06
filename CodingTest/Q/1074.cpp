#include "pch.h"
#include "Header.h"
#include <stack>
#include <cmath>
void Solve(ifstream* pLoadStream)
{
	/*
	사분면으로 계속 쪼개서
	0	1
	2	3
	순서로 순회하는
	방식을 사용할 떄 x,y는 몇 번째 순서가 되는지 출력하기
	*/

	int iSize;
	int iTargetX, iTargetY;
	CIN >> iSize >> iTargetY >> iTargetX; //참고로 0,0은 왼쪽위

	stack<int> stlDir;
	int iIndex;
	int iCurrPow;
	int iResult{ 0 };
	while (iSize > 0)
	{
		int iCurrPow = pow(2, iSize - 1); //최대 15승까지 입력되는데 그럼 32000밖에 안된다.
		if (iTargetX < iCurrPow && iTargetY < iCurrPow) // 2사분면
		{
			stlDir.push(0);
		}
		else if (iTargetX >= iCurrPow && iTargetY < iCurrPow) // 1사분면
		{
			stlDir.push(1);
		}
		else if (iTargetX < iCurrPow && iTargetY >= iCurrPow) // 3사분면
		{
			stlDir.push(2);
		}
		else if (iTargetX >= iCurrPow && iTargetY >= iCurrPow) // 4사분면
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