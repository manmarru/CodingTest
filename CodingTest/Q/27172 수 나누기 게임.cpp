#include "pch.h"
#include "Header.h"
#include <unordered_map>
#include <vector>
#define LIMIT 1000001

/*
https://www.acmicpc.net/source/95462094
더 빠른 사람들 코드도 사용 방식은 동일하지만 맵이 아니라 배열을 썼다.
생각해보면 플레이어 수가 많을수록 버려지는 값도 줄어들어서 배열이 무조건 유리하긴 하겠다.
내 코드는 플레이어가 적으면 메모리적으로 이득이긴 하지.
*/

void Solve(ifstream* _pLoadStream)
{
	unordered_map<int, int> Players;
	vector<int> AnswerSeq;
	int PlayerSize;
	CIN >> PlayerSize;
	int Input;
	for (int i = 0; i < PlayerSize; ++i)
	{
		CIN >> Input;
		AnswerSeq.push_back(Input);
		Players.insert({ Input, 0 });
	}

	int Curr;
	for (auto& Player : Players)
	{
		Curr = Player.first * 2;
		while (Curr < LIMIT)
		{
			if (Players.find(Curr) != Players.end())
			{
				--Players[Curr];
				++Player.second;
			}
			Curr += Player.first;
		}
	}

	for (int i : AnswerSeq)
	{
		cout << Players[i] << ' ';
	}

}