#include "pch.h"
#include "Header.h"

void Solve(ifstream* pLoadStream)
{
	���������ȭ;
	/*
	3Ű�ο� 5Ű�� ������ N�׶� �׸���
	������ �������� ������ -1 ���
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