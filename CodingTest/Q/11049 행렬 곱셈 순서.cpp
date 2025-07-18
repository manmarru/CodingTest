#include "pch.h"
#include "Header.h"
#include <vector>
#include <limits.h>
#include <queue>

// a * b 행렬과 b * c 행렬을 곱한 결과는 a * c 행렬이다.
// 연산량은 a * b * c 이다.
// a b [b c c d] d e
struct MATRIXINFO
{
	unsigned long long int Row; // Left
	unsigned long long int Column; // Right
};
struct NODE
{
	unsigned long long int Data;
	int Index;
};


void Solve(ifstream* _pLoadStream)
{
	int InputSize;
	CIN >> InputSize;
	vector<MATRIXINFO> Inputs(InputSize);
	vector<char> History(InputSize);
	priority_queue <NODE> Sequence;

	for (int i = 0; i < InputSize; ++i)
	{
		CIN >> Inputs[i].Row >> Inputs[i].Column;
		Sequence.push({Inputs[i].Row, i});
	}

	int MinIndex;
	unsigned long long int Min{ ULLONG_MAX };
	for (int i = 1; i < InputSize - 1; ++i)
	{
		Min = min(Min, Inputs[i].Row);
		MinIndex = i;
	}
}