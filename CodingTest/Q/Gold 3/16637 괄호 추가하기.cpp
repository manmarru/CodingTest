#include "pch.h"
#include "Header.h"
#include <string>
#include <vector>
#include <sstream>

/*
https://www.acmicpc.net/problem/16637
������ ������ ���� �����ϱ� Result �ʱⰪ�� 0���� �ϸ� �ȵȴ�. (max�� ���ϴϱ�)
�� ��ȣ���� ������ �� ���� ���길 ���� �� �����ϱ�
��ȣ�� ���� �߰��� �ʿ� ���� ���� ������ �� �ٲٸ� �ȴ�.

*/

long long int Result{ -99999 };
int Size;
vector<int> Nums;
vector<char> Opers;

long long int Oper(int front, int back, char op)
{
	switch (op)
	{
	case '+':
		return front + back;
	case '-':
		return front - back;
	case '*':
		return front * back;
	default:
		return 0;
	}
}

void DFS(int CurrIndex, long long int StackNum)
{
	if (CurrIndex == Size)
	{
		Result = max(Result, StackNum);
		return;
	}

	DFS(CurrIndex + 1, Oper(StackNum, Nums[CurrIndex + 1], Opers[CurrIndex]));

	if (CurrIndex == Size - 1)
		return;

	DFS(CurrIndex + 2, Oper(StackNum, Oper(Nums[CurrIndex + 1], Nums[CurrIndex + 2], Opers[CurrIndex + 1]), Opers[CurrIndex]));

	return;
}

void Solve(ifstream* _pLoadStream)
{
	string Input;
	CIN >> Size >> Input;
	int iInput;
	char szInput;
	stringstream ss(Input);
	while (ss >> iInput >> szInput)
	{
		Nums.push_back(iInput);
		Opers.push_back(szInput);
	}
	Nums.push_back(iInput);

	Size /= 2;
	DFS(0, Nums[0]);
	cout << Result;
}