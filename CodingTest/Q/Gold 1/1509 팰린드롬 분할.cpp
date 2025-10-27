#include "pch.h"
#include "Header.h"
#include <vector>
#include <string>

/*
https://www.acmicpc.net/problem/1509
이차원 DP문제 + 대칭성 체크
인덱싱에서 심하게 시간을 많이 쓴다.
eertree라는 알고리즘이 있긴 한데 내가 쓸 일은 없을듯

(사실 1차원 DP에 2차원 히스토리 저장이지?)
구간에 대한 정보가 존재하는지를 unordered_set에 저장하는 방식도 생각해 봤지만,
구간이 존재한다는 건 희소한 원소가 아니기 때문에 원소가 잔뜩 들어갈 가능성도 있다. 불가능!
*/

string Input;
vector<vector<char>> isPal;

void DPFill()
{
	int Size = Input.length();
	for (int i = 0; i < Size; ++i)
		isPal[i][i] = true;

	for (int i = 0; i < Size - 1; ++i)
		if (Input[i] == Input[i + 1])
			isPal[i][i + 1] = true;

	for (int length = 2; length < Size; ++length)
	{
		for (int start = 0; start + length < Size; ++start)
		{
			if (isPal[start + 1][start + length - 1] == false)
				continue;

			if (Input[start] == Input[start + length])
			{
				isPal[start][start + length] = true;
			}
		}
	}
}

void Solve(ifstream* _pLoadStream)
{
	CIN >> Input;
	int Size = Input.length();
	isPal.assign(Size, vector<char>(Size, false));
	DPFill();

	vector<int> DP(Size);
	for (int i = 0; i < Size; ++i)
	{
		if (isPal[0][i] == true)
			DP[i] = 1;
		else
			DP[i] = i + 1;
	}

	for (int start = 1; start < Size; ++start)
	{
		for (int end = start; end < Size; ++end)
		{
			if (isPal[start][end] == true)
			{
				DP[end] = min(DP[end], DP[start - 1] + 1);
			}
		}
	}

	cout << DP.back();
}