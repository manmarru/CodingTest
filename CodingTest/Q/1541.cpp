#include "pch.h"
#include "Header.h"
#include <string>

void Solve(ifstream* pLoadStream)
{
	/*
	�Ŀ� ��ȣ�� �ļ� ���� �� �ִ� �ּڰ� ���ϱ�
	��������
	- ���� ���� - ���ö����� �� ������ �ɵ�
	*/

	string szInput;
	CIN >> szInput;
	int Conversion{ 0 };
	int iPartialSum{ 0 };
	int iDir{ 1 };
	int iResult{ 0 };
	for (char szCurr: szInput)
	{
		if ('-' == szCurr)
		{
			iPartialSum += Conversion;
			Conversion = 0;
			iResult += iPartialSum * iDir;
			iPartialSum = 0;
			iDir = -1;
			continue;
		}
		else if ('+' == szCurr)
		{
			iPartialSum += Conversion;
			Conversion = 0;
			continue;
		}
		if (isdigit(szCurr))
		{
			Conversion *= 10;
			Conversion += szCurr - '0';
		}
	}
	iPartialSum += Conversion;
	iResult += iPartialSum * iDir;


	cout << iResult;
}