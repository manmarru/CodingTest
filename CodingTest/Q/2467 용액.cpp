#include "pch.h"
#include "Header.h"
#include <vector>

#define MAXNUM 2000000000

//각 용액들의 특성값이 주어진다.
//두 용액을 선택했을 때의 특성값의 합이 가장 작은 경우의 조합을 출력

void Solve(ifstream* _pLoadStream)
{
	int InputSize;
	CIN >> InputSize;

	vector<int> Solution(InputSize);
	for (int i = 0; i < InputSize; ++i)
	{
		CIN >> Solution[i];
	}

	auto Front = Solution.begin();
	auto Back = Solution.end();
	--Back;
	int Result[2];

	int MinSum = MAXNUM;
	while (Front != Back)
	{
		if (abs(*Front + *Back) < abs(MinSum))
		{
			MinSum = *Front + *Back;
			Result[0] = *Front;
			Result[1] = *Back;
		}
		if (*Front + *Back > 0)
		{
			--Back;
		}
		else
		{
			++Front;
		}
	}

	cout << Result[0] << ' ' << Result[1];
}