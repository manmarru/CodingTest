#include "pch.h"
#include "Header.h"
#include <vector>

/*
https://www.acmicpc.net/problem/2529

�� ������ �ڵ带 ���� �ߴµ�
https://www.acmicpc.net/source/99065368
��ó�� vector<int>�� ���°� �ƴ϶� DFS�� �Ű������� ""�� �ѱ�� ���⿡ ���� �־��� ���� �ϸ鼭 ��
sort�� �� �ʿ� ���� ������ �ְ������� ���� ũ��� ��ȸ�ϴϱ�
*/


int Size;
bool History[10] = { false, false, false, false, false, false, false, false, false, false }; // 0���� 10����
vector<char> Opers;
vector<int> Try;
vector<vector<int>> Result;

bool Oper(int Left, int Right, char _Oper)
{
	if (_Oper == '<')
		return Left < Right;
	else if (_Oper == '>')
		return Left > Right;

	cout << "Oper ERROR!";
	return false;
}

void DFS(int CurSlot)
{
	if (CurSlot > Size)
	{
		Result.push_back(Try);
		return;
	}

	for (int Slot = CurSlot; Slot <= Size; ++Slot)
	{
		if (Try.size() != Slot)
			return;

		for (int Num = 0; Num < 10; ++Num)
		{
			if (true == History[Num])
				continue;
			
			if (CurSlot != 0 && false == Oper(Try.back(), Num, Opers[Slot - 1]))
				continue;

			History[Num] = true;
			Try.push_back(Num);
			DFS(CurSlot + 1);
			Try.pop_back();
			History[Num] = false;
		}
	}
}

void Solve(ifstream* _pLoadStream)
{
	CIN >> Size;
	Opers.resize(Size);
	Try.reserve(Size);

	for (int i = 0; i < Size; ++i)
	{
		CIN >> Opers[i];
	}

	DFS(0);

	for (int i : Result.back())
		cout << i;
	cout << '\n';
	for (int i : Result[0])
		cout << i;
}