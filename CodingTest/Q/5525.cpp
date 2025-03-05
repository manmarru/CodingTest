#include "pch.h"
#include "Header.h"
#include <string>

int iLength{ 1 }, iTarget;
int Result(int _iSize, bool _endO)
{
	if (_endO)
	{
		cout << max(0, (iLength / 2 - 1) - iTarget + 1) << endl;
		return max(0, (iLength / 2 - 1) - iTarget + 1);
	}
	else
	{
		cout << max(0, ((iLength - 1) / 2) - iTarget + 1) << endl;
		return max(0, ((iLength - 1) / 2) - iTarget + 1);
	}
}

void Solve(ifstream* pLoadStream)
{
	/*
	P1 = IoI
	P2 = IoIoI (o�� ������ �����ϸ� ��)
	P3 = IOIOIOI
	o �� �����µ� ¦����IOIOIO = ���� / 2 - 1
				Ȧ����OIOIO = ���� / 2  - 1
	I�� �����µ� ¦��OIOIOI = ���� / 2 - 1
				Ȧ��IOIOIOI = ���� / 2
	���°ſ� - target + 1 �ϸ� �ȴ�. ������ ������
	*/

	int iSize;
	int iResult{ 0 };
	string szInput;
	CIN >> iTarget >> iSize >> szInput;

	for (int i = 1; i < iSize; ++i)
	{
		if (szInput[i - 1] != szInput[i])
		{
			++iLength;
			continue;
		}
		else if (1 == iLength)
			continue;
		else
		{
			iResult	+= Result(i - 1, 'O' == szInput[i - 1]);
			iLength = 1;
		}
	}
	if (iLength != 1)
	{
		iResult += Result(iLength, szInput[iSize - 1] == 'O');
	}

	cout << iResult;
}