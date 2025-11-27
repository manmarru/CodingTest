#include "pch.h"
#include "Header.h"
#include <vector>

/*
https://www.acmicpc.net/problem/17406
입력값이 크지 않아서 상관 없긴 했는데
DFS를 할 때마다 숫자판을 복사하는 게 규모가 큰 상황에서 문제가 된다.
- 해결방법
Cursor 앞쪽에 있는 애들은 더 swap 안하니까 그쪽 쿼리는 Turn을 한 상태로 다음 재귀에 전달한다.

DFS()
{
	if(다 정했으면)
		CountMin

	swap
	clone
	Turn (커서 번호에 있는 퀴리만)
	DFS
	swap
}
이런식으로
*/

//입력값 1부터 시작한다.


void TEST(vector<vector<int>>& Target)
{
	for (auto& Temp : Target)
	{
		for (int a : Temp)
		{
			cout << a << '\t';
		}
		cout << endl;
	}
	라인프린트;
}

int dY[4] = { 1, 0, -1, 0 };
int dX[4] = { 0, 1, 0, -1 };
int SizeY, SizeX;
int QuerySize;
int Result = 200000000;
struct NODE
{
	pair<int, int> Center;
	int s;
};

void Turn(vector<vector<int>>& Board, NODE S )
{
	pair<int, int> Curr;
	for (int i = 1; i <= S.s; ++i)
	{
		int Cash = Board[S.Center.first - i][S.Center.second  - i];// RU
		Curr = { S.Center.first - i, S.Center.second - i };
		for (int way = 0; way < 4; ++way)
		{
			for (int j = 0; j < i * 2; ++j)
			{
				Board[Curr.first][Curr.second] = Board[Curr.first + dY[way]][Curr.second + dX[way]];
				Curr.first += dY[way];
				Curr.second += dX[way];
			}
		}
		Board[Curr.first][Curr.second + 1] = Cash;
	}
}

void DFS(int Cursor, vector<NODE>& Nodes, vector<vector<int>>& Board)
{
	if (Cursor == QuerySize)
	{
		vector<vector<int>> Clone = Board;
		for (NODE Node : Nodes)
		{
			Turn(Clone, Node);
		}
		TEST(Clone);
		for (int y = 0; y < SizeY; ++y)
		{
			int Sum = 0;
			for (int x = 0; x < SizeX; ++x)
			{
				Sum += Clone[y][x];
			}
			Result = min(Result, Sum);
		}
		return;
	}

	for (int i = Cursor; i < QuerySize; ++i)
	{
		swap(Nodes[i], Nodes[Cursor]);
		DFS(Cursor + 1, Nodes, Board);
		swap(Nodes[i], Nodes[Cursor]);
	}
}

void Solve(ifstream* _pLoadStream)
{
	CIN >> SizeY >> SizeX >> QuerySize;
	vector<vector<int>> Board(SizeY, vector<int>(SizeX));

	for (int y = 0; y < SizeY; ++y)
	{
		for (int x = 0; x < SizeX; ++x)
		{
			CIN >> Board[y][x];
		}
	}

	NODE S;
	vector<NODE> Nodes;
	for (int i = 0; i < QuerySize; ++i)
	{
		CIN >> S.Center.first >> S.Center.second >> S.s;
		S.Center.first -= 1;
		S.Center.second -= 1;
		Nodes.push_back(S);
	}
	
	DFS(0, Nodes, Board);
	cout << Result;
}