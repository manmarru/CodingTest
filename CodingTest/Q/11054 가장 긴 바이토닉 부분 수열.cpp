#include "pch.h"
#include "Header.h"
#include <vector>


void Solve(ifstream* _pLoadStream)
{
	//부분수열 중 가장 긴 바이토닉 수열의 길이를 구하기
	int Size;
	CIN >> Size;
	vector<int> Input(Size);
	vector<int> DP(Size, 0);
	for (int i = 0; i < Size; ++i)
	{
		CIN >> Input[i];
	}
	
	//dp 사용할거고, n 을 선택했을 때 그 숫자보다 작은 애들 중 가장 크게 기록된 dp값에 1 더한걸 저장해주면 되겠다.
	for (int MainIndex = 0; MainIndex < Size; ++MainIndex)
	{
		DP[MainIndex] = 1;
		int Criteria = Input[MainIndex];
		
		for (int CurrIndex = MainIndex; CurrIndex >= 0; --CurrIndex) // 왼쪽
		{
			int Curr = Input[CurrIndex];
			if (Curr > Criteria)
			{
				DP[MainIndex] = 0;
				continue;
			}
			// 역순회하면서 Curr 보다 크고, 가장 높은 DP를 가지는 값 찾기

			int MaxCnt(0);
			for (int j = CurrIndex; j < Criteria; ++j)
			{
				
				MaxCnt = max(DP[j], MaxCnt);
			}
			DP[CurrIndex] = ++MaxCnt;
		}


		for (int i = MainIndex; i < Size; ++i)//오른쪽
		{

		}

	}

}