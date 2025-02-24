#include "pch.h"
#include "Header.h"
#include <vector>
#include <set>
#include <string>

void Solve(ifstream* pLoadStream)
{
	/*
	듣도 보도 못한 사람의 명단을 구하기
	*/

	int iInput[2];
	CIN >> iInput[0] >> iInput[1];
	set<string> mapListened;
	set<string> mapWatched;
	vector<string> vecResult;
	string strTemp;

	for (int i = 0; i < iInput[0]; ++i)
	{
		CIN >> strTemp;
		mapListened.insert(strTemp);
	}
	for (int i = 0; i < iInput[1]; ++i)
	{
		CIN >> strTemp;
		mapWatched.insert(strTemp);
	}

	if (iInput[0] < iInput[1])
	{
		for (string src : mapListened)
		{
			if (mapWatched.find(src) != mapWatched.end())
			{
				vecResult.push_back(src);
			}
		}
	}
	else
	{
		for (string src : mapWatched)
		{
			if (mapListened.find(src) != mapListened.end())
			{
				vecResult.push_back(src);
			}
		}
	}

	cout << vecResult.size() << '\n';

	for (string Src : vecResult)
		cout << Src << endl;
}