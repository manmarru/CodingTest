#include "pch.h"
#include "Header.h"
#include <vector>
#define INF 100000

/*
도로는 방향이 없고 웜홀은 방향이 있다.
*/

void Solve(ifstream* _pLoadStream)
{
	int Size;
	CIN >> Size;
	int NodeSize, LinkSize, WormSize;
	int Input[3];
	for (int Case = 0; Case < Size; ++Case)
	{
		CIN >> NodeSize >> LinkSize >> WormSize;
		vector<vector<int>> Floid(NodeSize, vector<int>(NodeSize, INF));
		for (int i = 0; i < NodeSize; ++i)
		{
			Floid[i][i] = 0;
		}


		for (int i = 0; i < LinkSize; ++i)
		{
			CIN >> Input[0] >> Input[1] >> Input[2];
			--Input[0]; --Input[1];
			Floid[Input[0]][Input[1]] = min(Floid[Input[0]][Input[1]], Input[2]);
			Floid[Input[1]][Input[0]] = min(Floid[Input[1]][Input[0]], Input[2]);
		}
		for (int i = 0; i < WormSize; ++i)
		{
			CIN >> Input[0] >> Input[1] >> Input[2];
			--Input[0]; --Input[1];
			Floid[Input[0]][Input[1]] = min(Floid[Input[0]][Input[1]], -Input[2]);
		}

		for (int Mid = 0; Mid < NodeSize; ++Mid)
		{
			for (int Start = 0; Start < NodeSize; ++Start)
			{
				for (int End = 0; End < NodeSize; ++End)
				{
					if (INF == Floid[Start][Mid] || INF == Floid[Mid][End])
						continue;
					Floid[Start][End] = min(Floid[Start][Mid] + Floid[Mid][End], Floid[Start][End]);
				}
			}
		}

		bool Result = false;
 		for (int Start = 0; Start < NodeSize; ++Start)
		{
			for (int End = 0; End < NodeSize; ++End)
			{
				if (Floid[Start][End] + Floid[End][Start] < 0)
				{
					Result = true;
				}
			}
		}

		if (Result)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}