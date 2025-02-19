#include "pch.h"
#include "Header.h"
#include <list>

void Solve(ifstream* pLoadStream)
{
	/*
	(N,K)요세푸스 순열을 구하기
	*/
	int iN;
	int iK;
	
	list<int> listBoard;
	CIN >> iN >> iK;
	cout << '<';
	for (int i = 0; i < iN; ++i)
		listBoard.push_back(i + 1);

	list<int>::iterator Curr = listBoard.begin();
	while (listBoard.size() != 1)
	{
		for (int i = 0; i < iK - 1; ++i)
		{
			++Curr;
			if (listBoard.end() == Curr)
				Curr = listBoard.begin();
		}
		cout << *Curr << ", ";
		Curr = listBoard.erase(Curr);
		if (listBoard.end() == Curr)
			Curr = listBoard.begin();
	}

	cout << listBoard.front();
	cout << '>';
}