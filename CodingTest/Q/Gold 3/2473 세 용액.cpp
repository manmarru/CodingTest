#include "pch.h"
#include "Header.h"
#include <vector>
#include <algorithm>
#define MAXCOST 3000000000
// �ΰ��� �׳� ����� �� �� ���ٰ� �����ϰ�
// ������ �ϳ��� �̺�Ž������ ���� ���Ѵ�

//�̰� �� �������� �� �𸣰���

vector<long long int> Liquids;
int Head, Left;
int Tail, Right;
int Curr;
int Result[3];
long long int ResultSum = MAXCOST;

void BinarySearch()
{
	long long int CurrSum;

	Left = Head + 1;
	Right = Tail - 1;
	while (Left <= Right)
	{
		Curr = (Right + Left) / 2;
		CurrSum = Liquids[Head] + Liquids[Tail] + Liquids[Curr];

		if (abs(CurrSum) < ResultSum)
		{
			ResultSum = abs(CurrSum);
			Result[0] = Head;
			Result[1] = Curr;
			Result[2] = Tail;
		}

		if (CurrSum > 0)
		{
			Right = Curr - 1;
		}
		else
		{
			Left = Curr + 1;
		}
	}
}

void Solve(ifstream* _pLoadStream)
{
	int InputSize;
	CIN >> InputSize;
	Liquids.resize(InputSize);
	for (int i = 0; i < InputSize; ++i)
	{
		CIN >> Liquids[i];
	}
	sort(Liquids.begin(), Liquids.end());

	Head = 0;
	Tail = Head + 2;

	for (Head; Head < InputSize - 1; ++Head)
	{
		for (Tail = Head + 2; Tail < InputSize; ++Tail)
		{
			BinarySearch();
		}
	}
	
	cout << Liquids[Result[0]] << ' ' << Liquids[Result[1]] << ' ' << Liquids[Result[2]];
}
/*for (int i : Liquids)
	cout << i << '\t';*/