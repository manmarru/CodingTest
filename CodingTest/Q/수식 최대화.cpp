#include "pch.h"
#include "Header.h"
#include <stack>
#include <string>
#include <array>
#include <iostream>

using namespace std;

/*
https://school.programmers.co.kr/learn/courses/30/lessons/67257
문제 풀이 방식 자체는 문제가 없었고, 뒤에 손으로 애쓴거 반복문으로 좀 고치는게 좋을 것 같다.
참고할 만한 함수는 substr이랑 stoi 이용해서 바로 숫자로 전환해버리는 방법이 있겠다.
*/

enum OPER { OPER_PLUS, OPER_MINUS, OPER_MUL, OPER_END };
array<int, 3> OperRank = { 1, 1, 0 };

int RankCheck(char c)
{
	switch (c)
	{
	case '+':
		return OperRank[OPER_PLUS];
	case '-':
		return OperRank[OPER_MINUS];
	case '*':
		return OperRank[OPER_MUL];
	}

	return -1;
}

long long Calc(long long Temp, long long Src, char oper)
{
	if (oper == '+')
		return  Temp + Src;
	else if (oper == '-')
		return Temp - Src;
	else if (oper == '*')
		return Temp * Src;
}

long long TotalCalc(string expr)
{
	stack<long long> StackNum;

	long long Curr = 0;
	for (char c : expr)
	{
		if (c == '/')
		{
			StackNum.push(Curr);
			Curr = 0;
		}
		else if (c < '0')
		{
			long long Temp = StackNum.top();
			StackNum.pop();
			Curr = Calc(Temp, Curr, c);
		}
		else
		{
			Curr = Curr * 10 + c - '0';
		}
	}

	return Curr;
}

string MakeReverse(string Data)
{
	stack<int> Opers;
	string Reverse;

	bool wasOper = false;
	for (char c : Data)
	{
		if (c >= '0')
		{
			if (true == wasOper)
			{
				Reverse.push_back('/');
			}
			Reverse.push_back(c);
			wasOper = false;
		}
		else
		{
			wasOper = true;

			if (!Opers.empty())
			{
				//우선순위 비교 후 넣거나 빼기
				int StackRank = RankCheck(Opers.top());
				int CurRank = RankCheck(c);
				if (CurRank < StackRank)
				{
					Opers.push(c);
				}
				else
				{
					//안에있는거 빼고 넣기
					while (CurRank >= StackRank)
					{
						Reverse.push_back(Opers.top());
						Opers.pop();

						if (Opers.empty())
							break;
						StackRank = RankCheck(Opers.top());
					}
					Opers.push(c);
				}
			}
			else
			{
				Opers.push(c);
			}
		}
	}
	while (!Opers.empty())
	{
		Reverse.push_back(Opers.top());
		Opers.pop();
	}

	return Reverse;
}

long long solution(string expression)
{
	long long Max = 0;

	OperRank = { 0, 1, 2 };
	long long Temp = TotalCalc(MakeReverse(expression));
	Max = max(Max, abs(Temp));

	OperRank = { 0, 2, 1 };
	Temp = TotalCalc(MakeReverse(expression));
	Max = max(Max, abs(Temp));

	OperRank = { 1, 0, 2 };
	Temp = TotalCalc(MakeReverse(expression));
	Max = max(Max, abs(Temp));

	OperRank = { 2, 0, 1 };
	Temp = TotalCalc(MakeReverse(expression));
	Max = max(Max, abs(Temp));

	OperRank = { 1, 2, 0 };
	Temp = TotalCalc(MakeReverse(expression));
	Max = max(Max, abs(Temp));

	OperRank = { 2, 1, 0 };
	Temp = TotalCalc(MakeReverse(expression));
	Max = max(Max, abs(Temp));

	return Max;
}