#include "pch.h"
#include "Header.h"
#include <vector>

/*
선행해야 하는 원소를 연결해놓는다.
출력할때는 히스토리를 같이 사용한다.
여러개 연결돼있으면 그냥 탐색한 뒤 출력하면서 빠져나오셈 여러개면 뭐가 먼저와도 상관없음

https://www.acmicpc.net/source/95860315
위상 정렬로 푸는 방법도 있다.
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