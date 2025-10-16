#include "pch.h"
#include "Header.h"
#include <vector>
#include <string>
#include <stack>

void Solve(ifstream* _pLoadStream)
{
	string Input[2];
	CIN >> Input[0] >> Input[1];
	int InputLength[2]{ Input[0].size() + 1, Input[1].size() + 1 };
	vector<vector<int>> DP(InputLength[0], vector<int>(InputLength[1], 0));

	for (int i = 1; i < InputLength[0]; ++i)
	{
		for (int j = 1; j < InputLength[1]; ++j)
		{
			if (Input[0][i - 1] == Input[1][j - 1])
			{
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			else
			{
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
			}
		}
	}
	int y{ InputLength[0] - 1 };
	int x{ InputLength[1] - 1 };
	cout << DP[InputLength[0] - 1][InputLength[1] - 1] << '\n';
	stack<char> Result;
	while (x != 0 && y != 0)
	{
		if (DP[y][x] == DP[y - 1][x])
		{
			--y;
		}
		else if (DP[y][x] == DP[y][x - 1])
		{
			--x;
		}
		else
		{
			Result.push(Input[0][y - 1]);
			--y;
			--x;
		}
	}
	
	while (!Result.empty())
	{
		cout << Result.top();
		Result.pop();
	}
}