#include "pch.h"
#include "Header.h"
#include <string>
#include <list>
#include <queue>
#include <array>

struct Compare
{
	bool operator()(array<int, 3> Temp, array<int, 3> Src)
	{
		if (Temp[2] == Src[2])
		{
			if (Temp[0] == Src[0])
				return Temp[1] > Src[1];
			return Temp[0] > Src[0];
		}
		return Temp[2] > Src[2];
	}
};

struct BUTTON
{
	int x;
	int y;
};
BUTTON buttons[10];

int check(BUTTON Before, BUTTON After)
{
	return abs(Before.x - After.x) + abs(Before.y - After.y);
}



void Solve(ifstream* _pLoadStream)
{
	/*
	시간은 초과하면 24로 나눈 나머지로
	분은 초과하면 60으로 나눈 나머지로 입력된다.
	25시는 1시
	61분은 1분으로 인식하는 셈

	원하는 시간을 손가락을 가장 적게 움직여서 입력하기
	(답 여러개면 가장 빠른 시간)
	*/

	for (int i = 1; i < 10; ++i)
	{
		buttons[i].y = (i - 1) / 3;
		buttons[i].x = (i - 1) % 3;
	}
	buttons[0] = { 1, 3 };

	string Input;
	CIN >> Input;
	int Hour, Min;
	Hour = (Input[0] - '0') * 10 + (Input[1] - '0');
	Min = (Input[3] - '0') * 10 + (Input[4] - '0');
	list<int> Hours;
	list<int> Mins;

	while (Hour < 100)
	{
		Hours.push_back(Hour);
		Hour += 24;
	}
	while (Min < 100)
	{
		Mins.push_back(Min);
		Min += 60;
	}
	priority_queue < array<int, 3>, vector<array<int, 3>>, Compare> result;
	//시, 분, 코스트
	array<int, 3> Curr;
	for (int i : Hours)
	{
		for (int j : Mins)
		{
			Curr[0] = i;
			Curr[1] = j;
			Curr[2] = check(buttons[i / 10], buttons[i % 10])
				+ check(buttons[i % 10], buttons[j / 10])
				+ check(buttons[j / 10], buttons[j % 10]);
			result.push(Curr);
		}
	}
	while (!result.empty()) // 디버깅용으로 전부 출력한다.
	{
		if (result.top()[0] < 10)
			cout << 0;
		cout << result.top()[0] << ':';
		if (result.top()[1] < 10)
			cout << 0;
		cout << result.top()[1] << ' ';
		cout << result.top()[2] << endl;
		result.pop();
	}
}