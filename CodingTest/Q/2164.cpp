#pragma once
#include "pch.h"
#include "Header.h"
#include <queue>

void Solve(ifstream* _pLoadStream)
{
	���������ȭ;
	/*
	n�� ī�并ġ��
	�����
	�� �Ʒ��� �����°� �ݺ�
	������ ���� ī�带 ��ȯ
	*/

	/* �������� Ǯ��
	input ���� �۰� ���� ū ������ ���� ...(i
	(input - i) * 2 = ����
	*/
	int iInput;
	*_pLoadStream >> iInput;
	if (iInput == 1)
	{
		cout << 1 << endl;
		return;
	}

	queue<int> queueNums;
	for (int i = 1; i <= iInput; ++i)
	{
		queueNums.push(i);
	}

	while(queueNums.size() != 1)
	{
		queueNums.pop();
		queueNums.push(queueNums.front());
		queueNums.pop();
	}
	cout << queueNums.front() << endl;


}