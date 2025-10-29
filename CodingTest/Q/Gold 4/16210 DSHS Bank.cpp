#include "pch.h"
#include "Header.h"
#include <vector>
#include <algorithm>

/*
https://www.acmicpc.net/problem/16210
브루트포스로 하기에는 50만^2를 감당 못한다.
x와 y를 각각 정렬해서
각각의 부분합 배열을 만들어서 (어느 은행에 포함하는지도 메모해놔야 함.) 활용하는 방식을 사용해봤다.
*/

struct DATA
{
	long long int Data;
	int Bank;
	bool operator < (DATA& Src)
	{
		return Data < Src.Data;
	}
};

void Solve(ifstream* _pLoadStream)
{
	int Size;
	vector<DATA> Y;
	vector<DATA> X;
	CIN >> Size;
	Y.reserve(Size);
	X.reserve(Size);
	
	int Input[2];
	for (int i = 0; i < Size; ++i)
	{
		CIN >> Input[0] >> Input[1];
		X.push_back({ (long long int)Input[0], i });
		Y.push_back({ (long long int)Input[1], i });
	}

	sort(Y.begin(), Y.end());
	sort(X.begin(), X.end());
	vector<long long int> pSumX(Size, 0);
	vector<long long int> pSumY(Size, 0);

	for (int i = 1; i < Size; ++i)
	{
		pSumX[i] = pSumX[i - 1] + X[i].Data;
		pSumY[i] = pSumY[i - 1] + Y[i].Data;
	}

	vector<long long int> Sum(Size, 0);
	for (int i = 0; i < Size; ++i)
	{
		long long int Temp = X[i].Data * i - pSumX[i];
		long long int Src = pSumX[Size - 1] - X[i].Data * (Size - i);
		Sum[X[i].Bank] += Temp + Src;

		Temp = Y[i].Data * i - pSumY[i];
		Src = pSumY[Size - 1] - Y[i].Data * (Size - i);
		Sum[Y[i].Bank] += Temp + Src;
	}



	long long int Min{ Sum[0] };
	int answer{ 0 };
	for (int i = 1; i < Size; ++i)
	{
		if (Sum[i] < Min)
		{
			answer = i;
			Min = Sum[i];
		}
	}

	cout << answer + 1;
	return;
}