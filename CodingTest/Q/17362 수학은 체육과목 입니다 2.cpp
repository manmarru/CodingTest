#include "pch.h"
#include "Header.h"

void Solve(ifstream* _pLoadStream)
{
	/*
	1	2	3	4	5
	9	8	7	6 
		10	11	12	13
	17	16	15	14 �̷������� �̾����� �հ��� �� ����
	���� ���ڴ� ��� �հ������� ��������
	*/

	int Input;
	int Board[8] = { 2, 1, 2, 3, 4, 5, 4, 3 };
	cin >> Input;

	Input %= 8;
	cout << Board[Input];

	return;
}