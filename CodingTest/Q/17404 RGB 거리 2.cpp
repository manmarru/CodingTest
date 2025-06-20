#include "pch.h"
#include "Header.h"
#include <vector>
#include <limits.h>

/*
첫 집과 마지막 집의 색이 다르다.
같은 색의 집이 연속해서 나오지 않는다.

각 집을 각 색으로 칠하는 비용이 주어지면
가장 적은 코스트로 집을 모두 칠하는 가격을 출력하기
*/

struct RGB
{
	int R = 0;
	int G = 0;
	int B = 0;
};

void Solve(ifstream* _pLoadStream)
{
	int HouseSize;
	CIN >> HouseSize;
	vector<RGB> Cost(HouseSize);
	vector<RGB> DP(HouseSize);
	for (int i = 0; i < HouseSize; ++i)
	{
		CIN >> Cost[i].R >> Cost[i].G >> Cost[i].B;
	}
	int Result{ INT_MAX };
	
	//이거 반복문으로 줄이면 코드 길이가 반토막날텐데...
	DP[0] = { INT_MAX, Cost[0].G, Cost[0].B };// 마지막에 R 선택
	for (int i = 1; i < HouseSize; ++i)
	{
		DP[i].R = min(DP[i - 1].G, DP[i - 1].B) + Cost[i].R;
		DP[i].G = min(DP[i - 1].R, DP[i - 1].B) + Cost[i].G;
		DP[i].B = min(DP[i - 1].R, DP[i - 1].G) + Cost[i].B;
	}
	Result = min(Result, Cost[HouseSize - 1].R + min(DP[HouseSize - 2].G, DP[HouseSize - 2].B));

	DP[0] = { Cost[0].R, INT_MAX, Cost[0].B }; //마지막에 G 선택
	for (int i = 1; i < HouseSize; ++i)
	{
		DP[i].R = min(DP[i - 1].G, DP[i - 1].B) + Cost[i].R;
		DP[i].G = min(DP[i - 1].R, DP[i - 1].B) + Cost[i].G;
		DP[i].B = min(DP[i - 1].R, DP[i - 1].G) + Cost[i].B;
	}
	Result = min(Result, Cost[HouseSize - 1].G + min(DP[HouseSize - 2].R, DP[HouseSize - 2].B));

	DP[0] = { Cost[0].R, Cost[0].G, INT_MAX }; //마지막에 B 선택
	for (int i = 1; i < HouseSize; ++i)
	{
		DP[i].R = min(DP[i - 1].G, DP[i - 1].B) + Cost[i].R;
		DP[i].G = min(DP[i - 1].R, DP[i - 1].B) + Cost[i].G;
		DP[i].B = min(DP[i - 1].R, DP[i - 1].G) + Cost[i].B;
	}
	Result = min(Result, Cost[HouseSize - 1].B + min(DP[HouseSize - 2].R, DP[HouseSize - 2].G));

	cout << Result;
}