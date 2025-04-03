#include "pch.h"
#include "Header.h"
#include <string>
#include <stack>

void Solve(ifstream* _pLoadStream)
{
	/*
	겁나 큰 정수 더하기 [-10^10000, 10^10000]
	참고로 파이썬은 그냥 더하면 된다 ㅋㅋ	
	*/
	string Num[2];
	int length[2];
	int sign[2]{1,1};
	bool up{false};
	stack<int> result;

	CIN >> Num[0] >> Num[1];
	if (Num[0][0] == '-')
	{
		sign[0] = -1;
		Num[0].erase(Num[0].begin());
	}
	if (Num[1][0] == '-')
	{
		sign[1] = -1;
		Num[1].erase(Num[1].begin());
	}
	length[0] = Num[0].length();
	length[1] = Num[1].length();

	string Zeros = string(abs(length[0] - length[1]), '0');

	int maxLength = max(length[0], length[1]);
	if (length[0] < length[1])
		Num[0] = Zeros + Num[0];
	else
		Num[1] = Zeros + Num[1];

	cout << Num[0]  << endl;
	cout << Num[1] << endl;


	int Temp;
	for (int i = maxLength - 1; i >= 0; --i)
	{
		Temp = (Num[0][i] - '0') * sign[0] + (Num[1][i] - '0') * sign[1] + up;
		Temp = (Temp ^ (Temp >> 31)) - (Temp >> 31);
		up = Temp >= 10;
		result.push(Temp % 10);
	}

	while (!result.empty())
	{
		cout << result.top();
		result.pop();
	}
}