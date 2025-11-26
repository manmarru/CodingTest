#include "pch.h"
#include "Header.h"
#include <vector>
#include <stack>

/*
https://www.acmicpc.net/problem/12100
내 코드가 느린 건 아니지만 무지 길지?
정석 풀이는 미는 방향은 하나로 고정하고, 방향에 따라 배열을 회전시키는 건가봐.
애초에 배열 최대 크기가 20*20 이라서 시간 초과가 날 일은 없거든.
*/

int Size;
int Answer{ 0 };

void Debug(vector<vector<int>>& Target)
{
	for (int y = 0; y < Size; ++y)
	{
		for (int x = 0; x < Size; ++x)
		{
			cout << Target[y][x] << '\t';
		}
		cout << '\n';
	}
	라인프린트;
}

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

void L(int Count, vector<vector<int>>& Temp);
void R(int Count, vector<vector<int>>& Temp);
void U(int Count, vector<vector<int>>& Temp);
void D(int Count, vector<vector<int>>& Temp);

void L(int Count, vector<vector<int>>& Temp)
{
	vector<vector<int>> Result(Size, vector<int>(Size, 0));
	for (int y = 0; y < Size; ++y)
	{
		bool History = false;
		stack<int> Tilt;
		Tilt.push(Temp[y][0]);
		int Cursor{ 0 };
		if (Tilt.top() == 0)
			--Cursor;

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

		Cursor += Tilt.size() - 1;
		while (Cursor >= 0)
		{
			Result[y][Cursor] = Tilt.top();
			Tilt.pop();
			--Cursor;
		}
	}
	MaxBlock(Result);
	if (Count == 5)
		return;

	L(Count + 1, Result);
	R(Count + 1, Result);
	U(Count + 1, Result);
	D(Count + 1, Result);
	
}

void R(int Count, vector<vector<int>>& Temp)
{
	vector<vector<int>> Result(Size, vector<int>(Size, 0));
	for (int y = 0; y < Size; ++y)
	{
		bool History = false;
		stack<int> Tilt;
		Tilt.push(Temp[y][Size - 1]);
		int Cursor{ 0 };
		if (Tilt.top() == 0)
			++Cursor;

		for (int x = Size - 2; x >= 0; --x)
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

		Cursor += Size - Tilt.size();
		while (Cursor < Size)
		{
			Result[y][Cursor] = Tilt.top();
			Tilt.pop();
			++Cursor;
		}
	}
	MaxBlock(Result);
	if (Count == 5)
		return;

	L(Count + 1, Result);
	R(Count + 1, Result);
	U(Count + 1, Result);
	D(Count + 1, Result);
}

void U(int Count, vector<vector<int>>& Temp)
{
	vector<vector<int>> Result(Size, vector<int>(Size, 0));
	for (int x = 0; x < Size; ++x)
	{
		bool History = false;
		stack<int> Tilt;
		Tilt.push(Temp[0][x]);
		int Cursor{ 0 };
		if (Tilt.top() == 0)
			--Cursor;

		for (int y = 1; y < Size; ++y)
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
		Cursor += Tilt.size() - 1;
		while (Cursor >= 0)
		{
			Result[Cursor][x] = Tilt.top();
			Tilt.pop();
			--Cursor;
		}
	}
	MaxBlock(Result);
	if (Count == 5)
		return;

	L(Count + 1, Result);
	R(Count + 1, Result);
	U(Count + 1, Result);
	D(Count + 1, Result);
}

void D(int Count, vector<vector<int>>& Temp)
{
	vector<vector<int>> Result(Size, vector<int>(Size, 0));
	for (int x = 0; x < Size; ++x)
	{
		bool History = false;
		stack<int> Tilt;
		Tilt.push(Temp[Size - 1][x]);
		int Cursor{ 0 };
		if (Tilt.top() == 0)
			++Cursor;

		for (int y = Size - 2; y >= 0; --y)
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
		Cursor += Size - Tilt.size();

		while (Cursor < Size)
		{
			Result[Cursor][x] = Tilt.top();
			Tilt.pop();
			++Cursor;
		}
	}
	MaxBlock(Result);

	if (Count == 5)
		return;

	L(Count + 1, Result);
	R(Count + 1, Result);
	U(Count + 1, Result);
	D(Count + 1, Result);
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
	R(1, Input);
	U(1, Input);
	D(1, Input);
	cout << Answer;
}