#include "pch.h"
#include "Header.h"
#include <list>
#include <string>

void Solve(ifstream* _pLoadStream)
{
	/*
	666이 들어간 n번째로 작은 숫자 출력
	브루트 포스
	*/
	int iSize{};
	string Temp;
	string Src;
	string szZero;
	CIN >> iSize;
	int iLength = (int)to_string(iSize).size();
	list<int> listNums;
//001같은것도 생각해야 된다. 자릿수 고정으로 하면 될듯
	for (int i = 0; i < iSize; ++i)
	{
		Temp = to_string(i);
		szZero = string(iLength - (int)Temp.size(), '0');

		for (int j = 0; j <= iLength; ++j)
		{
			Src = szZero + Temp;
			Src.insert(j, "666");
			listNums.push_back(stoi(Src));
		}
	}

	listNums.sort();
	listNums.unique();

	list<int>::iterator iter = listNums.begin();
	for (int i = 1; i < iSize; ++i)
	{
		++iter;
	}

	cout << *iter;
}