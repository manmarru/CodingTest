#include "pch.h"
#include "Header.h"
#include <list>
#include <string>

void Solve(ifstream* _pLoadStream)
{
	/*
	666�� �� n��°�� ���� ���� ���
	���Ʈ ����
	*/
	int iSize{};
	string Temp;
	string Src;
	string szZero;
	CIN >> iSize;
	int iLength = (int)to_string(iSize).size();
	list<int> listNums;
//001�����͵� �����ؾ� �ȴ�. �ڸ��� �������� �ϸ� �ɵ�
	for (int i = 0; i < iSize; ++i)
	{
		Temp = to_string(i);
		szZero = string(iLength - (int)Temp.size(), '0');

		for (int j = 0; j <= iLength; ++j)
		{
			Src = szZero + Temp;
			Src.insert(j, "666");
			listNums.push_back(stoi(Src));
		}
	}

	listNums.sort();
	listNums.unique();

	list<int>::iterator iter = listNums.begin();
	for (int i = 1; i < iSize; ++i)
	{
		++iter;
	}

	cout << *iter;
}