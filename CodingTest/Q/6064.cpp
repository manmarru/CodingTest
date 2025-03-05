#include "pch.h"
#include "Header.h"

void Solve(ifstream* pLoadStream)
{
	/*
	���� ���̵��
	Z<M>, Z<N> ��ġ�������� <a, b>�� ������ ��Ÿ����
	�������� ������ -1
	�ּҰ���������� �����ϸ� �Ǳ� �ϴµ� �����Ƽ� �׳� �� ���ذ� ���Ѱű��� ���� ����
	A % 11 == 11 ���� ��쵵 ����ؼ� ����ó������
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