#include "pch.h"
#include "Header.h"

void Solve(ifstream* _pLoadStream)
{
	/*
	1	2	3	4	5
	9	8	7	6 
		10	11	12	13
	17	16	15	14 이런식으로 이어지는 손가락 셈 숫자
	받은 숫자는 어느 손가락에서 끝나는지
	*/

	int Input;
	int Board[8] = { 2, 1, 2, 3, 4, 5, 4, 3 };
	cin >> Input;

	Input %= 8;
	cout << Board[Input];

	return;
}