#include "pch.h"
#include "Header.h"
#include <vector>

/*
�����ؾ� �ϴ� ���Ҹ� �����س��´�.
����Ҷ��� �����丮�� ���� ����Ѵ�.
������ ����������� �׳� Ž���� �� ����ϸ鼭 ���������� �������� ���� �����͵� �������

https://www.acmicpc.net/source/95860315
���� ���ķ� Ǫ�� ����� �ִ�.
*/

struct NODE
{
	int Num;
	vector<NODE*> Fronts;
};

vector<bool> History;
void DFS(NODE* Node)
{
	if (History[Node->Num])
		return;

	if (Node->Fronts.empty())
	{
		cout << Node->Num << ' ';
		History[Node->Num] = true;
		return;
	}
	else
	{
		for (NODE* Temp : Node->Fronts)
		{
			DFS(Temp);
		}
		cout << Node->Num << ' ';
		History[Node->Num] = true;
	}
}


void Solve(ifstream* _pLoadStream)
{
	int ManSize, MeasureSize;
	CIN >> ManSize >> MeasureSize;
	++ManSize;
	vector<NODE> Mans(ManSize);
	History.resize(ManSize, false);
	for (int i = 1; i < ManSize; ++i)
		Mans[i].Num = i;

	int FrontInput, BackInput;
	for (int i = 0; i < MeasureSize; ++i)
	{
		CIN >> FrontInput >> BackInput;
		Mans[BackInput].Fronts.push_back(&Mans[FrontInput]);
	}

	for (int i = 1; i < ManSize; ++i)
	{
		if (Mans[i].Fronts.empty() && !History[i])
		{
			cout << Mans[i].Num << ' ';
			History[i] = true;
		}
		else
		{
			DFS(&Mans[i]);
		}
	}

}