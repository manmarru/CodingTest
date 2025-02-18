#pragma once
#include "pch.h"
#include "Header.h"

void Solve(ifstream* pLoadStream)
{
	//각 변의 길이를 받고 직각삼각형인지 판정하기, 0, 0, 0이 입력값으로 들어올때까지 반복

	int iInput[3] = {1, 1, 1};

	while (1)
	{
		(*pLoadStream) >> iInput[0] >> iInput[1] >> iInput[2];
		if (iInput[0] == 0 && iInput[1] == 0)
			return;


		if (iInput[1] < iInput[2])
			swap(iInput[1], iInput[2]);
		if (iInput[0] < iInput[1])
		{
			swap(iInput[0], iInput[1]);

			if (iInput[1] < iInput[2])
				swap(iInput[1], iInput[2]);
		}
		cout << iInput[0] << ' ' << iInput[1] << ' ' << iInput[2] << endl;
		if (iInput[0] * iInput[0] == iInput[1] * iInput[1] + iInput[2] * iInput[2])
		{
			cout << "right" << endl;
		}
		else
			cout << "wrong" << endl;
	}

	return;
}