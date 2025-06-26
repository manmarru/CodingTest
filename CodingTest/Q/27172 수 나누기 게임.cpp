#include "pch.h"
#include "Header.h"
#include <unordered_map>
#include <vector>
#define LIMIT 1000001

/*
https://www.acmicpc.net/source/95462094
�� ���� ����� �ڵ嵵 ��� ����� ���������� ���� �ƴ϶� �迭�� ���.
�����غ��� �÷��̾� ���� �������� �������� ���� �پ�� �迭�� ������ �����ϱ� �ϰڴ�.
�� �ڵ�� �÷��̾ ������ �޸������� �̵��̱� ����.
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