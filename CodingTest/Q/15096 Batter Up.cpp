#include "pch.h"
#include "Header.h"

void Solve(ifstream* _pLoadStream)
{
	/*
	타자의 성적 계산하기
	1, 2, 3, 4(홈런)은 각각 1, 2, 3, 4점
	-1(볼넷)은 공 안친걸로 간주
	삼진은 0
	점수 / 공을 친 횟수 출력
	*/
	int Case;
	CIN >> Case;
	double Result(0.000000000);
	double hit(0);
	double Input;
	for (int i = 0; i < Case; ++i)
	{
		CIN >> Input;
		if (-1 == Input)
		{
			continue;
		}
		++hit;
		Result +=Input;
	}
	cout.precision(11);
	cout << Result / hit;

}