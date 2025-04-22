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
	규칙 찾아서 별 찍기
	input이 줄 수구나
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
		//왼쪽 공백
		for (int j = 0; j < Input - i; ++j)
			cout << ' ';

		//그려야 하는 삼각형 갯수 먼저 구하자
		int Num = Temp[(i - 1) / 3] * (((i - 1) / 12) + 1);
		for (int j = 0; j < Num / 2; ++j)
		{
			Square((i - 1) % 3);
			// 중간 공백
			/*
			i 칸을 삼각형 num개로 채우게 됨 = (2 * ((i - 1) % 3) - 1) * num
			*/
		}


		cout << '\n';
	}
}