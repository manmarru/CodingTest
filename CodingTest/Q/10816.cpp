#include "pch.h"
#include "Header.h"
#include <map>

void Solve(ifstream* pLoadStream)
{
	int iInputSize{};
	map<int, int> mapCards;
	int iInput{};

	*pLoadStream >> iInputSize;
	for (int i = 0; i < iInputSize; ++i)
	{
		*pLoadStream >> iInput;
		mapCards[iInput] += 1;
	}

	*pLoadStream >> iInputSize;
	for (int i = 0; i < iInputSize; ++i)
	{
		*pLoadStream >> iInput;
		cout << mapCards[iInput] << ' ';
	}

}