#include "pch.h"
#include "Header.h"
#include <vector>

void Solve(ifstream* _pLoadStream)
{
	vector<int> ASequence;
	vector<int> BSequence;
	vector<int> Result;
	int InputA, InputB;

	CIN >> InputA;
	ASequence.resize(InputA);
	for (int i = 0; i < InputA; ++i)
		CIN >> ASequence[i];
	CIN >> InputB;
	BSequence.resize(InputB);
	for (int i = 0; i < InputB; ++i)
		CIN >> BSequence[i];

	int AIndex{ -1 }, BIndex{ -1 };
	int Curr;
	int Target;
	int TempB;
	bool Renew{true};
	while (1)
	{
		Curr = 0;
		Renew = false;
		for (int a = AIndex + 1; a < InputA; ++a)
		{
			Target = ASequence[a];
			if (Curr < Target)
			{
				for (int b = BIndex + 1; b < InputB; ++b)
				{
					if (Target == BSequence[b])
					{
						AIndex = a;
						Curr = Target;
						TempB = b;
						Renew = true;
						break;
					}
				}
			}
		}
		if (!Renew)
			break;
		BIndex = TempB;
		Result.push_back(Curr);

	}

	/*for (int& Temp : Result)
		cout << Temp << ' ';*/
	int ResultSize = Result.size();
	cout << ResultSize << '\n';
	for (int i = 0; i < ResultSize; ++i)
		cout << Result[i] << ' ';
}