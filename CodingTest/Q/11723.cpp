#include "pch.h"
#include "Header.h"
#include <vector>

void Solve(ifstream* pLoadStream)
{
	/*
	add : 추가 (이미 있으면 무시
	remove : 제거 (없으면 무시
	check : 있으면 1 없으면 0 출력
	toggle : 있으면 제거 없으면 추가
	all : 집합을 1,2,3,4,5,....20 으로 교체
	empty : 집합 비우기
	*/

	int iInput{};
	CIN >> iInput;

	string szInput;
	int iOption;
	vector<bool> vecSet;
	vecSet.resize(20);
	for (int i = 0; i < 20; ++i)
	{
		vecSet[i] = false;
	}

	for (int i = 0; i < iInput; ++i)
	{
		CIN >> szInput;

		if ("all" == szInput)
		{
			for (int j = 0; j < 20; ++j)
				vecSet[j] = true;
			continue;
		}
		else if ("empty" == szInput)
		{
			for (int j = 0; j < 20; ++j)
				vecSet[j] = false;
			continue;
		}

		CIN >> iOption;
		--iOption;
		if ("add" == szInput)
		{
			vecSet[iOption] = true;
		}
		else if ("remove" == szInput)
		{
			vecSet[iOption] = false;
		}
		else if ("check" == szInput)
		{
			cout << vecSet[iOption] << '\n';
		}
		else if ("toggle" == szInput)
		{
			vecSet[iOption] = !vecSet[iOption];
		}
		

	}
}