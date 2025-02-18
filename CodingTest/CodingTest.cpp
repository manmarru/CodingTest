#pragma once
#include "pch.h"
#include "Header.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(NULL);



	ifstream LoadStream("../Data/Input.txt");

	Solve(&LoadStream);

	LoadStream.close();




	return 0;
}