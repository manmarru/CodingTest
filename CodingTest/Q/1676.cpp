#pragma once
#include "pch.h"
#include "Header.h"

void Solve(ifstream* _pLoadStream)
{
	/*
	�ڿ������� ó�� 0�� �ƴ� ���ڰ� ���� ������ 0�� ������ ���ϱ�
	*/

	int iInput(0);
	int i2(0), i5(0);
	int iCurrNum(0);
	*_pLoadStream >> iInput;

	for (int i = 1; i <= iInput; ++i)
	{
		iCurrNum = i;
		while (true)
		{
			if (iCurrNum % 2 != 0)
				break;
			iCurrNum /= 2;
			++i2;
		}

		while (true)
		{
			if (iCurrNum % 5 != 0)
				break;
			iCurrNum /= 5;
			++i5;
		}
	}
	cout << min(i2, i5);

}