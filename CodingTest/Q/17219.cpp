#include "pch.h"
#include "Header.h"
#include <string>
#include <map>
#include <unordered_map>
void Solve(ifstream* _pLoadStream)
{
	int iInput[2];
	string szInput[2];
	unordered_map<string, string> setPassWord;
	szInput[0].reserve(20);
	szInput[1].reserve(20);

	CIN >> iInput[0] >> iInput[1];

	for (int i = 0; i < iInput[0]; ++i)
	{
		CIN >> szInput[0] >> szInput[1];
		setPassWord[szInput[0]] = szInput[1];
	}

	for (int i = 0; i < iInput[1]; ++i)
	{
		CIN >> szInput[0];
		cout << setPassWord[szInput[0]] << '\n';
	}

}