#pragma once
#include "pch.h"
#include "2751.h"
#include <set>
void Solve(ifstream* pLoadStream)
{
	/*
	Á¤·Ä
	*/

	set<int> setNums;

	int iInput(0);
	int iNum(0);
	*pLoadStream >> iInput;
	for (size_t i = 0; i < iInput; i++)
	{
		*pLoadStream >> iNum;
		setNums.insert(iNum);
	}

	for (auto temp : setNums)
	{
		cout << temp << endl;
	}


}