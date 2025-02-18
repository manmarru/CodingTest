#pragma once
#include "pch.h"
#include "1920.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);




	ifstream LoadStream("../Data/Input.txt");

	Solve(&LoadStream);

	LoadStream.close();




	return 0;
}