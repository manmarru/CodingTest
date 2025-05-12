#include "pch.h"
#include "Header.h"
#include <vector>
#include <algorithm>

void Solve(ifstream* _pLoadStream)
{
	int SIZE;
	int Time;
	int Term;
	int Books;
	CIN >> SIZE;
	vector<int> TimeTable(31, 0);
	
	for (int i = 0; i < SIZE; ++i)
	{
		CIN >> Time >> Term;
		--Time;
		--Term;
		for (int j = Time; j <Term; ++j)
		{
			++TimeTable[j];
		}
	}
	CIN >> Books;
	if (Books >= *max_element(TimeTable.begin(), TimeTable.end()))
		cout << 1;
	else
		cout << 0;
	

}