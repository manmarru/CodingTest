#include "pch.h"
#include "Header.h"

void Square(int line)
{
	switch (line)
	{
	case 0:
		cout << '*';
		break;
	case 1:
		cout << "* *";
		break;
	case 2:
		cout << "*****";
		break;
	}
}

void Gap(int line)
{
	switch (line)
	{
	case 0:
		cout << "     ";
		break;
	case 1:
		cout << "   ";
		break;
	case 2:
		cout << " ";
		break;
	}
}

void Solve(ifstream* _pLoadStream)
{
	/*
	��Ģ ã�Ƽ� �� ���
	input�� �� ������
	*/

	/*
	3	6	9	12	15	18	21	24
	1	2	2	4	2	4	4	8
	*/
	int Temp[4] = { 1, 2, 2, 4 };
	int Input;
	CIN >> Input;
	for(int i = 1; i <= Input; ++i)
	{
		//���� ����
		for (int j = 0; j < Input - i; ++j)
			cout << ' ';

		//�׷��� �ϴ� �ﰢ�� ���� ���� ������
		int Num = Temp[(i - 1) / 3] * (((i - 1) / 12) + 1);
		for (int j = 0; j < Num / 2; ++j)
		{
			Square((i - 1) % 3);
			// �߰� ����
			/*
			i ĭ�� �ﰢ�� num���� ä��� �� = (2 * ((i - 1) % 3) - 1) * num
			*/
		}


		cout << '\n';
	}
}