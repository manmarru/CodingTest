#include "pch.h"
#include "Header.h"
#include <vector>

/*
https://www.acmicpc.net/problem/14889
일단 문제집 답안은 비트마스킹 쓰긴 했는데 넘어가고(내코드가 더 빠름)
알고리즘은 문제 없긴 한데
0번은 팀 고정해도 상관없으니까 0번을 건너뛰는 최적화는 고려해볼 만 하다.
*/

#define INF 100000000
int Size;
vector<char> vecSelected;
vector<vector<int>> Input;
int Check()
{
	int Result = 0;
	for (int y = 0; y < Size; ++y)
	{
		for (int x = 0; x < Size; ++x)
		{
			if (vecSelected[y] != vecSelected[x])
				continue;

			Result += vecSelected[y] ? Input[y][x] : -Input[y][x];
		}
	}

	return abs(Result);
}

int Min = INF;
int DFS(int Curr, int Selected)
{
	if (Selected == Size / 2)
	{
		return Check();
	}

	int Min = INF;
	for (int i = Curr + 1; i < Size; ++i)
	{
		vecSelected[i] = true;
		Min = min(DFS(i, Selected + 1), Min);
		vecSelected[i] = false;
	}
	return Min;
}

void Solve(ifstream* _pLoadStream)
{
	CIN >> Size;
	Input.resize(Size, vector<int>(Size));

	for (int y = 0; y < Size; ++y)
	{
		for (int x = 0; x < Size; ++x)
		{
			CIN >> Input[y][x];
		}
	}

	int Select = Size / 2; // 무조건 짝수라서 나누어 떨어짐
	vecSelected.resize(Size, false);

	cout << DFS(0, 0);
}