#include "pch.h"
#include "Header.h"

void Solve(ifstream* pLoadStream)
{
	입출력최적화;
	/*
	3키로와 5키로 봉투로 N그람 그리드
	나누어 떨어지지 않으면 -1 출력
	*/
	int iInput{};
	int iCurr{};
	int iResult{};
	*pLoadStream >> iInput;
	iCurr = iInput;
	iResult = (int)(iCurr / 5);
	iCurr = iCurr % 5;
	switch (iCurr)
	{
	case 1:
		if (iInput < 6)
		{
			cout << -1 << endl;
			return;
		}
		iResult += 1;
		break;
	case 2:
		if (iInput < 12)
		{
			cout << -1 << endl;
			return;
		}
		iResult += 2;
		break;
	case 4:
		if (iInput < 9)
		{
			cout << -1 << endl;
			return;
		}
		iResult += 2;
		break;
	default:
		if (iCurr % 3 == 0)
		{
			iResult += iCurr / 3;
		}
		else
		{
			cout << -1 << endl;
			return;
		}
		break;
	}


	cout << iResult;
}