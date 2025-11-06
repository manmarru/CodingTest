#include "pch.h"
#include "Header.h"
#include <map>
#include <vector>

/*
https://www.acmicpc.net/problem/13144
문제 설명 아오 ㅋㅋ
순열중에서 연속된 인덱스만 가능하다.

첨에 이해하는게 좀 어려웠다.
중복이 나올때까지 범위를 확장하고, 중복이 나온다면
그 이전까지의 범위에서 중복이 나온 원소 앞에 나온 애들은 이후부터는 못 쓰지까
그 원소들을 각각 무조건 포함한 수열의 갯수를 Result에 더해준다. Result += R - L
마지막으로 남은 범위는 그 안에서 모든 경우의 수를 더한다.(1로 시작하는 등차수열의 합)
*/

void Solve(ifstream* _pLoadStream)
{
	vector<int> Nums;
	vector<char> Visiting;
	int Size;
	CIN >> Size;
	Nums.resize(Size);
	Visiting.resize(100001, false);
	for (int i = 0; i < Size; ++i)
	{
		CIN >> Nums[i];
	}

	long long Result{ 0 };
	int Left{ 0 }, Right{ 0 };

	while (Right < Size)
	{
		if (Visiting[Nums[Right]] == false)
		{
			Visiting[Nums[Right]] = true;
			++Right;
		}
		else
		{
			Result += Right - Left;
			Visiting[Nums[Left]] = false;
			++Left;
		}
	}

	//마지막 구간에 대해서는 경우의 수를 다 따지면 됨.
	Result += long long(Right - Left) * long long(Right - Left + 1) / 2;

	cout << Result;
}