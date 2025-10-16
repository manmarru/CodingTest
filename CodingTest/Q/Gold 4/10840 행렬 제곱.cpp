#include "pch.h"
#include "Header.h"
#include <vector>
#include <stack>

int Size;

vector<vector<int>> operator *(vector<vector<int>> Temp, vector<vector<int>> Src)
{
	vector<vector<int>> Result;
	int Width = Temp.size();
	for (int i = 0; i < Width; ++i)
	{
		Result.resize(Width);
		for (int j = 0; j < Width; ++j)
		{
			Result[j].resize(Width, 0);
		}
	}

	for (int y = 0; y < Width; ++y)
	{
		for (int x = 0; x < Width; ++x)
		{
			for (int i = 0; i < Width; ++i)
			{
				Result[y][x] += Temp[y][i] * Src[i][x];
				Result[y][x] %= 1000;
			}
		}
	}

	return Result;
}

void Solve(ifstream* _pLoadStream)
{
	/*
	행렬 A의 B 제곱 구하기
	1 <= A <= 5
	1 <= B <= 천억
	*/
	unsigned long long int Input;
	CIN >> Size >> Input;
	
	vector<vector<int>> Matrix(Size);
	for (int y = 0; y < Size; ++y)
	{
		Matrix[y].resize(Size);
		for (int x = 0; x < Size; ++x)
		{
			CIN >> Matrix[y][x];
		}
	}
	
	vector<vector<int>> Result = Matrix;
	stack<bool> Pow2; //false 면 + 1, true면 * 2
	while (Input != 1)
	{
		if (Input % 2 == 0)
		{
			Pow2.push(true);
			Input /= 2;
		}
		else
		{
			Pow2.push(false);
			Input -= 1;
		}
	}
	/*
	fttft
	1 * 2) * 2) + 1) * 2
	*/
	bool Curr;
	while (!Pow2.empty())
	{
		Curr = Pow2.top();
		Pow2.pop();
		if (Curr)
		{
			Result = Result * Result;
		}
		else
		{
			Result = Result * Matrix;
		}
	}

	for (int y = 0; y < Size; ++y) // 연산 한번도 안했을 경우 %1000 연산을 아에 안하니까!
	{
		for (int x = 0; x < Size; ++x)
		{
			Result[y][x] %= 1000;
		}
	}

	
	// 행렬 출력
	for (int y = 0; y < Size; ++y)
	{
		for (int x = 0; x < Size; ++x)
		{
			cout << Result[y][x] << ' ';
		}
		cout << endl;
	}
	
}

/*
31 = 30 + 1
30 = 15 * 2
15 = 14 + 1
14 = 7 * 2
7 = 6 + 1
6 = 3 * 2
3 = 2 + 1
2 = 1 + 1

31 = ((((((1 + 1) + 1)*2) + 1 ) * 2) +1) *2) +1)
*/