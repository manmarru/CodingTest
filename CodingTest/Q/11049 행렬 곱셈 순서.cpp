#include "pch.h"
#include "Header.h"
#include <vector>
#include <limits.h>
#include <queue>

// a * b ��İ� b * c ����� ���� ����� a * c ����̴�.
// ���귮�� a * b * c �̴�.
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