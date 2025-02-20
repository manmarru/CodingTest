#include "pch.h"
#include "Header.h"
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

void Solve(ifstream* pLoadStream)
{
	/*
	»ê¼úÆò±Õ (Æò±Õ)
	Áß¾Ó°ª
	ÃÖºó°ª
	¹üÀ§ (ÃÖ´ë - ÃÖ¼Ò)
	±¸ÇÏ±â
	*/


	int iSize{};
	int iInput{};
	int iResult[4] = { 0, 0, 0, 0 };
	vector<int> vecSample;
	map<int, int> mapSample;
	CIN >> iSize;

	for (int i = 0; i < iSize; i++)
	{
		CIN >> iInput;
		vecSample.push_back(iInput);
		++mapSample[iInput];
	}
	sort(vecSample.begin(), vecSample.end());


	for (int i = 0; i < (int)vecSample.size(); ++i) //Æò±Õ
	{
		iResult[0] += vecSample[i];
	}
	iResult[0] = floor(0.5 + iResult[0] / (double)vecSample.size());



	if (vecSample.size() % 2 == 0)				//Áß¾Ó
	{
		iResult[1] = floor(0.5 + (vecSample[iSize / 2 - 1] + vecSample[(iSize / 2)]) / 2);
	}
	else
	{
		iResult[1] = vecSample[iSize / 2];
	}


												//ÃÖºó
	int iMax = (*mapSample.begin()).second;
	pair<int, int> iMaxnum = { 4001, 4001 };
	iResult[2] = (*mapSample.begin()).first;
	for (pair<int, int> i : mapSample)
	{
		if (iMax < i.second)
		{
			iMax = i.second;
			iMaxnum.first = iMaxnum.second = 4001;
		}
		if (iMax == i.second)
		{
			if (i.first < iMaxnum.second)
			{
				iMaxnum.second = i.first;
				if (iMaxnum.second < iMaxnum.first)
					swap(iMaxnum.first, iMaxnum.second);
			}
		}
	}
	if (iMaxnum.second != 4001)
		iResult[2] = iMaxnum.second;
	else
		iResult[2] = iMaxnum.first;



	iResult[3] = vecSample.back() - vecSample.front();	//¹üÀ§



	for (int i = 0; i < 4; i++)
	{
		cout << iResult[i] << endl;
	}
	
}