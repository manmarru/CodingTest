#include "pch.h"
#include "Header.h"
#include <vector>
#include <algorithm>
#include <queue>

/*
https://www.acmicpc.net/problem/1781
잘 풀었음

https://www.acmicpc.net/source/99657610
이건 간결해진 답안 (그냥 내 코드 주석들만 봐도 된다.)
*/

// first = 데드라인
// second = 컵라면수

struct COMP
{
	bool operator ()(pair<int, int> Temp, pair<int, int> Src)
	{
		return Temp.second > Src.second;
	}
};

void Solve(ifstream* _pLoadStream)
{
	int Size;
	CIN >> Size;
	vector<pair<int, int>> Board(Size);
	for (int i = 0; i < Size; ++i)
	{
		CIN >> Board[i].first >> Board[i].second;
	}

	sort(Board.begin(), Board.end());/* ,
		[](pair<int, int> Temp, pair<int, int> Src)
		{
			if (Temp.first == Src.first)
				return Temp.second > Src.second;
			return Temp.first < Src.first;
		});어차피 마감일 같은 애들끼리는 거를 수 있다.*/

	priority_queue<pair<int, int>, vector<pair<int, int>>, COMP> Q;
	//우선 순위 큐에는 점수만 넣어도 상관없다. 그러면 비교구조체 만들 필요도 없네
	for (int i = 0; i < Size; ++i)
	{
		Q.push(Board[i]);
		if (Q.size() > Board[i].first)
			Q.pop();
	}

	int Result = 0;
	while (!Q.empty())
	{
		Result += Q.top().second;
		Q.pop();
	}

	cout << Result;
}