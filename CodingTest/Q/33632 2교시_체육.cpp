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
	직사각형 운동장에서 변 AB방향으로 공을 참
	AB와 평행한 골대가 운동장 안에 존재할 때
	골대에 공이 들어갈 확률 구하기

	*/


	COOR Size;
	COOR Wani;
	COOR Left, Right;
	double Result;
	CIN >> Size.x >> Size.y >> Wani.x >> Wani.y >> Left.x >> Left.y >> Right.x >> Right.y;

	if (Wani.y < Right.y) //같은 경우는 입력되지 않음.
	{
		cout << 0;
		return;
	}


	double Temp[2]; // y = 0에 닿은 x값
	if (Left.y == 0)
	{
		cout << (Right.x - Left.x) / Size.x;
		return;
	}
	/*
	1 = 골대양끝점, 2 = 벽에닿은좌표

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