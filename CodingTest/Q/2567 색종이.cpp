#include "pch.h"
#include "Header.h"

#define LEFT 0
#define RIGHT 1

struct PAPER // ���ϴ� �������� ��ǥ
{
	int y;
	int x;

	// �� ��
	int Left[2]{ 0, 10 };
	int Right[2]{ 0, 10 };
	int Up[2]{ 0, 10 };
	int Down[2]{ 0, 10 };
};



bool AABB(PAPER& Temp, PAPER& Src)
{
	if (abs(Temp.x - Src.x) > 10)
		return false;

	if (abs(Temp.y - Src.y) > 10)
		return false;

	int DeltaX = Src.x - Temp.x;
	int DeltaY = Src.y - Temp.y;

	if (abs(DeltaX) <= 10) // ���Ʒ����� ���� ����
	{
		if (DeltaY < 0) // Temp�� ���� ����
		{
			Temp.Down[LEFT] = max(Temp.Down[LEFT], DeltaX);
			Src.Up[RIGHT] = min(Src.Up[RIGHT], 10 - DeltaX);
		}
		else
		{

		}
	}

	if(abs(DeltaY) <= 10) // �¿���� ���� ����
	{
		
	}

	return true;
}

void Solve(ifstream* _pLoadStream)
{
	int PaperSize;
	CIN >> PaperSize;

	int Input;
	for (int i = 0; i < PaperSize; ++i)
	{

	}
}