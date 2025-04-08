#include "pch.h"
#include "Header.h"
#include <queue>

void Solve(ifstream* _pLoadStream)
{
	/*
	절댓값 힙 구현하기
	1. 0이 아닌 정수 push
	2. 0을 입력받으면 절댓값이 가장 작은 값을 출력하면서 pop
		동일한 절대값에 대해서 더 작은 값을 pop

	https://www.acmicpc.net/source/90878200 연산자 오버라이딩을 쓰는 방법이 있다.
	*/
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Temp;
	
	int iSize;
	CIN >> iSize;
	int iInput;
	pair<int, int> pairMin;
	int iDir;
	for (int i = 0; i < iSize; i++)
	{
		CIN >> iInput;
		if (0 == iInput)
		{
			if (Temp.empty())
				cout << 0 << '\n';
			else
			{
				pairMin = Temp.top();
				Temp.pop();
				cout << pairMin.first * pairMin.second << '\n';
			}
		}
		else
		{
			iDir = iInput < 0 ? -1 : 1;
			Temp.push({ iInput * iDir, iDir });
		}
	}
}