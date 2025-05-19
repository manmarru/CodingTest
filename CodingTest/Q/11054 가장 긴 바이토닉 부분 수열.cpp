#include "pch.h"
#include "Header.h"
#include <vector>


void Solve(ifstream* _pLoadStream)
{
	//부분수열 중 가장 긴 바이토닉 수열의 길이를 구하기
	/*
	https://www.acmicpc.net/source/94493660
	좀 최적화 풀이, 어차피 길이만 알면 되는거니깐.
	*/
	int Size;
	CIN >> Size;
	vector<int> Input(Size);
	vector<int> DP(Size, 0);
	for (int i = 0; i < Size; ++i)
	{
		CIN >> Input[i];
	}
	int Result[3] = { 0, 0, 0};
	
	//dp 사용할거고, n 을 선택했을 때 그 숫자보다 작은 애들 중 가장 크게 기록된 dp값에 1 더한걸 저장해주면 되겠다.
	for (int MainIndex = 0; MainIndex < Size; ++MainIndex)
	{
		fill(DP.begin(), DP.end(), 0);
		DP[MainIndex] = 1;
		Result[0] = 0;
		for (int CurrIndex = MainIndex - 1; CurrIndex >= 0; --CurrIndex) // 왼쪽
		{
			int Curr = Input[CurrIndex];
			if (Curr >= Input[MainIndex])
			{
				DP[CurrIndex] = 0;
				continue;
			}
			// 역순회하면서 Curr 보다 크고, 가장 높은 DP를 가지는 값 찾기
			int MaxCnt{ 0 };
			for (int j = CurrIndex + 1; j <= MainIndex; ++j)
			{
				if(Input[CurrIndex] < Input[j])
					MaxCnt = max(DP[j], MaxCnt);
			}
			DP[CurrIndex] = ++MaxCnt;
		}
		for (int i = 0; i <= MainIndex; ++i)
			Result[0] = max(Result[0], DP[i]);

		
		Result[1] = 0;
		//오른쪽
		for (int CurrIndex = MainIndex + 1; CurrIndex < Size; ++CurrIndex)
		{
			int Curr = Input[CurrIndex];
			if (Curr >= Input[MainIndex])
			{
				DP[CurrIndex] = 0;
				continue;
			}

			int MaxCnt{ 0 };
			for (int j = CurrIndex - 1; j >= MainIndex; --j)
			{
				if (Input[CurrIndex] < Input[j])
					MaxCnt = max(DP[j], MaxCnt);
			}
			DP[CurrIndex] = ++MaxCnt;
		}
		for (int i = Size - 1; i >= MainIndex; --i)
			Result[1] = max(Result[1], DP[i]);


		Result[2] = max(Result[2], Result[0] + Result[1]);
	}

	cout << Result[2] - 1;
}