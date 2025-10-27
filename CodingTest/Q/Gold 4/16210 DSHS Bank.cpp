#include "pch.h"
#include "Header.h"
#include <vector>

struct COOR
{
	int y, x;
};

void Solve(ifstream* _pLoadStream)
{
	int Input;
	vector<COOR> Banks;
	CIN >> Input;
	Banks.reserve(Input);

	COOR C;
	for (int i = 0; i < Input; ++i)
	{
		CIN >> C.y >> C.x;
		Banks.push_back(C);
	}




	return;
}