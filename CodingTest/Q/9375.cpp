#include "pch.h"
#include "Header.h"
#include <string>
#include <map>

void Solve(ifstream* _pLoadStream)
{
	int iCase{};
	CIN >> iCase;

	int iInput{};
	int iResult{};
	string szInput[2];
	for (int CaseNum = 0; CaseNum < iCase; ++CaseNum)
	{
		map<string, int> mapWear;
		iResult = 1;
		CIN >> iInput;

		for (int i = 0; i < iInput; i++)
		{
			CIN >> szInput[0] >> szInput[1];
			mapWear[szInput[1]] += 1;
		}
		for (auto pair : mapWear)
		{
			iResult *= pair.second + 1;
		}

		cout << iResult - 1 << endl; // ´Ù¹þÀº°æ¿ì »©±â
	}



}