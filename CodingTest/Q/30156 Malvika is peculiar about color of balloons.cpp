#include "pch.h"
#include "Header.h"
#include <string>

void Solve(ifstream* _pLoadStream)
{
	/*
	�̰� �� min����  ����??
	https://www.acmicpc.net/source/91082497 �̰� �� �� ����??
	*/
	int Input;
	string Balloons;
	CIN >> Input;
	for (int i = 0; i < Input; i++)
	{
		int b(0);
		CIN >> Balloons;
		for (int j = 0; j < Balloons.size(); j++)
		{
			if (Balloons[j] == 'b')
				++b;
		}
		if (b <= Balloons.size() / 2)
			cout << b << '\n';
		else
			cout << Balloons.size() - b << '\n';
	}

}