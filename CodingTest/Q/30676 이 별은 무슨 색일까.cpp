#include "pch.h"
#include "Header.h"

void Solve(ifstream* _pLoadStream)
{
	int Color;
	CIN >> Color;
	if (620 <= Color)
		cout << "Red";
	else if (590 <= Color)
		cout << "Orange";
	else if (570 <= Color)
		cout << "Yellow";
	else if (495 <= Color)
		cout << "Green";
	else if (450 <= Color)
		cout << "Blue";
	else if (425 <= Color)
		cout << "Indigo";
	else if (380 <= Color)
		cout << "Violet";

}