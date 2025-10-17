#include "pch.h"
#include "Header.h"
#include <vector>

/*
https://www.acmicpc.net/problem/2529

좀 간결한 코드를 보긴 했는데
https://www.acmicpc.net/source/99065368
나처럼 vector<int>를 쓰는게 아니라 DFS에 매개변수로 ""를 넘기고 여기에 문자 넣었다 뺐다 하면서 씀
sort는 할 필요 없음 어차피 최고차항이 숫자 크기로 순회하니깐
*/


int Size;
bool History[10] = { false, false, false, false, false, false, false, false, false, false }; // 0까지 10개다
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