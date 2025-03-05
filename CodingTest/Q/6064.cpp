#include "pch.h"
#include "Header.h"

void Solve(ifstream* pLoadStream)
{
	/*
	양쪽 아이디얼
	Z<M>, Z<N> 동치공간에서 <a, b>는 몇인지 나타내기
	존재하지 않으면 -1
	최소공배수까지만 루프하면 되긴 하는데 귀찮아서 그냥 두 기준값 곱한거까지 돌게 했음
	A % 11 == 11 같은 경우도 허용해서 예외처리했음
	*/

	int iSize;
	int iStandard[2];
	int iInput[2];
	CIN >> iSize;

	bool find;
	for (int i = 0; i < iSize; ++i)
	{
		CIN >> iStandard[0] >> iStandard[1] >> iInput[0] >> iInput[1];
		if (iStandard[0] == iInput[0])
			iInput[0] = 0;
		if (iStandard[1] == iInput[1])
			iInput[1] = 0;

		int iIndex = iStandard[0] < iStandard[1] ? 1 : 0;
		find = false;
		int C{ iInput[iIndex] };
		while (C <= iStandard[0] * iStandard[1])
		{
			if ((C % iStandard[0] == iInput[0]) && (C % iStandard[1] == iInput[1]))
			{
				if (0 == C)
				{
					C += iStandard[iIndex];
				}
				cout << C << '\n';
				find = true;

				break;
			}
			C += iStandard[iIndex];
		}
		if (!find)
			cout << -1 << '\n';

	}
}