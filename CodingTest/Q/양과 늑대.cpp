#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>
#include <unordered_set>

/*
��Ƴ���;;
https://school.programmers.co.kr/learn/courses/30/lessons/92343
����Ž���� �ϵ�, ���� ���¸� ���� �־���� �Ѵ�.

- �ڵ� ���������� �κ�
����� O(N) �� �Ҹ������ �̵��� �����Ǹ� �ٲٴ°Ŷ� O(1)�� �Ҹ�ȴ�.
����Ÿ���� ��� �Ȱ����� unordered_set�� �����ϱ�, ���⼭ �ð� ���⵵�� �Ƴ� �� �ִ�.


CASE CurrCase = move(Destination.front()); // ���� ����
Destination.pop();

������ ����Ŵϱ� ���� ���Ժ��ٴ� std::move�� �̵����ָ� �� �����ڴ�!
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
		CASE CurrCase = move(Destination.front()); // ���� ����
		Destination.pop();

		if (CurrCase.Movable.empty())
		{
			answer = max(answer, CurrCase.Sheep);
			continue;
		}

		for (int i : CurrCase.Movable)
		{
			if (CurrCase.History.find(i) != CurrCase.History.end()) // �� ���� ������
				continue;

			if (Info[i] == 1 && CurrCase.Sheep == CurrCase.Wolf + 1) // ���붧���� �� ����
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