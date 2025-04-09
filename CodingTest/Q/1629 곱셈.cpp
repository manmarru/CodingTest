#include "pch.h"
#include "Header.h"
#include <queue>



void Solve(ifstream* _pLoadStream)
{
	/*
	ū ������ �ŵ����� A^B % c ���
	����Ʈ ������ + �����п� ������ ��⿬�� ����

	B = Q + W �� ��
	A^B % C = ((A^Q % C) * (A^W % C)) % C
	*/

	unsigned long long int InputA, InputB, InputC;
	unsigned long long int Result{ 1 };
	CIN >> InputA >> InputB >> InputC;
	InputA %= InputC;
	queue<bool> BinBit;

	
	//b�� �������� ��Ÿ����
	while (InputB > 1)
	{
		BinBit.push(InputB % 2);
		InputB /= 2;
	}
	BinBit.push(InputB);

	// �����ϱ�
	unsigned long long CurrA{ InputA };
	while (!BinBit.empty())
	{
		if(BinBit.front())
			Result *= CurrA;
		Result %= InputC;
		BinBit.pop();

		CurrA *= CurrA;
		CurrA %= InputC;
	}
	cout << Result << endl;
}