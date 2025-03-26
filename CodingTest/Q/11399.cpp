#include "pch.h"
#include "Header.h"
#include <list>

void Solve(ifstream* _pLoadStream)
{
	/*
	걍 정렬 아님? 시간제한이 1초긴 하네
	*/

	int iSize{};
	long long int iInput{};
	long long int iResult{ 0 };
	list<long long int> listInput;

	CIN >> iSize;
	for (int i = 0; i < iSize; ++i)
	{
		CIN >> iInput;
		listInput.push_back(iInput);
	}
	listInput.sort();

	long long int iCurr{ 0 };
	for (auto Temp : listInput)
	{
		iCurr += Temp;
		iResult += iCurr;
	}
	cout << iResult;
}