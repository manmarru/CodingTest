#include "pch.h"
#include "Header.h"

void Solve(ifstream* _pLoadStream)
{
	/*
	������ �׼� ����ϱ�
	*/

	int Price, Need, Own;
	CIN >> Price >> Need >> Own;
	cout << max(0, Price * Need - Own);
}