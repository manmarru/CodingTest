#include "pch.h"
#include "Header.h"
#include <vector>
#include <map>
#include <string>

void Solve(ifstream* _pLoadStream)
{
	/*
	포켓몬 도감 너무 가지고 싶다ㅜㅜ
	꼭 만점을 받아줘!
	*/

	vector<string> Pokedex;
	map<string, int> mapPokedex;
	int iSize[2];
	CIN >> iSize[0] >> iSize[1];

	Pokedex.resize(iSize[0]);
	for (int i = 0; i < iSize[0]; ++i)
	{
		CIN >> Pokedex[i];
		mapPokedex[Pokedex[i]] = i + 1;
	}

	string strQuestion;
	for (int i = 0; i < iSize[1]; ++i)
	{
		CIN >> strQuestion;
		if (isdigit(strQuestion[0]))
		{
			cout << Pokedex[stoi(strQuestion) - 1] << '\n';
		}
		else
		{
			cout << mapPokedex[strQuestion] << '\n';
		}
	}
}