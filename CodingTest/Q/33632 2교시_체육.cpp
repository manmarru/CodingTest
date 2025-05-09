#include "pch.h"
#include "Header.h"

struct COOR
{
	int x;
	int y;
};

void Solve(ifstream* _pLoadStream)
{
	/*
	���簢�� ��忡�� �� AB�������� ���� ��
	AB�� ������ ��밡 ��� �ȿ� ������ ��
	��뿡 ���� �� Ȯ�� ���ϱ�

	*/


	COOR Size;
	COOR Wani;
	COOR Left, Right;
	double Result;
	CIN >> Size.x >> Size.y >> Wani.x >> Wani.y >> Left.x >> Left.y >> Right.x >> Right.y;

	if (Wani.y < Right.y) //���� ���� �Էµ��� ����.
	{
		cout << 0;
		return;
	}


	double Temp[2]; // y = 0�� ���� x��
	if (Left.y == 0)
	{
		cout << (Right.x - Left.x) / Size.x;
		return;
	}
	/*
	1 = ���糡��, 2 = ����������ǥ

	x1 : y1 = x2 : y2
	y1 x2 = y2 x1
	x2 = x1 y2 / y1
	*/
	Temp[0] = (Left.x - Wani.x) * Wani.y / (Wani.y - Left.y) + Wani.x;
	Temp[1] = (Right.x - Wani.x) * Wani.y / (Wani.y - Right.y) + Wani.x;

	Temp[0] = min(Temp[0], (double)Size.x);
	Temp[0] = max(0., Temp[0]);

	Temp[1] = min(Temp[1], (double)Size.x);
	Temp[1] = max(0., Temp[1]);
	
	Result = abs(Temp[0] - Temp[1]);
	cout << Result / Size.x;
}