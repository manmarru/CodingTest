#include "pch.h"
#include "Header.h"
#include <stack>
#define CUTLINE 1000000007

/*
1 1				F(n+1)	F(n)
1 0 ÀÇ n½Â =	F(n)	F(n-1)
*/

struct MATRIX22
{
	long long int _00, _01;
	long long int _10, _11;

	MATRIX22 operator *(MATRIX22 Temp)
	{
		return { (_00 * Temp._00 + _01 * Temp._10) % CUTLINE, (_00 * Temp._01 + _01 * Temp._11) % CUTLINE,
				(_10 * Temp._00 + _11 * Temp._10) % CUTLINE, (_10 * Temp._01 + _11 * Temp._11) % CUTLINE };
	}
};


void Solve(ifstream* _pLoadStream)
{
	long long int Input;
	CIN >> Input;
	stack<bool> OddUpper; // È¦¼ö¸é true;
	while (Input != 1)
	{
		if (Input % 2 == 1)
		{
			OddUpper.push(true);
			Input -= 1;
		}
		else
		{
			OddUpper.push(false);
			Input = Input / 2;
		}
	}
	MATRIX22 Result{1, 1, 1, 0};

	bool Curr;
	while (!OddUpper.empty())
	{
		Curr = OddUpper.top();
		OddUpper.pop();

		if (Curr)
		{
			Result = Result * MATRIX22{ 1, 1, 1, 0 };
		}
		else
		{
			Result = Result * Result;
		}
	}
	cout << Result._10;
}