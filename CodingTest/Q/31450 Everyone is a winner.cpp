#include "pch.h"
#include "Header.h"

void Solve(ifstream* _pLoadStream)
{
	/*
	my friend wants to give the same number of medals to every student
	*/

	int Size;
	int Medal;
	CIN >> Size >> Medal;

	cout << (Size % Medal == 0 ? "Yes" : "No");
}