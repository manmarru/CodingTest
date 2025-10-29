#include "pch.h"
#include "Header.h"
#include <vector>

/*
https://www.acmicpc.net/problem/12101
3 이상의 숫자는 사용 불가능하다.
트리로 조합을 싹 다 만들긴 했는데

DP로 갯수만 체크하고, 그 다음부터는
사전순으로 루프 타고 올라가면서 찾는게 효율적이겠다.
*/

struct NODE
{
	int Data;
	int Size = 0;
	vector<NODE*> Nodes;
};

int Insert(int Remain, int n, NODE* Curr)
{
	if (Remain == 0)
		Curr->Size = 1;
	Curr->Data = n;
	for (int i = 1; i <= min(3, Remain); ++i)
	{
		Curr->Nodes.push_back(new NODE);
		Curr->Size += Insert(Remain - i, i, Curr->Nodes.back());
	}

	return Curr->Size;
}

vector<int> answer;
void Print(int Remain, NODE* Curr)
{
	int Sum{ 0 };
	answer.push_back(Curr->Data);
	
	for (NODE* Temp : Curr->Nodes)
	{
		if (Sum + Temp->Size >= Remain)
		{
			Print(Remain - Sum, Temp);
			break;
		}
		Sum += Temp->Size;
	}
}

void Solve(ifstream* _pLoadStream)
{
	int n;
	int k;
	CIN >> n >> k;
	
	NODE Root;
	
	for (int i = 1; i <= min(3, n); ++i)
	{
		Root.Nodes.push_back(new NODE);
		Root.Size += Insert(n - i, i, Root.Nodes.back());
	}

	int Sum{ 0 };
	for (NODE* Temp : Root.Nodes)
	{
		if (Sum + Temp->Size >= k)
		{
			Print(k - Sum, Temp);
			break;
		}
		Sum += Temp->Size;
	}

	if (answer.empty())
		cout << -1;
	else
	{
		cout << answer.front();
		for (int i = 1; i < answer.size(); ++i)
			cout << '+' << answer[i];
	}
}