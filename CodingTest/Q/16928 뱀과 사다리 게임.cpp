#include "pch.h"
#include "Header.h"
#include <queue>

void Solve(ifstream* pLoadStream)
{
	int Board[101]{ 0 };
	int BFS[101]{999};
	for (int i = 1; i <= 100; ++i)
	{
		Board[i] = i;
		BFS[i] = 999;
	}
	BFS[1] = 0;
	int Size[2];
	int Input[2];
	CIN >> Size[0] >> Size[1];
	for (int i = 0; i < Size[0] + Size[1]; i++)
	{
		CIN >> Input[0] >> Input[1];
		Board[Input[0]] = Input[1];
	}

	int Curr{ 1 };
	queue<int> Destination;
	Destination.push(1);
	while (!Destination.empty())
	{
		Curr = Destination.front();
		Destination.pop();
		for (int i = 1; i <= 6; ++i)
		{
			if (Curr + i > 100)
				continue;
			if (BFS[Curr] + 1 >= BFS[Board[Curr + i]])
				continue;
			Destination.push(Board[Curr + i]);
			BFS[Board[Curr + i]] = BFS[Curr] + 1;
		}
	}

	cout << BFS[100];
}