#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>
#include <algorithm>

/*
https://www.acmicpc.net/problem/1202
힘들구만
다른 그리디들이랑 비슷하긴 함(정렬하고 큐에 넣어서 우선순위로 뺴는거)
아래 주석 부분부터만 아이디어 보면 될듯
*/

enum MEMO {MUGE, COST};

void Solve(ifstream* _pLoadStream)
{
	int GemSize, BagSize;
	CIN >> GemSize >> BagSize;
	vector<pair<int, int>> Gems(GemSize);
	for (int i = 0; i < GemSize; ++i)
	{
		CIN >> Gems[i].first >> Gems[i].second;
	}
	vector<int> Bags(BagSize);
	for (int i = 0; i < BagSize; ++i)
		CIN >> Bags[i];

	sort(Gems.begin(), Gems.end());
	sort(Bags.begin(), Bags.end());

	priority_queue<int> Q;

	// 넣을 수 있는 보석들을 pq에 넣고
	// pq를 통해 그중 가장 비싼 보석을 하나 꺼낸다.
	// 나머지는 냅뒀다가 다음 비교에 쓰고.

	long long Sum = 0;
	int GemIndex = 0;

	for (int BagIndex = 0; BagIndex < BagSize; ++BagIndex)
	{
		while (GemIndex < GemSize && Gems[GemIndex].first <= Bags[BagIndex])
		{
			Q.push(Gems[GemIndex].second);
			++GemIndex;
		}

		if (!Q.empty())
		{
			Sum += Q.top();
			Q.pop();
		}
	}

	cout << Sum;
}