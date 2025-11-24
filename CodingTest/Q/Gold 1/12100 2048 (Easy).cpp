#include "pch.h"
#include "Header.h"
#include <vector>
#include <stack>

/*
https://www.acmicpc.net/problem/12100
*/

int Size;
int Answer{ 0 };
void MaxBlock (vector<vector<int>>& Temp)
{
	for (int y = 0; y < Size; ++y)
	{
		for (int x = 0; x < Size; ++x)
		{
			Answer = max(Answer, Temp[y][x]);
		}
	}
	return;
}

void L(int Count, vector<vector<int>> Temp);

void L(int Count, vector<vector<int>> Temp)
{
	vector<vector<int>> Result(Size, vector<int>(Size, 0));
	for (int y = 0; y < Size; ++y)
	{
		bool History = false;
		stack<int> Tilt;
		Tilt.push(Temp[y][0]);

		for (int x = 1; x < Size; ++x)
		{
			if (Temp[y][x] == 0)
				continue;

			if (History == false && Tilt.top() == Temp[y][x])
			{
				Tilt.top() *= 2;
				History = true;
			}
			else
			{
				Tilt.push(Temp[y][x]);
				History = false;
			}
		}

		int Cursor = Tilt.size() - 1;
		while (!Tilt.empty())
		{
			Result[y][Cursor] = Tilt.top();
			Tilt.pop();
			--Cursor;
		}
	}

	if (Count == 5)
		return;

	L(Count + 1, Result);
}


void Solve(ifstream* _pLoadStream)
{
	//최대 5번 행동 가능, 가장 큰 블럭의 숫자 구하기
	CIN >> Size;
	
	vector<vector<int>> Input(Size, vector<int>(Size));
	for (int y = 0; y < Size; ++y)
	{
		for (int x = 0; x < Size; ++x)
		{
			CIN >> Input[y][x];
		}
	}

	if (Size == 1)
	{
		cout << Input[0][0];
		return;
	}

	L(1, Input);
	cout << Answer;
}