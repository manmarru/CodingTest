#include "pch.h"
#include "Header.h"
#include <vector>


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
	Input -= 1;
	int Curr = 0;
	vector<vector<int>> Temp = Matrix;
	for (int i = 0; i < Input; ++i)
	{
		Matrix = Matrix * Temp;
		Curr += 1;
	}
	for (int y = 0; y < Size; ++y)
	{
		for (int x = 0; x < Size; ++x)
		{
			cout << Matrix[y][x] << '\t';
		}
		cout << endl;
	}
	/*
	음...일단 쪼개야될거같은데
	B = B1 + B2
	B1 = B3 + B4 이런식으로
	*/
	

}