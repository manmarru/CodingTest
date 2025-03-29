#include "pch.h"
#include "Header.h"

void Solve(ifstream* _pLoadStream)
{
	/*
	�־��� ���ڵ鿡�� ¦������ �հ� Ȧ������ ���� ���ؼ�
	��� ���� �� ū�� ���
	*/

	int Case;
	int Size;
	int Input;
	int EvenSum;
	int OddSum;
	CIN >> Case;
	for (int i = 0; i < Case; i++)
	{
		CIN >> Size;
		EvenSum = OddSum = 0;
		for (int j = 0; j < Size; j++)
		{
			CIN >> Input;
			if (Input % 2 == 0)
				EvenSum += Input;
			else
				OddSum += Input;
		}
		if (EvenSum == OddSum)
			cout << "TIE" << '\n';
		else
			cout << (EvenSum > OddSum ? "EVEN" : "ODD") << '\n';
	}
}