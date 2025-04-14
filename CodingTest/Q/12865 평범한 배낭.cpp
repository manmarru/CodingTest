#include "pch.h"
#include "Header.h"
#include <vector>

struct BAG
{
	int Weight;
	int Value;
};

void Solve(ifstream* _pLoadStream)
{
	/*
	배냥에 넣을 수 있는 물건들의 가치의 최댓값을 출력

	set으로 중복되는 무게,가치는 제거하면서 풀려 했는데
	삽입할때마다 정렬하는건 생각 못했다. ㅈㄴ느림
	*/

	int Size;
	int MaxWeight;
	CIN >> Size >> MaxWeight;

	vector<int> DP(MaxWeight + 1, -1); // 무게당 최대 가치
	DP[0] = 0;
	vector<BAG> Entry;
	Entry.reserve(Size);
	BAG Input; // 무게, 가치

	for (int i = 0; i < Size; ++i)
	{
		CIN >> Input.Weight >> Input.Value;
		Entry.push_back(Input);
	}
	/*
	현재 물건을 넣기 전까지의 무게별 DP를 확인할거임
	*/

	vector<int> NewDP(MaxWeight + 1, 0);
	for (int i = 0; i < Size; ++i)
	{
		for (int j = 0; j < MaxWeight; ++j)
		{
			if (DP[j] == -1)
				continue;

			if (j + Entry[i].Weight > MaxWeight)
				break;
			//역순으로 maxweight부터 넣으면 newDP 필요없다.
			NewDP[j + Entry[i].Weight] = max(DP[j + Entry[i].Weight], DP[j] + Entry[i].Value);
		}
		for (int j = 0; j <= MaxWeight; ++j)
		{
			DP[j] = NewDP[j] == 0 ? DP[j] : NewDP[j];
			NewDP[j] = 0;
		}
	}

	int Result(0);
	for (int i = 1; i <= MaxWeight; ++i)
	{
		Result = max(DP[i], Result);
	}
	
	cout << Result;
}