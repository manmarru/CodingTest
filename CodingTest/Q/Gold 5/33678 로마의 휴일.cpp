#include "pch.h"
#include "Header.h"
#include <vector>

void Solve(ifstream* _pLoadStream)
{
	int Size, Ticket, Bonus;
	CIN >> Size >> Ticket >> Bonus;

	vector<int> Acc;
	Acc.resize(Size + 1);
	int Input;
	for (int i = 1; i <= Size; ++i)
	{
		CIN >> Input;
		Acc[i] = Input + Acc[i - 1];
	}

	int Left{ 0 }, Right{ Size };
	int Duration;
	int Answer{ 0 };

	while (Left <= Right)
	{
		bool Found = false;
		Duration = (Left + Right) / 2;
		for (int End = Duration; End <= Size; ++End)
		{
			int Cost = Acc[End - Duration] * Bonus + Acc[Size] - Acc[End];

			if (Cost >= Ticket)
			{
				Found = true;
				break;
			}
		}
		if (false == Found)
		{
			Right = Duration - 1;
		}
		else 
		{
			Answer = Duration;
			Left = Duration + 1;
		}
	}

	if (Answer == 0)
	{
		cout << -1;
		return;
	}
	cout << Answer;
}