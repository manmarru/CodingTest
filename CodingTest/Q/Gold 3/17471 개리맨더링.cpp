#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>

vector<int> Population;
vector<vector<int>> Links;
int NodeSize;

vector<char> Select;
bool Check(bool Temp) // Temp 쪽 팀이 한 뭉치인지 확인
{
	int Start;
	for (int i = 0; i < NodeSize; ++i)
	{
		if (Temp == Select[i])
		{
			Start = i;
			break;
		}
	}

	vector<int> History(NodeSize, false);
	History[Start] = true;

	queue<int> Destination;
	Destination.push(Start);
	int Count = 1;

	int Curr;
	while (!Destination.empty())
	{
		Curr = Destination.front();
		Destination.pop();

		for(int Next : Links[Start])
		{
			if (Select[Next] != Temp)
				continue;
			
			if (History[Next] == true)
				continue;
			History[Next] = true;
			Destination.push(Next);
			++Count;
		}
	}


	return true;
}

void Combination(int SelectSize)
{
	if (SelectSize == NodeSize || false == Check(true) || false == Check(false))
	{

		return;
	}



	for (int i = 0; i < NodeSize; ++i)
	{
		Select[i] = true;
		Combination(SelectSize + 1);
		Select[i] = false;
	}
}


void Solve(ifstream* _pLoadStream)
{
	CIN >> NodeSize;
	Population.resize(NodeSize);
	Links.resize(NodeSize);
	Select.resize(NodeSize, false);

	for (int i = 0; i < NodeSize; ++i)
	{
		CIN >> Population[i];
	}

	int Input;
	for (int i = 0; i < NodeSize; ++i)
	{
		int Size;
		CIN >> Size;

		for (int j = 0; j < Size; ++j)
		{
			CIN >> Input;
			Links[i].push_back(Input - 1);
		}
	}

	// 조합을 먼저 만들고 그게 한 덩어리로 있는지 체크하면 된다.
	Combination(0);
}