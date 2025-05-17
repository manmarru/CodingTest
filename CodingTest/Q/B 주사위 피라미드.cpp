#include "pch.h"
#include "Header.h"


int Mins[7] = { 0, 1, 3, 6, 10, 15, 21 };

int Maxes[7] = { 0, 6, 11, 15, 18, 20, 21 };

void Solve(ifstream* _pLoadStream)
{
	/*
	2 5 4면 노출 주사위는 등차수열
	1 3 6은 점화식 세우면 됐다.
	*/
	int Input;
	CIN >> Input;
	int Result[7] = { 0 };

	Result[5] = 1;
	Result[2] = Input - 1;
	Result[4] = (Input - 1) * 2;
	if (3 == Input)
	{
		Result[1] = 2;
		Result[2] = 2;
		Result[3] = 1;
	}
	else
	{
		int Temp(0);
		for (int i = 3; i <= Input; ++i)
		{
			Temp += (i - 2) * 2;
		}
		Result[1] = Temp;
		Temp = 0;
		for (int i = 3; i <= Input; ++i)
		{
			Temp += i - 2;
		}
		Result[3] = Temp;
	}
	int Answer(0);
	for (int i = 1; i <= 6; ++i)
	{
		Answer += Result[i] * Mins[i];
		Answer += Result[i] * Maxes[i];
	}
	cout << Answer;
}