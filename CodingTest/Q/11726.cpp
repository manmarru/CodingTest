#include "pch.h"
#include "Header.h"
#include <vector>

void Solve(ifstream* _pLoadStream)
{
	/*
	2*n ũ���� ���簢���� ä��� ����� ���� 10007�� ���� �������� ���

	���η� � ���η� � �ִ��� ���� ������, input�� Ȧ���� ���ΰ� Ȧ������ ��
	�Ǻ���ġ�����̳�!
	*/

	int iInput;
	CIN >> iInput;
	if (1 == iInput)
	{
		cout << 1;
		return;
	}
	else if (2 == iInput)
	{
		cout << 2;
		return;
	}
	vector<long long int> vecDP;
	vecDP.resize(iInput);
	vecDP[0] = 1;
	vecDP[1] = 2;

	for (int i = 2; i < iInput; ++i)
		vecDP[i] = vecDP[i - 1] + vecDP[i - 2];

	cout << vecDP[iInput - 1] % 10007;
}