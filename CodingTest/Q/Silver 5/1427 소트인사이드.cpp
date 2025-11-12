#include "pch.h"
#include "Header.h"
#include <list>

void Solve(ifstream* _pLoadStream)
{
	string a;
	CIN >> a;
	list<int> Temp;
	for (char c : a)
		Temp.push_back(c - '0');
	Temp.sort(greater<int>());
	for (int i : Temp)
		cout << i;
}