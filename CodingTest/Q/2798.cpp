#pragma once
#include "pch.h"
#include "30802.h"
#include <vector>

void Solve(ifstream* pLoadStream)
{
	//카드갯수, 블랙잭 넘버 카드들의 숫자값을 받고 블랙잭 넘버에 가장 가까운 3합결과를 출력
	int iAmount(0), iMaxNum(0);
	int Temp;
	int iAnswer(0);
	vector<int> vecDeck;
	(*pLoadStream) >> iAmount >> iMaxNum;

	for (size_t i = 0; i < iAmount; i++)
	{
		(*pLoadStream) >> Temp;
		if (Temp < iMaxNum)
		{
			vecDeck.push_back(Temp);
		}
	}
	
	int iSum(0);
	for (size_t i = 0; i < vecDeck.size() - 2; i++)
	{
		for (size_t j = i + 1; j < vecDeck.size() - 1; j++)
		{
			for (size_t k = j + 1; k < vecDeck.size(); k++)
			{
				iSum = vecDeck[i] + vecDeck[j] + vecDeck[k];
				if (iSum <= iMaxNum && iAnswer < iSum)
					iAnswer = iSum;
			}
		}
	}

	cout << iAnswer << endl;
	return;

}