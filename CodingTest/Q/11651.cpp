#include "pch.h"
#include "Header.h"

void Solve(ifstream* _pLoadStream)
{
	/*
	y값 오름차순으로, 같으면 x오름차순으로 정렬
	*/
	int iInput{};
	*_pLoadStream >> iInput;

	pair<int, int> Coord;
	list<pair<int, int>> listCoord;
	for (size_t i = 0; i < iInput; i++)
	{
		*_pLoadStream >> Coord.first >> Coord.second;
		listCoord.push_back(Coord);
	}

	listCoord.sort([](pair<int, int>Temp, pair<int, int>Src) ->bool
		{
			return Temp.second == Src.second ? Temp.first < Src.first : Temp.second < Src.second;
		});

	for (pair<int, int> m_Coord : listCoord)
	{
		cout << m_Coord.first << ' ' << m_Coord.second << '\n';
	}

}