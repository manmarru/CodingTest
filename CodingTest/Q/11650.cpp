#include "pch.h"
#include "Header.h"

void Solve(ifstream* pLoadStream)
{
	/*
	x값 오름차순으로, 같으면 y오름차순으로 정렬
	*/

	int iInput{};
	*pLoadStream >> iInput;

	pair<int, int> Coord;
	list<pair<int, int>> listCoord;
	for (size_t i = 0; i < iInput; i++)
	{
		*pLoadStream >> Coord.first >> Coord.second;
		listCoord.push_back(Coord);
	}

	listCoord.sort([](pair<int, int>Temp, pair<int, int>Src) ->bool
		{
			return Temp.first == Src.first ? Temp.second < Src.second : Temp.first < Src.first;
		});

	for (pair<int, int> m_Coord : listCoord)
	{
		cout << m_Coord.first << ' ' << m_Coord.second << '\n';
	}
}