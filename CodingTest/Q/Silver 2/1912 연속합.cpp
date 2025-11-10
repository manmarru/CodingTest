#include "pch.h"
#include "Header.h"
#include <vector>

/*
https://www.acmicpc.net/problem/1912
이게 DP일줄은 상상도 못했는데
푸는 방법만 알면 구현 자체는 쉽다.

연속합을 저장하되, 현재 값을 포함한 연속합의 최대치를 구한다.
직전 최대치가 음수라면 그냥 현재 값만 있는게 연속합 최대임
전부 구한 후 max를 구하면 되겠다.

물론 입력받으면서 연속합도 같이 구해주면 반복문이 하나로 줄어든다. 풀이시간은 기존도 짧았어서 비교가 안되더라.ㄴ
*/

void Solve(ifstream* _pLoadStream)
{
	int Size;
	CIN >> Size;
	vector<int> Input(Size);
	for (int i = 0; i < Size; ++i)
	{
		CIN >> Input[i];
	}

	int Answer = Input[0];
	for (int i = 1; i < Size; ++i)
	{
		Input[i] = max(Input[i - 1] + Input[i], Input[i]);
		Answer = max(Input[i], Answer);
	}
	cout << Answer;

}