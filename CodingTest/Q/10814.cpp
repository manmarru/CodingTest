#include "pch.h"
#include "Header.h"
#include <string>
#include <list>
#include <algorithm>

void Solve(ifstream* pLoadStream)
{
	//����
	int iInput(0);
	list<pair<int, string>> listPeople;
	*pLoadStream >> iInput;

	pair<int, string> People;
	for (size_t i = 0; i < iInput; i++)
	{
		*pLoadStream >> People.first >> People.second;
		listPeople.push_back(People);
	}

	listPeople.sort([](pair<int, string>Temp, pair<int, string>Src) ->bool
		{
			return Temp.first < Src.first;
		});

	for (auto pair : listPeople)
	{
		cout << pair.first << '\t' << pair.second << endl;
	}
}