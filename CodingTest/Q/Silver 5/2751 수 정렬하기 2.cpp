#pragma once
#include "pch.h"
#include "Header.h"
#include <set>
void Solve(ifstream* _pLoadStream)
{
	/*
	Á¤·Ä
	*/

	set<int> setNums;

	int iInput(0);
	int iNum(0);
	*_pLoadStream >> iInput;
	for (size_t i = 0; i < iInput; i++)
	{
		*_pLoadStream >> iNum;
		setNums.insert(iNum);
	}

	for (auto temp : setNums)
	{
		cout << temp << endl;
	}


}