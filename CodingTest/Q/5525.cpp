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
	P2 = IoIoI (o의 갯수로 생각하면 됨)
	P3 = IOIOIOI
	o 로 끝났는데 짝수임IOIOIO = 길이 / 2 - 1
				홀수임OIOIO = 길이 / 2  - 1
	I로 끝났는데 짝수OIOIOI = 길이 / 2 - 1
				홀수IOIOIOI = 길이 / 2
	나온거에 - target + 1 하면 된다. 음수면 버리고
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