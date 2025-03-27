#include "pch.h"
#include "Header.h"

void Solve(ifstream* _pLoadStream)
{
	/*
	부족한 액수 계산하기
	*/

	int Price, Need, Own;
	CIN >> Price >> Need >> Own;
	cout << max(0, Price * Need - Own);
}