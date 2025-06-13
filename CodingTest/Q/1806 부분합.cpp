#include "pch.h"
#include "Header.h"
#include <vector>
const int MAXSIZE{ 100001 };

void Solve(ifstream* _pLoadStream)
{
	int Length;
	int MaxSize;
	CIN >> Length >> MaxSize;
	vector<int> Input(Length);

	for (int i = 0; i < Length; ++i)
	{
		CIN >> Input[i];
		if (Input[i] >= MaxSize)
		{
			cout << 1;
			return;
		}
	}

	auto Head = Input.begin();
	auto Tail = Input.begin();
	Head++;
	int Answer{ MAXSIZE };
	int CurrSum{ Input[0] + Input[1] };
	int CurrLength{ 2 };
	while (1)
	{
		if (Head == Tail)
		{
			++Head;
			if (Head == Input.end())
				break;
			CurrSum += *Head;
			++CurrLength;
		}
		else if (CurrSum >= MaxSize)
		{
			Answer = min(Answer, CurrLength);
			CurrSum -= *Tail;
			++Tail;
			--CurrLength;
		}
		else
		{
			++CurrLength;
			++Head;
			if (Head == Input.end())
				break;
			CurrSum += *Head;
		}
	}

	if (MAXSIZE == Answer)
		cout << 0;
	else
		cout << Answer;
}