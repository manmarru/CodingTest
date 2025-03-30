#include "pch.h"
#include "Header.h"

void Solve(ifstream* _pLoadStream)
{
	/*
	������ ���� ������ũ �丮��!
	���� �����ⰰ��!
	����8 ��� �븥�� 8 ���� 4 �ұ� 1 �а��� 9 = ������ũ ���� 16��
	������ũ�� ����ϴ� �� ���
	- �ٳ��� 1
	- ���� 30
	- ���ݸ� 25
	- ȣ�� 10
	��� ����� ���� �Է¹ް� ���� �� �ִ� ������ũ�� �� ����ϱ�
	*/
	int Case;
	float IngredientNeed[5]{ 8, 8, 4, 1, 9 };
	float Ingredient[5];
	float Deco[4];
	float DecoNeed[4]{ 1, 30, 25, 10 };
	float dough{ 1000000 };
	int Pancake{ 0 };

	CIN >> Case;
	for (int i = 0; i < Case; i++)
	{
		dough = 1000000.f;
		Pancake = 0;

		for (int j = 0; j < 5; ++j)
		{
			CIN >> Ingredient[j];
			dough = min(Ingredient[j] / IngredientNeed[j], dough);
		}
		dough = int(dough * 16);
		int Make = 0;
		for (int j = 0; j < 4; ++j)
		{
			if (dough <= 0)
				break;
			CIN >> Deco[j];
			Make += (int)(Deco[j] / DecoNeed[j]);
		}

		cout << min(Make, (int)dough) << '\n';
	}
}