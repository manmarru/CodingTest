#include "pch.h"
#include "Header.h"
#include <vector>

void Solve(ifstream* pLoadStream)
{
	/*
	add : �߰� (�̹� ������ ����
	remove : ���� (������ ����
	check : ������ 1 ������ 0 ���
	toggle : ������ ���� ������ �߰�
	all : ������ 1,2,3,4,5,....20 ���� ��ü
	empty : ���� ����
	*/

	int iInput{};
	CIN >> iInput;

	string szInput;
	int iOption;
	vector<bool> vecSet;
	vecSet.resize(20);
	for (int i = 0; i < 20; ++i)
	{
		vecSet[i] = false;
	}

	for (int i = 0; i < iInput; ++i)
	{
		CIN >> szInput;

		if ("all" == szInput)
		{
			for (int j = 0; j < 20; ++j)
				vecSet[j] = true;
			continue;
		}
		else if ("empty" == szInput)
		{
			for (int j = 0; j < 20; ++j)
				vecSet[j] = false;
			continue;
		}

		CIN >> iOption;
		--iOption;
		if ("add" == szInput)
		{
			vecSet[iOption] = true;
		}
		else if ("remove" == szInput)
		{
			vecSet[iOption] = false;
		}
		else if ("check" == szInput)
		{
			cout << vecSet[iOption] << '\n';
		}
		else if ("toggle" == szInput)
		{
			vecSet[iOption] = !vecSet[iOption];
		}
		

	}
}