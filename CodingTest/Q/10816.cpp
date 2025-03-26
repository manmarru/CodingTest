#include "pch.h"
#include "Header.h"
#include <map>

void Solve(ifstream* _pLoadStream)
{
	int iInputSize{};
	map<int, int> mapCards;
	int iInput{};

	*_pLoadStream >> iInputSize;
	for (int i = 0; i < iInputSize; ++i)
	{
		*_pLoadStream >> iInput;
		mapCards[iInput] += 1;
	}

	*_pLoadStream >> iInputSize;
	for (int i = 0; i < iInputSize; ++i)
	{
		*_pLoadStream >> iInput;
		cout << mapCards[iInput] << ' ';
	}

}