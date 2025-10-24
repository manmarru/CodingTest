#include "pch.h"
#include "Header.h"
#include <string>
#include <vector>
#include <sstream>

/*
https://www.acmicpc.net/problem/16637
정답이 음수일 수도 있으니까 Result 초기값을 0으로 하면 안된다. (max로 비교하니깐)
각 괄호에는 무조건 한 개의 연산만 넣을 수 있으니까
괄호를 직접 추가할 필요 없이 연산 순서만 잘 바꾸면 된다.

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