#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>
#include <unordered_set>

/*
어렵네잉;;
https://school.programmers.co.kr/learn/courses/30/lessons/92343
완전탐색을 하되, 현재 상태를 같이 넣어줘야 한다.

- 코드 디테일적인 부분
복사는 O(N) 이 소모되지만 이동은 소유권만 바꾸는거라서 O(1)만 소모된다.
원시타입의 경우 똑같지만 unordered_set이 있으니깐, 여기서 시간 복잡도를 아낄 수 있다.


CASE CurrCase = move(Destination.front()); // 복사 방지
Destination.pop();

어차피 지울거니까 복사 대입보다는 std::move로 이동해주면 더 빠르겠다!
*/


struct CASE
{
	int Curr;
	int Sheep = 0;
	int Wolf = 0;
	unordered_set<int> Movable;
	unordered_set<int> History;
	CASE(int curr, int sheep, int wolf) : Curr(curr), Sheep(sheep), Wolf(wolf) 
	{
	}
};

void Solve(ifstream* _pLoadStream)
{
	vector<int> Info{ 0, 0, 1, 1, 0, 0, 0 };
	vector<vector<int>> Edges{ {0, 1},{1, 2},{1, 3},{2, 4},{3, 5},{3, 6} };
	int answer = 1;

	vector<vector<int>> Tree(Info.size());
	for (auto& Link : Edges)
	{
		Tree[Link[0]].push_back(Link[1]);
		Tree[Link[1]].push_back(Link[0]);
	}

	queue<CASE> Destination;
	Destination.push(CASE(0, 1, 0));
	Destination.front().History.insert(0);
	for (int i : Tree[0])
	{
		Destination.front().Movable.insert(i);
	}
	
	while(!Destination.empty())
	{
		CASE CurrCase = move(Destination.front()); // 복사 방지
		Destination.pop();

		if (CurrCase.Movable.empty())
		{
			answer = max(answer, CurrCase.Sheep);
			continue;
		}

		for (int i : CurrCase.Movable)
		{
			if (CurrCase.History.find(i) != CurrCase.History.end()) // 간 적이 있으면
				continue;

			if (Info[i] == 1 && CurrCase.Sheep == CurrCase.Wolf + 1) // 늑대때문에 못 가면
			{
				answer = max(answer, CurrCase.Sheep);
				continue;
			}

			Destination.push(CurrCase);
			Destination.back().Movable.erase(i);
			Destination.back().Curr = i;
			Destination.back().History.insert(i);

			if (Info[i] == 0)
				++Destination.back().Sheep;
			else
				++Destination.back().Wolf;
			
			
			for (int j : Tree[i])
			{
				if (Destination.back().History.find(j) != Destination.back().History.end())
					continue;
				Destination.back().Movable.insert(j);
			}
		}
	}

	cout << answer;
}