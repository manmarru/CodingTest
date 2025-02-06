#include "pch.h"
#include "10989.h"
#include <algorithm>

void Solve(ifstream* pLoadStream)
{
	/*
	정렬하기
	숫자갯수
	숫자들
	입력받고 오름차순으로 정렬하기
	*/
	int iInput(0);
	int iNum(0);
	*pLoadStream >> iInput;
	vector<int> vecInput;
	vecInput.resize(10001);

	for (int i = 0; i < iInput; ++i)
	{
		*pLoadStream >> iNum;
		vecInput[iNum] += 1;
	}
	for (int i = 0; i < 10001; ++i)
	{
		for (int j = 0; j < vecInput[i]; ++j)
			cout << i << '\n';
	}
}