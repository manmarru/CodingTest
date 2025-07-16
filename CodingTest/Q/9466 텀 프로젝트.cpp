#include "pch.h"
#include "Header.h"
#include <vector>

enum STATE { STATE_NONE, STATE_SEARCHING, STATE_VISITED };
struct NODE
{
	int Parent;
	STATE History = STATE_NONE;
};

vector<NODE> Nodes;
int Result;
bool DFS(int Curr)
{
	switch (Nodes[Curr].History)
	{
	case STATE_NONE:
		Nodes[Curr].History = STATE_SEARCHING;
		if (true == DFS(Nodes[Curr].Parent))
		{
			if (Nodes[Curr].History == STATE_VISITED)
				return false;
			Nodes[Curr].History = STATE_VISITED;
			--Result;
			return true;
		}
		else
		{
			Nodes[Curr].History = STATE_VISITED;
			return false;
		}
		break;
	case STATE_SEARCHING:
		--Result;
		Nodes[Curr].History = STATE_VISITED;
		return true;
	case STATE_VISITED:
		return false;
	}
	return false; // ¿©±â ¿À¸é °Á ¾ÈµÊ.
}

void Solve(ifstream* _pLoadStream)
{
	int QuerySize;
	int InputSize;
	CIN >> QuerySize;
	for (int Query = 0; Query < QuerySize; ++Query)
	{
		Nodes.clear();
		Result = 0;
		CIN >> InputSize;
		Result = InputSize;
		Nodes.resize(InputSize + 1);
		for (int i = 1; i <= InputSize; ++i)
		{
			CIN >> Nodes[i].Parent;
			if (i == Nodes[i].Parent)
			{
				Nodes[i].History = STATE_VISITED;
				--Result;
			}
		}

		for (int i = 1; i <= InputSize; ++i)
		{
			if (Nodes[i].History != STATE_NONE)
				continue;
			DFS(i);
		}
		cout << Result << endl;
	}

}