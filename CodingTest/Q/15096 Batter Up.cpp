#include "pch.h"
#include "Header.h"

void Solve(ifstream* _pLoadStream)
{
	/*
	Ÿ���� ���� ����ϱ�
	1, 2, 3, 4(Ȩ��)�� ���� 1, 2, 3, 4��
	-1(����)�� �� ��ģ�ɷ� ����
	������ 0
	���� / ���� ģ Ƚ�� ���
	*/
	int Case;
	CIN >> Case;
	double Result(0.000000000);
	double hit(0);
	double Input;
	for (int i = 0; i < Case; ++i)
	{
		CIN >> Input;
		if (-1 == Input)
		{
			continue;
		}
		++hit;
		Result +=Input;
	}
	cout.precision(11);
	cout << Result / hit;

}