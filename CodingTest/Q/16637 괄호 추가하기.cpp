#include "pch.h"
#include "Header.h"
#include <vector>
#include <string>

long long int Oper(int front, int back, char oper)
{
	switch (oper)
	{
	case '+':
	{
		return front + back;
		break;
	}
	case '-':
	{
		return front - back;
		break;
	}
	case '*':
	{
		return front * back;
		break;
	}
	}
	cout << "OPER ERROR! : " << oper << endl;
	return -1;
}

int DFS(int Index)
{



	return 0;
}

void Solve(ifstream* _pLoadStream)
{
	int Size;
	string Input;
	CIN >> Size >> Input;

	vector<int> Nums(Size / 2 + 1);
	vector<char> Opers(Size / 2);
	for (int i = 0; i < Size / 2; ++i)
	{
		Nums[i] = Input[i] - '0';
		Opers[i] = Input[i + 1];
	}

	int Answer{ 0 };

	for (int i = 0; i < Opers.size(); ++i)
	{
		Answer = max(Answer, DFS(i));
	}

	cout << Answer;
}