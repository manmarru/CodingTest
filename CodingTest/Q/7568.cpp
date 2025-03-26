#pragma once
#include "pch.h"
#include "Header.h"

void Solve(ifstream* _pLoadStream)
{
	/*
	두 값이 다 커야 덩치가 더 큼
	각각 자기보다 덩치 큰 사람의 숫자 +1 출력
	*/

	int iInput;
	*_pLoadStream >> iInput;
	vector<pair<int, int>> vecPeople;
	vector<int> vecResult;
	pair<int, int> pairInput;
	for (size_t i = 0; i < iInput; i++)
	{
		*_pLoadStream >> pairInput.first >> pairInput.second;
		vecPeople.push_back(pairInput);
		vecResult.push_back(0);
	}

	for (size_t i = 0; i < vecPeople.size(); i++)
	{
		for (size_t j = 0; j < vecPeople.size(); j++)
		{
			if (i == j)
				continue;

			if (vecPeople[i].first < vecPeople[j].first
				&& vecPeople[i].second < vecPeople[j].second)
				vecResult[i] += 1;
		}
	}
	for (int Temp : vecResult)
		cout << Temp + 1 << endl;

}